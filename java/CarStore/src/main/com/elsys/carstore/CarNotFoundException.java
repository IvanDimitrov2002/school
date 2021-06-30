package main.com.elsys.carstore;

public class CarNotFoundException extends Exception {
    public CarNotFoundException(){
        super("Car not found!");
    }
}
