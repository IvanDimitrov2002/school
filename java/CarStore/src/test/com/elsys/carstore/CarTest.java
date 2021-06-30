package test.com.elsys.carstore;

import main.com.elsys.carstore.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CarTest {
    Car car;

    @BeforeEach
    void setUp() {
        car = new OrdinaryCar(
                Model.AUDI,
                2003,
                5000,
                EngineType.DIESEL,
                Region.BURGAS
        );
    }

    @Test
    void compareTo() {
        Car car2 = new OrdinaryCar(
                Model.BMW,
                2005,
                10000,
                EngineType.ELECTRIC,
                Region.BURGAS
        );
        assertEquals(-1, car.compareTo(car2));
        assertEquals(1, car2.compareTo(car));
        assertEquals(0, car.compareTo(car));
    }

    @Test
    void getNumber() {
        assertEquals(1000, Car.getNumber(Region.SOFIA));
    }

    @Test
    void getModel() {
        assertEquals(Model.AUDI, car.getModel());
    }

    @Test
    void getYear() {
        assertEquals(2003, car.getYear());
    }

    @Test
    void getPrice() {
        assertEquals(5000, car.getPrice());
    }

    @Test
    void getEngineType() {
        assertEquals(EngineType.DIESEL, car.getEngineType());
    }

    @Test
    void getRegion() {
        assertEquals(Region.BURGAS, car.getRegion());
    }

    @Test
    void setModel() {
        car.setModel(Model.BMW);
        assertEquals(Model.BMW, car.getModel());
    }

    @Test
    void setYear() {
        car.setYear(2005);
        assertEquals(2005, car.getYear());
    }

    @Test
    void setPrice() {
        car.setPrice(6000);
        assertEquals(6000, car.getPrice());
    }

    @Test
    void setEngineType() {
        car.setEngineType(EngineType.GASOLINE);
        assertEquals(EngineType.GASOLINE, car.getEngineType());
    }

    @Test
    void setRegistrationNumber() {
        car.setRegistrationNumber("CB1234AA");
        assertEquals("CB1234AA", car.getRegistrationNumber());
    }

    @Test
    void setRegion() {
        car.setRegion(Region.PLOVDIV);
        assertEquals(Region.PLOVDIV, car.getRegion());
    }
}