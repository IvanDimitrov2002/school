package main.com.elsys.pizzaria;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import static java.lang.Thread.sleep;

public class Pizza implements Runnable {
    private Integer orderId;
    private PizzaStatus status = PizzaStatus.MAKING;
    private ArrayList<Ingredient> ingredients = new ArrayList<Ingredient>();

    public Pizza(Integer orderId, ArrayList<Ingredient> ingredients) {
        this.orderId = orderId;
        this.ingredients = ingredients;
    }

    @Override
    public void run() {
        double bakeTime = 0;
        Map<IngredientType, Boolean> ingredientsOccurances = new HashMap<>();
        for(Ingredient ingredient : ingredients){
            Boolean hasIngredient = true;
            if(ingredientsOccurances.get(ingredient.getIngredientType()) == null){
                hasIngredient = false;
            }
            if(hasIngredient){
                bakeTime += ingredient.getTime() * 0.1;
            } else {
                ingredientsOccurances.put(ingredient.getIngredientType(), true);
                bakeTime += ingredient.getTime();
            }
        }
        try {
            sleep((long) bakeTime * 1000);
            status = PizzaStatus.DELIVERING;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public ArrayList<Ingredient> getIngredients() {
        return ingredients;
    }

    public void setIngredients(ArrayList<Ingredient> ingredients) {
        this.ingredients = ingredients;
    }

    public synchronized PizzaStatus getStatus() {
        return status;
    }

    public synchronized void setStatus(PizzaStatus status) {
        this.status = status;
    }

    public synchronized Boolean changeStatus(PizzaStatus currStatus, PizzaStatus newStatus) {
        if(currStatus != status){
            return false;
        }
        status = newStatus;
        return true;
    }

    public Integer getOrderId() {
        return orderId;
    }

    public void setOrderId(Integer orderId) {
        this.orderId = orderId;
    }
}
