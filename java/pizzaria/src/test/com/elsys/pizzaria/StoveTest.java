package test.com.elsys.pizzaria;

import main.com.elsys.pizzaria.Pizzeria;
import main.com.elsys.pizzaria.Stove;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StoveTest {
    Stove stove;

    @BeforeEach
    void setUp() {
        stove = new Stove(3, new Pizzeria());
    }

    @Test
    void setId() {
        stove.setId(2);
        assertEquals(2, stove.getId());
    }

    @Test
    void getCapacity() {
        assertEquals(3, stove.getCapacity());
    }

    @Test
    void setCapacity() {
        stove.setCapacity(4);
        assertEquals(4, stove.getCapacity());
    }

    @Test
    void getCurrCapacity() {
        assertEquals(0, stove.getCurrCapacity());
    }

    @Test
    void setCurrCapacity() {
        stove.setCurrCapacity(1);
        assertEquals(1, stove.getCurrCapacity());
    }

    @Test
    void getWorking() {
        assertEquals(false, stove.getWorking());
    }

    @Test
    void setWorking() {
        stove.setWorking(true);
        assertEquals(true, stove.getWorking());
    }
}