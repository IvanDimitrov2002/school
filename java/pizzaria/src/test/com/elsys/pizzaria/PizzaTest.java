package test.com.elsys.pizzaria;

import main.com.elsys.pizzaria.Ingredient;
import main.com.elsys.pizzaria.Pizza;
import main.com.elsys.pizzaria.PizzaStatus;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class PizzaTest {
    Pizza pizza;
    ArrayList<Ingredient> ingredients;

    @BeforeEach
    void setUp() {
        ingredients = new ArrayList<Ingredient>();
        ingredients.add(new Ingredient("White Dough", "dough"));
        ingredients.add(new Ingredient("Ketchup", "sauce"));
        ingredients.add(new Ingredient("Yellow Cheese", "cheese"));
        ingredients.add(new Ingredient("Ham", "meat"));
        pizza = new Pizza(1, ingredients);
    }

    @Test
    void getIngredients() {
        assertArrayEquals(ingredients.toArray(), pizza.getIngredients().toArray());
    }

    @Test
    void setIngredients() {
        ArrayList<Ingredient> ingredients = new ArrayList<Ingredient>();
        ingredients.add(new Ingredient("Brown Dough", "dough"));
        ingredients.add(new Ingredient("Mayo", "sauce"));
        ingredients.add(new Ingredient("Mozzarella", "cheese"));
        ingredients.add(new Ingredient("Chicken", "meat"));
        pizza.setIngredients(ingredients);
        assertArrayEquals(ingredients.toArray(), pizza.getIngredients().toArray());
    }

    @Test
    void getStatus() {
        assertEquals(PizzaStatus.MAKING, pizza.getStatus());
    }

    @Test
    void setStatus() {
        pizza.setStatus(PizzaStatus.OCCUPIED);
        assertEquals(PizzaStatus.OCCUPIED, pizza.getStatus());
    }

    @Test
    void changeStatus() {
        pizza.changeStatus(PizzaStatus.MAKING, PizzaStatus.OCCUPIED);
        assertEquals(PizzaStatus.OCCUPIED, pizza.getStatus());
    }

    @Test
    void getOrderId() {
        assertEquals(1, pizza.getOrderId());
    }

    @Test
    void setOrderId() {
        pizza.setOrderId(2);
        assertEquals(2, pizza.getOrderId());
    }
}