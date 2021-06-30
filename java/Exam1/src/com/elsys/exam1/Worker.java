package com.elsys.exam1;

import java.util.List;

public class Worker extends BaseUnit {
    private Integer currQuantity = 0;
    private Integer totalQuantity = 0;
    private Integer maxQuantity;
    private Resource resource;
    private Position deliveryPosition;

    public Worker(String name, Integer speed, Position position, Integer currHealth, Integer maxHealth, Integer maxQuantity, Resource resource, Position deliveryPosition) {
        super(name, speed, position, currHealth, maxHealth);
        this.maxQuantity = maxQuantity;
        this.resource = resource;
        this.deliveryPosition = deliveryPosition;
    }

    public Worker(String name, Integer speed, Position position, Integer currHealth, Integer maxHealth, Integer currQuantity, Integer maxQuantity, Resource resource, Position deliveryPosition) {
        super(name, speed, position, currHealth, maxHealth);
        this.currQuantity = currQuantity;
        this.maxQuantity = maxQuantity;
        this.resource = resource;
        this.deliveryPosition = deliveryPosition;
    }

    public Worker(){};

    void findNewResource(List<Resource> resources){
        if(resource.getQuantity() == 0){
            Integer minDistance = resources.get(0).getPosition().getSum();
            for(Resource currResource : resources){
                if(currResource.getPosition().getSum() < minDistance){
                    minDistance = currResource.getPosition().getSum();
                    resource = currResource;
                }
            }
        }
    }

    @Override
    public void nextTick() {
        if(currQuantity == 0){
            if(resource.getQuantity() < maxQuantity){
                currQuantity = resource.getQuantity();
                System.out.println("Resource quantity drained out!");
                resource.setQuantity(0);
            } else {
                currQuantity = maxQuantity;
                System.out.println("Worker got " + maxQuantity + " from the resource!");
                resource.setQuantity(resource.getQuantity() - maxQuantity);
            }
        } else {
            move();
            if(currPosition.getX() == deliveryPosition.getX() && currPosition.getY() == deliveryPosition.getY()){
                totalQuantity += currQuantity;
                currQuantity = 0;
            }
        }
    }

    @Override
    public void move() {
        if(currPosition.getX() == deliveryPosition.getX()){
            if(currPosition.getY() + speed > deliveryPosition.getY()){
                currPosition.setY(deliveryPosition.getY());
                System.out.println("Worker " + name + "  reached Y coordinate of the delivery position!");
            } else {
                currPosition.setY(currPosition.getY() + speed);
                System.out.println("Worker " + name + " moved " + speed + " times to Y coordinate of the delivery position!");
            }
        } else {
            if(currPosition.getX() + speed > deliveryPosition.getX()){
                currPosition.setX(deliveryPosition.getX());
                System.out.println("Worker " + name + "  reached X coordinate of the delivery position!");
            } else {
                currPosition.setX(currPosition.getX() + speed);
                System.out.println("Worker " + name + " moved " + speed + " times to X coordinate of the delivery position!");
            }
        }
    }

    public Integer getCurrQuantity() {
        return currQuantity;
    }

    public void setCurrQuantity(Integer currQuantity) {
        this.currQuantity = currQuantity;
    }

    public Integer getMaxQuantity() {
        return maxQuantity;
    }

    public void setMaxQuantity(Integer maxQuantity) {
        this.maxQuantity = maxQuantity;
    }

    public Resource getResource() {
        return resource;
    }

    public void setResource(Resource resource) {
        this.resource = resource;
    }

    public Position getDeliveryPosition() {
        return deliveryPosition;
    }

    public void setDeliveryPosition(Position deliveryPosition) {
        this.deliveryPosition = deliveryPosition;
    }

    public Integer getTotalQuantity() {
        return totalQuantity;
    }

    public void setTotalQuantity(Integer totalQuantity) {
        this.totalQuantity = totalQuantity;
    }
}
