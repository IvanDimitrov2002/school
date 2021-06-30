package test.java.com.squirrels;

import main.java.com.squirrels.Food;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FoodTest {
    Food food;

    @BeforeEach
    void setUp() {
        food = new Food(10.0, 10.0){
            @Override
            public void passWinter(){};
        };
    }

    @Test
    void getFoodScore() {
        assertEquals(food.getFoodScore(), 100);
    }

    @Test
    void getQuality() {
        assertEquals(food.getQuality(), 10);
    }

    @Test
    void setQuality() {
        food.setQuality(20.0);
        assertEquals(food.getQuality(), 20);
    }

    @Test
    void getQuantity() {
        assertEquals(food.getQuantity(), 10);
    }

    @Test
    void setQuantity() {
        food.setQuantity(20.0);
        assertEquals(food.getQuantity(), 20.0);
    }
}