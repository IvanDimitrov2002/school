package test.com.elsys.pizzaria;

import main.com.elsys.pizzaria.Ingredient;
import main.com.elsys.pizzaria.IngredientType;

import static org.junit.jupiter.api.Assertions.*;

class IngredientTest {
    Ingredient ingredient;

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        ingredient = new Ingredient("White Dough", "dough");
    }

    @org.junit.jupiter.api.Test
    void getName() {
        assertEquals("White Dough", ingredient.getName());
    }

    @org.junit.jupiter.api.Test
    void setName() {
        ingredient.setName("Brown Dough");
        assertEquals("Brown Dough", ingredient.getName());
    }

    @org.junit.jupiter.api.Test
    void getIngredientType() {
        assertEquals(IngredientType.DOUGH, ingredient.getIngredientType());
    }

    @org.junit.jupiter.api.Test
    void setIngredientType() {
        ingredient.setIngredientType(IngredientType.MEAT);
        assertEquals(IngredientType.MEAT, ingredient.getIngredientType());
    }

    @org.junit.jupiter.api.Test
    void getTime() {
        assertEquals(2.0, ingredient.getTime());
    }

    @org.junit.jupiter.api.Test
    void setTime() {
        ingredient.setTime(3.0);
        assertEquals(3.0, ingredient.getTime());
    }
}