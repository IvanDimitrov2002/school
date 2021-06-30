package main.com.elsys.pizzaria;

public class InvalidPizzaDough extends Exception {
    public InvalidPizzaDough() {
        super("You must select exactly one type of dough!");
    }
}
