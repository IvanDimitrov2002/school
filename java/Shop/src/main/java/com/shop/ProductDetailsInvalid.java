package main.java.com.shop;

public class ProductDetailsInvalid extends  Exception {
    public ProductDetailsInvalid(String message) {
        super(message + " for this product is invalid");
    }
}
