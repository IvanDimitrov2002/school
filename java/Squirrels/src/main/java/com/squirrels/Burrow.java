package main.java.com.squirrels;

import java.util.ArrayList;
import java.util.List;

public class Burrow {
    private List<Food> food = new ArrayList<Food>();

    public Burrow(List<Food> food) {
        this.food = food;
    }

    public Burrow(){}

    public void addFood(Food food){
        this.food.add(food);
    }

    public void passWinter() {
        for(Food food : this.food){
            food.passWinter();
        }
    }

    public String getInfo(){
        String info = "";
        for(Food food : this.food){
            info += (food.getClass().getSimpleName() + " " + String.format("%.2f", food.getQuantity()) + " " +
                    String.format("%.2f", food.getQuality())  + "\n");
        }
        return info;
    }

    public Double getTotalFoodScore(){
        Double totalFoodScore = 0.0;
        for(Food food : this.food){
            totalFoodScore += food.getFoodScore();
        }
        return totalFoodScore;
    }

    public List<Food> getFood() {
        return food;
    }

    public void setFood(List<Food> food) {
        this.food = food;
    }
}
