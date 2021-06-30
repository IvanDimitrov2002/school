package main.java.com.shop;

public class ProductDoesNotExists extends Exception{
    public ProductDoesNotExists() {
        super("Product does not exist!");
    }
}
