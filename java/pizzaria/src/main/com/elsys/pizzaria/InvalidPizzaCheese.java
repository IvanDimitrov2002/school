package main.com.elsys.pizzaria;

public class InvalidPizzaCheese extends Exception {
    public InvalidPizzaCheese() {
        super("You must select minimum 1 type of cheese!");
    }
}

