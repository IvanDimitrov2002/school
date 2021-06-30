package main.com.elsys.microbiology;

import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.concurrent.CopyOnWriteArrayList;

import static java.lang.Thread.currentThread;
import static java.lang.Thread.sleep;

public class Paramecium implements Runnable {
    private Point position;
    private Integer rate;
    private Integer speed;
    private CopyOnWriteArrayList<Object> terrain;

    public Paramecium(Point position, Integer rate, Integer speed, CopyOnWriteArrayList<Object> terrain) {
        this.position = position;
        this.rate = rate;
        this.speed = speed;
        this.terrain = terrain;
    }

    @Override
    public void run() {
        while(true){
            Optional<Object> closestFood = terrain.stream().filter(o -> o instanceof Food).min(new Comparator<Object>() {
                @Override
                public int compare(Object o1, Object o2) {
                    return Double.compare(((Food) o1).getPosition().distanceTo(position), ((Food) o2).getPosition().distanceTo(position));
                }
            });

            Food food;

            try {
                food = (Food) closestFood.get();
            } catch (NoSuchElementException e){
                break;
            }

            System.out.println(currentThread().getId() + " " + food);

            if(position.distanceTo(food.getPosition()) == 0){
                System.out.println(currentThread().getId() + " eating food.");
                if(food.getQuantity() - rate <= 0){
                    terrain.remove(food);
                } else {
                    food.setQuantity(food.getQuantity() - rate);
                }
            } else {
                System.out.println(currentThread().getId() + " going to food.");
                if(position.getX() < food.getPosition().getX()) {
                    if(position.getX() + speed > food.getPosition().getX()){
                        position.setX(food.getPosition().getX());
                    } else {
                        position.setX(position.getX() + speed);
                    }
                } else if(position.getX() > food.getPosition().getX()) {
                    if(position.getX() - speed < food.getPosition().getX()){
                        position.setX(food.getPosition().getX());
                    } else {
                        position.setX(position.getX() - speed);
                    }
                }

                if(position.getY() < food.getPosition().getY()) {
                    if(position.getY() + speed > food.getPosition().getY()){
                        position.setY(food.getPosition().getY());
                    } else {
                        position.setY(position.getY() + speed);
                    }
                } else if(position.getY() > food.getPosition().getY()) {
                    if(position.getY() - speed < food.getPosition().getY()){
                        position.setY(food.getPosition().getY());
                    } else {
                        position.setY(position.getY() - speed);
                    }
                }
            }


            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }

    public Integer getSpeed() {
        return speed;
    }

    public void setSpeed(Integer speed) {
        this.speed = speed;
    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }
}
