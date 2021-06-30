package test.com.elsys.pizzaria;

import main.com.elsys.pizzaria.Pizzaman;
import main.com.elsys.pizzaria.PizzamanType;
import main.com.elsys.pizzaria.Pizzeria;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PizzamanTest {
    Pizzaman pizzaman;

    @BeforeEach
    void setUp() {
        pizzaman = new Pizzaman("Ivan Dimitrov", 5, new Pizzeria());
    }

    @Test
    void getFullName() {
        assertEquals("Ivan Dimitrov", pizzaman.getFullName());
    }

    @Test
    void setFullName() {
        pizzaman.setFullName("Pancake Man");
        assertEquals("Pancake Man", pizzaman.getFullName());
    }

    @Test
    void getExperience() {
        assertEquals(5, pizzaman.getExperience());
    }

    @Test
    void setExperience() {
        pizzaman.setExperience(9);
        assertEquals(9, pizzaman.getExperience());
    }

    @Test
    void getType() {
        assertEquals(PizzamanType.SENIOR, pizzaman.getType());
    }

    @Test
    void setType() {
        pizzaman.setType(PizzamanType.MASTER);
        assertEquals(PizzamanType.MASTER, pizzaman.getType());
    }

    @Test
    void getPrepareTime() {
        assertEquals(0.5, pizzaman.getPrepareTime(), 1);
    }

    @Test
    void setPrepareTime() {
        pizzaman.setPrepareTime(1.0);
        assertEquals(1.0, pizzaman.getPrepareTime(), 1);
    }

    @Test
    void getOccupied() {
        assertEquals(false, pizzaman.getOccupied());
    }

    @Test
    void setOccupied() {
        pizzaman.setOccupied(true);
        assertEquals(true, pizzaman.getOccupied());
    }
}