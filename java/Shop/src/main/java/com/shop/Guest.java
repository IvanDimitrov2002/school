package main.java.com.shop;

public class Guest extends Customer {
    public Guest(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
    }

    public Guest() {
        super();
    }
}
