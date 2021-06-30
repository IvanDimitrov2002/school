package test.com.elsys.pizzaria;

import main.com.elsys.pizzaria.Deliveryman;
import main.com.elsys.pizzaria.Pizzeria;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DeliverymanTest {
    Deliveryman deliveryman;

    @BeforeEach
    void setUp() {
        deliveryman = new Deliveryman("Ivan Dimitrov", new Pizzeria());
    }

    @Test
    void getFullName() {
        assertEquals("Ivan Dimitrov", deliveryman.getFullName());
    }

    @Test
    void setFullName() {
        deliveryman.setFullName("Pancake Man");
        assertEquals("Pancake Man", deliveryman.getFullName());
    }

    @Test
    void getOccupied() {
        assertEquals(false, deliveryman.getOccupied());
    }

    @Test
    void setOccupied() {
        deliveryman.setOccupied(true);
        assertEquals(true, deliveryman.getOccupied());
    }
}