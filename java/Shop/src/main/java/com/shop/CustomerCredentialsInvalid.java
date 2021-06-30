package main.java.com.shop;

public class CustomerCredentialsInvalid extends Exception {
    public CustomerCredentialsInvalid(String message) {
        super(message + " for this customer is invalid");
    }
}
