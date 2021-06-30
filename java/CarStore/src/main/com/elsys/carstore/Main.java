package main.com.elsys.carstore;

import java.util.Collection;
import java.util.Comparator;

public class Main {

    public static class CustomComparator implements Comparator<Car> {
        public int compare(Car car1, Car car2) {
            return Integer.compare(car1.getPrice(), car2.getPrice());
        }
    }

    public static void main(String[] args) {
        Collection<Car> cars;
	    CarStore carStore = new CarStore();
        Car one = new OrdinaryCar(
                Model.AUDI,
                2006,
                5000,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                2003,
                300,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                2001,
                8000,
                EngineType.GASOLINE,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        cars = carStore.getCars();
        for(Car car : cars){
            System.out.println("Model: " + car.getModel() + " Year: " +car.getYear() + " Price: " +
                    car.getPrice() + " Engine: " + car.getEngineType() +
                    " RegistrationNumber: " + car.getRegistrationNumber() +
                    " Region: " + car.getRegion());
        }

        System.out.println("");

        cars = carStore.getCarsByModel(Model.AUDI);
        for(Car car : cars){
            System.out.println("Model: " + car.getModel() + " Year: " +car.getYear() + " Price: " +
                    car.getPrice() + " Engine: " + car.getEngineType() +
                    " RegistrationNumber: " + car.getRegistrationNumber() +
                    " Region: " + car.getRegion());
        }

        System.out.println("");

        cars = carStore.getCars(new CustomComparator());
        for(Car car : cars){
            System.out.println("Model: " + car.getModel() + " Year: " +car.getYear() + " Price: " +
                    car.getPrice() + " Engine: " + car.getEngineType() +
                    " RegistrationNumber: " + car.getRegistrationNumber() +
                    " Region: " + car.getRegion());
        }

        System.out.println("");

        cars = carStore.getCars(new CustomComparator(), true);
        for(Car car : cars){
            System.out.println("Model: " + car.getModel() + " Year: " +car.getYear() + " Price: " +
                    car.getPrice() + " Engine: " + car.getEngineType() +
                    " RegistrationNumber: " + car.getRegistrationNumber() +
                    " Region: " + car.getRegion());
        }

        System.out.println("");

        System.out.println("Total cars: " + carStore.getNumberOfCars());
        System.out.println("Total price: " + carStore.getTotalPriceOfCars());
    }
}
