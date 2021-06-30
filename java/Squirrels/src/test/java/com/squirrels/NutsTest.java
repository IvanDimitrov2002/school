package test.java.com.squirrels;

import main.java.com.squirrels.Food;
import main.java.com.squirrels.Nuts;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NutsTest {
    Nuts nut;

    @BeforeEach
    void setUp() {
        nut = new Nuts(20.0, 10.0);
    }

    @Test
    void getFoodScore() {
        assertEquals(nut.getFoodScore(), 200);
    }

    @Test
    void getQuality() {
        assertEquals(nut.getQuality(), 10);
    }

    @Test
    void setQuality() {
        nut.setQuality(30.0);
        assertEquals(nut.getQuality(), 30.0);;
    }

    @Test
    void getQuantity() {
        assertEquals(nut.getQuantity(), 20);
    }

    @Test
    void setQuantity() {
        nut.setQuantity(40.0);
        assertEquals(nut.getQuantity(), 40.0);
    }
}