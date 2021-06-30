package main.com.elsys.robot;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws UnableToAddModule {
        List<RobotModule> modules = new ArrayList<RobotModule>();
        ArrayList<String> sensors = new ArrayList<String>();

        sensors.add("accelerometer");
        sensors.add("accelerometer");
        sensors.add("temperature");
        sensors.add("infrared");
        sensors.add("gyroscope");

        modules.add(new Head(1, "1A2B3C4D", 180, sensors));
        modules.add(new Arm(2, "ABCDEFGH", RobotModuleType.WITH_FINGERS, 5, 500));
        modules.add(new Arm(3, "ABCDEFGH", RobotModuleType.WITH_FINGERS, 5, 500));
        modules.add(new MovingPart(4, "ZXCVBNML", RobotModuleType.LEG, 5));

        Robot robot = new Robot("Sam", "QWERTYUI", 5, modules);

        Scanner scanner = new Scanner(System.in);
        String inputInfo = "";

        System.out.println("Robot valid for manufacture: " + robot.isMinimumRequirementCovered());
        robot.addModule(new MovingPart(5, "ZXCVBNML", RobotModuleType.LEG, 5));
        System.out.println("Adding the necessary leg :)");
        System.out.println("Robot valid for manufacture: " + robot.isMinimumRequirementCovered() + "\n");

        while(true){
            inputInfo = scanner.nextLine();
            if(inputInfo.equals("stop")){
                break;
            }

            robot.processCommand(inputInfo);
        }
    }
}
