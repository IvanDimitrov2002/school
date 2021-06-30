package main.java.com.shop;

public class RegisteredCustomer extends Customer {
    public RegisteredCustomer(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
    }

    @Override
    public int hashCode() {
        return id;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof RegisteredCustomer) {
            if(((RegisteredCustomer) obj).getId() == id) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
