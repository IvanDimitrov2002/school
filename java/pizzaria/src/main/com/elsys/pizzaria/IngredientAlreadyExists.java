package main.com.elsys.pizzaria;

public class IngredientAlreadyExists extends Exception {
    public IngredientAlreadyExists() {
        super("Error: The ingredient already exists!");
    }
}
