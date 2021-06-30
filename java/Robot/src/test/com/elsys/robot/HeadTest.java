package test.com.elsys.robot;

import main.com.elsys.robot.Head;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class HeadTest {
    Head head;

    @BeforeEach
    void setUp() {
        ArrayList<String> sensors = new ArrayList<String>();
        sensors.add("accelerometer");
        sensors.add("accelerometer");
        head = new Head(1, "QWERTYUI", 180, sensors);
    }

    @Test
    void getMaxRotationAngle() {
        assertEquals(180, head.getMaxRotationAngle());
    }

    @Test
    void setMaxRotationAngle() {
        head.setMaxRotationAngle(90);
        assertEquals(90, head.getMaxRotationAngle());
    }

    @Test
    void getCurrRotationAngle() {
        assertEquals(0, head.getCurrRotationAngle());
    }

    @Test
    void setCurrRotationAngle() {
        head.setCurrRotationAngle(90);
        assertEquals(90, head.getCurrRotationAngle());
    }

    @Test
    void getDeepSight() {
        assertTrue(head.getDeepSight());
    }

    @Test
    void getSensors() {
        ArrayList<String> sensors = new ArrayList<String>();
        sensors.add("accelerometer");
        sensors.add("accelerometer");
        assertArrayEquals(sensors.toArray(), head.getSensors().toArray());
    }

    @Test
    void setSensors() {
        ArrayList<String> sensors = new ArrayList<String>();
        sensors.add("gyroscope");
        sensors.add("gyroscope");
        head.setSensors(sensors);
        assertArrayEquals(sensors.toArray(), head.getSensors().toArray());
    }
}