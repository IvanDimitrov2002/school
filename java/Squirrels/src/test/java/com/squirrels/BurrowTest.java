package test.java.com.squirrels;

import main.java.com.squirrels.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BurrowTest {
    Burrow burrow;

    @BeforeEach
    void setUp() {
        List<Food> food = new ArrayList<Food>();
        food.add(new Nuts(10.0, 10.0));
        food.add(new Cake(40.0, 50.0));
        food.add(new McBurger(20.0, 30.0));
        burrow = new Burrow(food);
    }

    @Test
    void addFood() {
        Nuts nuts = new Nuts(20.0, 20.0);
        burrow.getFood().add(nuts);
        assertEquals(burrow.getFood().get(3), nuts);
    }

    @Test
    void passWinter() {
        burrow.passWinter();
        List<Food> food = burrow.getFood();
        assertEquals(food.get(0).getQuantity(), 10);
        assertEquals(food.get(0).getQuality(), 10);
        assertEquals(food.get(1).getQuantity(), 28);
        assertEquals(food.get(1).getQuality(), 49.02, 0.01);
        assertEquals(food.get(2).getQuantity(), 16);
        assertEquals(food.get(2).getQuality(), 15);
    }

    @Test
    void getInfo() {
        assertEquals(burrow.getInfo(), "Nuts 10.00 10.00\n" +
                                            "Cake 40.00 50.00\n" +
                                            "McBurger 20.00 30.00\n");
    }

    @Test
    void getTotalFoodScore() {
        assertEquals(burrow.getTotalFoodScore(), 2700);
    }
}