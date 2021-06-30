package main.java.com.shop;

public abstract class Customer {
    protected Integer id;
    protected String firstName;
    protected String lastName;
    protected Address address;
    static protected Integer customerCount = 0;

    public Customer(String firstName, String lastName, Address address) {
        this.id = customerCount++;
        this.firstName = firstName;
        this.lastName = lastName;
        this.address = address;
    }

    public Customer() {
        this.id = customerCount++;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public static Integer getCustomerCount() {
        return customerCount;
    }

    public static void setCustomerCount(Integer customerCount) {
        Customer.customerCount = customerCount;
    }
}
