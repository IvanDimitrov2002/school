package main.java.com.squirrels;

public class FoodGetterLimitExceeded extends Exception{
    public FoodGetterLimitExceeded(){
        super("The squirrel went for food enough times this year!");
    }
}
