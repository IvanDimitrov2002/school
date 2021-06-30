package main.com.elsys.carstore;

import java.util.Random;

public class SportsCar extends Car {

    public SportsCar(Model model, int year, int price, EngineType engineType, Region region){
        Random rnd = new Random();
        this.model = model;
        this.year = year;
        this.price = price;
        this.engineType = engineType;
        this.region = region;
        this.registrationNumber = (Region.getPrefix(region) + Car.getNumber(region) + (char)(rnd.nextInt(26) + 'A')
                                   + (char)(rnd.nextInt(26) + 'A'));

    }
}
