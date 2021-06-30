package main.java.com.shop;

public class ProductQuantityInvalid extends Exception {
    public ProductQuantityInvalid() {
        super("Product quantity not enough!");
    }
}
