package main.java.com.shop;

public class CartIsEmpty extends Exception {
    public CartIsEmpty(){
        super("The cart is empty!");
    }
}
