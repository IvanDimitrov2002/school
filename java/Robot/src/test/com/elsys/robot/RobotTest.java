package test.com.elsys.robot;

import main.com.elsys.robot.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class RobotTest {
    Robot robot;

    @BeforeEach
    void setUp() throws UnableToAddModule {
        List<RobotModule> modules = new ArrayList<RobotModule>();
        ArrayList<String> sensors = new ArrayList<String>();
        sensors.add("accelerometer");
        sensors.add("accelerometer");
        modules.add(new Head(1, "QWERTYUI", 180, sensors));
        modules.add(new Arm(2, "12345678", RobotModuleType.WITH_FINGERS, 5, 300));
        modules.add(new Arm(3, "12345678", RobotModuleType.WITH_FINGERS, 5, 300));
        modules.add(new MovingPart(4, "QWERTYUI", RobotModuleType.CHAIN, 5));
        modules.add(new MovingPart(5, "QWERTYUI", RobotModuleType.CHAIN, 5));
        robot = new Robot("Sam", "QWERTYUI", 7, modules);
    }

    @Test
    void addModule() throws UnableToAddModule {
        robot.addModule(new MovingPart(6, "QWERTYUI", RobotModuleType.CHAIN, 5));
        robot.addModule(new MovingPart(7, "QWERTYUI", RobotModuleType.CHAIN, 5));
        assertEquals(7, robot.getModules().size());
    }

    @Test
    void isMinimumRequirementCovered() {
        assertTrue(robot.isMinimumRequirementCovered());
    }
}