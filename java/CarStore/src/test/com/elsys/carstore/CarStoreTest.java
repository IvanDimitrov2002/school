package test.com.elsys.carstore;

import main.com.elsys.carstore.*;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.*;


class CarStoreTest {
    public static class CustomComparator implements Comparator<Car> {
        public int compare(Car car1, Car car2) {
            return Integer.compare(car1.getPrice(), car2.getPrice());
        }
    }

    private static final int CAR_NEW_YEAR = 2006;
    private static final int CAR_MID_YEAR = 2003;
    private static final int CAR_OLD_YEAR = 2001;

    private static final int CHEAP_CAR_PRICE = 300;
    private static final int EXPENSIVE_CAR_PRICE = 5000;
    private static final int VERY_EXPENSIVE_CAR_PRICE = 8000;

    private CarStore carStore;

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        carStore = new CarStore();
    }

    @Test
    void add() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_NEW_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_MID_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        boolean check = carStore.add(one);
        carStore.add(two);
        Car[] carsArray = carStore.getCars().toArray(new Car[carStore.getCars().size()]);
        assertTrue(check);
        assertEquals(one, carsArray[0]);
        assertEquals(two, carsArray[1]);
    }

    @org.junit.jupiter.api.Test
    void addAll() {
        Collection<Car> cars = new ArrayList<Car>();

        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_NEW_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_MID_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        cars.add(one);
        cars.add(two);

        carStore.addAll(cars);
        Car[] expected = carStore.getCars().toArray(new Car[carStore.getCars().size()]);
        Car[] actual = cars.toArray(new Car[cars.size()]);

        assertArrayEquals(expected, actual);
    }

    @org.junit.jupiter.api.Test
    void remove() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_NEW_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );

        carStore.add(one);
        boolean check = carStore.remove(one);
        assertTrue(check);
    }

    @org.junit.jupiter.api.Test
    void getCarByRegistrationNumber() throws CarNotFoundException {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_NEW_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_MID_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.GASOLINE,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        Collection<Car> cars = carStore.getCars();
        Car[] carsArray = cars.toArray(new Car[cars.size()]);

        String expected = carsArray[0].getRegistrationNumber();
        String actual = carStore.getCarByRegistrationNumber(expected).getRegistrationNumber();
        assertEquals(expected, actual);

        assertThrows(CarNotFoundException.class, () -> {
            carStore.getCarByRegistrationNumber("test");
        });
    }

    @org.junit.jupiter.api.Test
    void getCarsByModel() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_NEW_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_MID_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.GASOLINE,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        Collection<Car> cars = carStore.getCarsByModel(Model.AUDI);

        Car[] expected = { three, one };
        Car[] actual = cars.toArray(new Car[cars.size()]);
        assertArrayEquals(expected, actual);
    }

    @org.junit.jupiter.api.Test
    void getCars() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_MID_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_NEW_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        Collection<Car> cars = carStore.getCars();
        Car[] carsArray = cars.toArray(new Car[cars.size()]);

        assertEquals(three, carsArray[0]);
        assertEquals(one, carsArray[1]);
        assertEquals(two, carsArray[2]);
    }

    @org.junit.jupiter.api.Test
    void getCarsWithCustomComparatorAndBoolean() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_MID_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_NEW_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);
        Collection<Car> cars = carStore.getCars(
                new CustomComparator(),
                false
        );

        Car[] expected = { three, one, two };
        Car[] actual = cars.toArray(new Car[cars.size()]);
        assertArrayEquals(expected, actual);

        cars = carStore.getCars(
                new CustomComparator(),
                true
        );

        Car[] expected2 = { two, one, three };
        Car[] actual2 = cars.toArray(new Car[cars.size()]);
        assertArrayEquals(expected2, actual2);
    }

    @org.junit.jupiter.api.Test
    void getNumberOfCars() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_MID_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_NEW_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        assertEquals(3, carStore.getNumberOfCars());
    }

    @org.junit.jupiter.api.Test
    void getTotalPriceOfCars() {
        Car one = new OrdinaryCar(
                Model.AUDI,
                CAR_MID_YEAR,
                EXPENSIVE_CAR_PRICE,
                EngineType.DIESEL,
                Region.BURGAS
        );
        Car two = new OrdinaryCar(
                Model.BMW,
                CAR_NEW_YEAR,
                VERY_EXPENSIVE_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        Car three = new OrdinaryCar(
                Model.AUDI,
                CAR_OLD_YEAR,
                CHEAP_CAR_PRICE,
                EngineType.ELECTRIC,
                Region.BURGAS
        );

        carStore.add(one);
        carStore.add(two);
        carStore.add(three);

        assertEquals(13300, carStore.getTotalPriceOfCars());
    }
}