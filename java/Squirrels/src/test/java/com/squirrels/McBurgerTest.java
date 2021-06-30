package test.java.com.squirrels;

import main.java.com.squirrels.McBurger;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class McBurgerTest {
    McBurger mcburger;

    @BeforeEach
    void setUp() {
        mcburger = new McBurger(20.0, 30.0);
    }

    @Test
    void getFoodScore() {
        assertEquals(mcburger.getFoodScore(), 600);
    }

    @Test
    void getQuality() {
        assertEquals(mcburger.getQuality(), 30);
    }

    @Test
    void setQuality() {
        mcburger.setQuality(20.0);
        assertEquals(mcburger.getQuality(), 20);
    }

    @Test
    void getQuantity() {
        assertEquals(mcburger.getQuantity(), 20);
    }

    @Test
    void setQuantity() {
        mcburger.setQuantity(30.0);
        assertEquals(mcburger.getQuantity(), 30);
    }

    @Test
    void passWinter() {
        assertEquals(mcburger.getPassedWinter(), false);
        mcburger.passWinter();
        assertEquals(mcburger.getQuantity(), 16);
        assertEquals(mcburger.getQuality(), 15);
        assertEquals(mcburger.getPassedWinter(), true);
    }
}