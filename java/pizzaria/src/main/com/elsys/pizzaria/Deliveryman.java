package main.com.elsys.pizzaria;

public class Deliveryman implements Runnable {
    private String fullName;
    private Pizzeria pizzeria;
    private Boolean isOccupied = false;

    public Deliveryman(String fullName, Pizzeria pizzeria) {
        this.fullName = fullName;
        this.pizzeria = pizzeria;
    }

    private Boolean availableForDelivery(){
        for(Pizza pizza : pizzeria.getPizzas()){
            if(pizza.getStatus() != PizzaStatus.DELIVERED){
                return true;
            }
        }
        return false;
    }

    @Override
    public void run(){
        while(availableForDelivery()){
            for(Pizza pizza : pizzeria.getPizzas()){
                pizza.changeStatus(PizzaStatus.DELIVERING, PizzaStatus.DELIVERED);
            }
        }
        isOccupied = false;
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public synchronized Boolean getOccupied() {
        return isOccupied;
    }

    public synchronized void setOccupied(Boolean occupied) {
        isOccupied = occupied;
    }
}
