package test.java.com.squirrels;

import main.java.com.squirrels.Cake;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CakeTest {
    Cake cake;

    @BeforeEach
    void setUp() {
        cake = new Cake(40.0, 50.0);
    }

    @Test
    void getFoodScore() {
        assertEquals(cake.getFoodScore(), 2000);
    }

    @Test
    void getQuality() {
        assertEquals(cake.getQuality(), 50);
    }

    @Test
    void setQuality() {
        cake.setQuality(20.0);
        assertEquals(cake.getQuality(), 20.0);
    }

    @Test
    void getQuantity() {
        assertEquals(cake.getQuantity(), 40);
    }

    @Test
    void setQuantity() {
        cake.setQuantity(30.0);
        assertEquals(cake.getQuantity(), 30.0);
    }

    @Test
    void passWinter() {
        cake.passWinter();
        assertEquals(cake.getAge(), 1);
        assertEquals(cake.getQuantity(), 28);
        assertEquals(cake.getQuality(), 49.02, 0.01);
    }

    @Test
    void getAge() {
        assertEquals(cake.getAge(), 0);
    }

    @Test
    void setAge() {
        cake.setAge(1);
        assertEquals(cake.getAge(), 1);
    }
}