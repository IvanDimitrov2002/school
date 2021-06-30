package test.com.elsys.robot;

import main.com.elsys.robot.Arm;
import main.com.elsys.robot.Head;
import main.com.elsys.robot.RobotModule;
import main.com.elsys.robot.RobotModuleType;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ArmTest {
    Arm arm;

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        arm = new Arm(1, "12345678", RobotModuleType.WITH_FINGERS, 5, 300);
    }

    @org.junit.jupiter.api.Test
    void getId() {
        assertEquals(1, arm.getId());
    }

    @org.junit.jupiter.api.Test
    void setId() {
        arm.setId(2);
        assertEquals(2, arm.getId());
    }

    @org.junit.jupiter.api.Test
    void getSerialNumber() {
        assertEquals("12345678", arm.getSerialNumber());
    }

    @org.junit.jupiter.api.Test
    void setSerialNumber() {
        arm.setSerialNumber("87654321");
        assertEquals("87654321", arm.getSerialNumber());
    }

    @org.junit.jupiter.api.Test
    void getType() {
        assertEquals(RobotModuleType.WITH_FINGERS, arm.getType());
    }

    @org.junit.jupiter.api.Test
    void setType() {
        arm.setType(RobotModuleType.WITH_PINCH);
        assertEquals(RobotModuleType.WITH_PINCH, arm.getType());
    }

    @org.junit.jupiter.api.Test
    void isMinimumRequirementCovered() {
        List<RobotModule> modules = new ArrayList<RobotModule>();
        ArrayList<String> sensors = new ArrayList<String>();
        sensors.add("accelerometer");
        sensors.add("accelerometer");
        modules.add(new Head(2, "QWERTYUI", 180, sensors));
        assertTrue(arm.isMinimumRequirementCovered(modules));
    }

    @org.junit.jupiter.api.Test
    void getCurrLift() {
        assertEquals(0, arm.getCurrLift());
    }

    @org.junit.jupiter.api.Test
    void getJoints() {
        assertEquals(5, arm.getJoints());
    }

    @org.junit.jupiter.api.Test
    void setJoints() {
        arm.setJoints(6);
        assertEquals(6, arm.getJoints());
    }

    @org.junit.jupiter.api.Test
    void getMaxLift() {
        assertEquals(300, arm.getMaxLift());
    }

    @org.junit.jupiter.api.Test
    void setMaxLift() {
        arm.setMaxLift(600);
        assertEquals(600, arm.getMaxLift());
    }
}