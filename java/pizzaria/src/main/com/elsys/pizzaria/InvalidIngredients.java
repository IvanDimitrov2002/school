package main.com.elsys.pizzaria;

public class InvalidIngredients extends Exception {
    public InvalidIngredients() {
        super("There are no such ingredients in the pizzeria.");
    }
}
