package main.java.com.shop;

public class OrderDoesNotExists extends Exception{
    public OrderDoesNotExists(){
        super("Order does not exist!");
    }
}
