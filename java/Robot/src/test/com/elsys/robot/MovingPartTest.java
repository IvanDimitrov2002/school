package test.com.elsys.robot;

import main.com.elsys.robot.MovingPart;
import main.com.elsys.robot.RobotModule;
import main.com.elsys.robot.RobotModuleType;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MovingPartTest {
    MovingPart leg;

    @BeforeEach
    void setUp() {
        leg = new MovingPart(1, "QWERTYUI", RobotModuleType.CHAIN, 5);
    }

    @Test
    void isMinimumRequirementCovered() {
        List<RobotModule> modules = new ArrayList<RobotModule>();
        modules.add(new MovingPart(2, "QWERTYUI", RobotModuleType.CHAIN, 5));
        modules.add(new MovingPart(3, "QWERTYUI", RobotModuleType.CHAIN, 5));
        assertTrue(leg.isMinimumRequirementCovered(modules));
    }

    @Test
    void getSpeed() {
        assertEquals(5, leg.getSpeed());
    }

    @Test
    void setSpeed() {
        leg.setSpeed(6);
        assertEquals(6, leg.getSpeed());
    }

    @Test
    void getPosition() {
        assertEquals(0, leg.getPosition());
    }

    @Test
    void getCurrRotationAngle() {
        assertEquals(0, leg.getCurrRotationAngle());
    }
}