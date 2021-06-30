package main.com.elsys.pizzaria;

import java.util.ArrayList;
import java.util.concurrent.CopyOnWriteArrayList;

public class Pizzeria {
    private CopyOnWriteArrayList<Pizza> pizzas = new CopyOnWriteArrayList<Pizza>();
    private ArrayList<Pizzaman> pizzamen = new ArrayList<Pizzaman>();
    private ArrayList<Ingredient> ingredients = new ArrayList<Ingredient>();
    private ArrayList<Stove> stoves = new ArrayList<Stove>();
    private ArrayList<Deliveryman> deliverymen = new ArrayList<Deliveryman>();

    public CopyOnWriteArrayList<Pizza> getPizzas() {
        return pizzas;
    }

    public void setPizzas(CopyOnWriteArrayList<Pizza> pizzas) {
        this.pizzas = pizzas;
    }

    public ArrayList<Pizzaman> getPizzamen() {
        return pizzamen;
    }

    public void setPizzamen(ArrayList<Pizzaman> pizzamen) {
        this.pizzamen = pizzamen;
    }

    public ArrayList<Ingredient> getIngredients() {
        return ingredients;
    }

    public void setIngredients(ArrayList<Ingredient> ingredients) {
        this.ingredients = ingredients;
    }

    public ArrayList<Stove> getStoves() {
        return stoves;
    }

    public void setStoves(ArrayList<Stove> stoves) {
        this.stoves = stoves;
    }

    public ArrayList<Deliveryman> getDeliverymen() {
        return deliverymen;
    }

    public void setDeliverymen(ArrayList<Deliveryman> deliverymen) {
        this.deliverymen = deliverymen;
    }
}
