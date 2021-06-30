package main.com.elsys.carstore;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;

public class CarStore {
    private ArrayList<Car> cars = new ArrayList<Car>();


    /**
     * Adds the specified car in the store.
     * @return true if the car was added successfully to the store
     */
    public boolean add(Car car) {
        try{
            cars.add(car);
            return true;
        } catch (Exception e){
            return false;
        }
    }

    /**
     * Adds all of the elements of the specified collection in the store.
     * @return true if the store cars are changed after the execution
     * (i.e. at least one new car is added to the store)
     */
    public boolean addAll(Collection<Car> cars) {
        ArrayList<Car> newCars = new ArrayList<Car>(cars);
        boolean status = false;
        for (Car newCar : newCars) {
            try {
                this.cars.add(newCar);
                status = true;
            } catch (Exception ignored) {

            }
        }
        return status;
    }

    /**
     * Removes the specified car from the store.
     * @return true if the car is successfully removed from the store
     */
    public boolean remove(Car car) {
        try{
            cars.remove(car);
            return true;
        } catch (Exception e){
            return false;
        }
    }

    /**
     * Finds a car from the store by its registration number.
     * @throws CarNotFoundException if a car with this
     * registration number is not found in the store
     **/
    public Car getCarByRegistrationNumber(String registrationNumber) throws CarNotFoundException {
        for (Car car : this.cars) {
            if(registrationNumber == car.getRegistrationNumber()){
                return car;
            }
        }
        throw new CarNotFoundException();
    }

    /**
     * Returns all cars of a given model.
     * The cars need to be sorted by year of manufacture (in ascending order).
     */
    public Collection<Car> getCarsByModel(Model model) {
        ArrayList<Car> modelCars = new ArrayList<Car>();
        for (Car car : this.cars) {
            if (car.getModel() == model) {
                modelCars.add(car);
            }
        }
        modelCars.sort(new Comparator<Car>(){
            public int compare(Car car1, Car car2){
                return Integer.compare(car1.getYear(), car2.getYear());
            }
        });
        return modelCars;
    }

    /**
     * Returns all cars sorted by their natural ordering
     * (according to the implementation of the Comparable<Car> interface).
     **/
    public Collection<Car> getCars() {
        ArrayList<Car> sortedCars = cars;
        sortedCars.sort(new Comparator<Car>(){
            public int compare(Car car1, Car car2){
                return car1.compareTo(car2);
            }
        });
        return sortedCars;
    }

    /**
     * Returns all cars sorted according to the
     * order induced by the specified comparator.
     */
    public Collection<Car> getCars(Comparator<Car> comparator) {
        ArrayList<Car> sortedCars = cars;
        sortedCars.sort(comparator);
        return sortedCars;
    }

    /**
     * Returns all cars sorted according to the
     * given comparator and boolean flag for order.
     * @param isReversed if true, the cars should be returned in reverse order
     */
    public Collection<Car> getCars(Comparator<Car> comparator, boolean isReversed) {
        ArrayList<Car> sortedCars = cars;
        sortedCars.sort(comparator);
        if(isReversed){
            Collections.reverse(sortedCars);
        }
        return sortedCars;
    }

    /**
     * Returns the total number of cars in the store.
     */
    public int getNumberOfCars() {
        return cars.size();
    }

    /**
     * Returns the total price of all cars in the store.
     */
    public int getTotalPriceOfCars() {
        int totalPrice = 0;
        for (Car car : cars) {
            totalPrice += car.getPrice();
        }
        return totalPrice;
    }
}
