package test.java.com.squirrels;

import main.java.com.squirrels.*;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SquirrelTest {
    Squirrel squirrel;

    @BeforeEach
    void setUp() {
        Burrow burrow = new Burrow();
        burrow.addFood(new Nuts(10.0, 20.0));
        burrow.addFood(new McBurger(10.0, 20.0));
        burrow.addFood(new Cake(10.0, 20.0));
        squirrel = new Squirrel("Bob", 3, "red", burrow);
    }

    @Test
    void addFood() throws FoodGetterLimitExceeded {
        squirrel.addFood(new Nuts(10.0, 10.0));
        assertEquals(squirrel.getWentForFood(), 1);
        squirrel.addFood(new Nuts(10.0, 10.0));
        squirrel.addFood(new Nuts(10.0, 10.0));
        squirrel.addFood(new Nuts(10.0, 10.0));
        assertThrows(FoodGetterLimitExceeded.class, () -> {
            squirrel.addFood(new Nuts(10.0, 10.0));
        });
    }

    @Test
    void passWinter() {
        squirrel.passWinter();
        assertEquals(squirrel.getAge(), 4);
        assertEquals(squirrel.getWentForFood(), 0);
        List<Food> food = squirrel.getBurrow().getFood();
        assertEquals(food.get(0).getQuantity(), 10);
        assertEquals(food.get(0).getQuality(), 20);
        assertEquals(food.get(1).getQuantity(), 8);
        assertEquals(food.get(1).getQuality(), 10);
        assertEquals(food.get(2).getQuantity(), 7);
        assertEquals(food.get(2).getQuality(), 19.60, 0.01);
    }

    @Test
    void getInfo() {
        assertEquals(squirrel.getInfo(), "<red> Bob(3) 600.00\n" +
                                                "Nuts 10.00 20.00\n" +
                                                "McBurger 10.00 20.00\n" +
                                                "Cake 10.00 20.00\n");
    }

    @Test
    void getName() {
        assertEquals(squirrel.getName(), "Bob");
    }

    @Test
    void setName() {
        squirrel.setName("Jo");
        assertEquals(squirrel.getName(), "Jo");
    }

    @Test
    void getType() {
        assertEquals(squirrel.getType(), "red");
    }

    @Test
    void setType() {
        squirrel.setType("brown");
        assertEquals(squirrel.getType(), "brown");
    }

    @Test
    void getAge() {
        assertEquals(squirrel.getAge(), 3);
    }

    @Test
    void setAge() {
        squirrel.setAge(4);
        assertEquals(squirrel.getAge(), 4);
    }

    @Test
    void getBurrow() {
        assertNotNull(squirrel.getBurrow());
    }

    @Test
    void getWentForFood() {
        assertEquals(squirrel.getWentForFood(), 0);
    }

    @Test
    void setWentForFood() {
        squirrel.setWentForFood(1);
        assertEquals(squirrel.getWentForFood(), 1);
    }

    @Test
    void getLimitFoodGettering() {
        assertEquals(squirrel.getLimitFoodGettering(), 4);
    }

    void setLimitFoodGettering() {
        squirrel.setLimitFoodGettering(5);
        assertEquals(squirrel.getLimitFoodGettering(), 5);
    }
}