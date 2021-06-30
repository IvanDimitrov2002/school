package main.com.elsys.robot;

import java.util.ArrayList;
import java.util.List;

public class Robot {
    private String name;
    private String serialNumber;
    private Integer maximumModules;
    private List<RobotModule> modules;

    public Robot(String name, String serialNumber, Integer maximumModules, List<RobotModule> modules) throws UnableToAddModule {
        this.name = name;
        this.serialNumber = serialNumber;
        this.maximumModules = maximumModules;
        this.modules = modules;
        if(modules.size() > maximumModules){
            throw new UnableToAddModule();
        }
    }

    public void addModule(RobotModule newModule) throws UnableToAddModule {
        if(modules.contains(newModule) || modules.size() + 1 > maximumModules){
            throw new UnableToAddModule();
        }
        modules.add(newModule);
    }

    public boolean isMinimumRequirementCovered(){
        boolean hasHead = modules.stream().anyMatch(module -> module instanceof Head);
        boolean hasArms = modules.stream().filter(module -> module instanceof Arm).count() >= 2;
        boolean hasMovingPart = modules.stream().anyMatch(module -> module instanceof MovingPart);
        boolean modulesCheck = modules.stream().anyMatch(module -> !module.isMinimumRequirementCovered(modules));
        return hasHead && hasArms && hasMovingPart && !modulesCheck;
    }

    public void processCommand(String command){

        try {
            String id = command.split(" ")[0];
            String commands = command.split(" ").length > 2
                    ?
                    command.split(" ")[1] + " " + command.split(" ")[2]
                    :
                    command.split(" ")[1];

            switch (id.toLowerCase()) {
                case "arm":
                    modules.stream().filter(module -> module instanceof Arm).forEach(module -> {
                        try {
                            module.processCommand(commands);
                        } catch (MaximumRotationAngle | NoItemGrabbed | ItemTooHeavy e) {
                            System.out.println(e.getMessage());
                        }
                    });
                    break;
                case "head":
                    modules.stream().filter(module -> module instanceof Head).forEach(module -> {
                        try {
                            module.processCommand(commands);
                        } catch (MaximumRotationAngle | NoItemGrabbed | ItemTooHeavy e) {
                            System.out.println(e.getMessage());
                        }
                    });
                    break;
                case "leg":
                    modules.stream().filter(module -> module instanceof MovingPart).forEach(module -> {
                        try {
                            module.processCommand(commands);
                        } catch (MaximumRotationAngle | NoItemGrabbed | ItemTooHeavy e) {
                            System.out.println(e.getMessage());
                        }
                    });
                    break;
                default:
                    modules.stream().filter(module -> module.getId().equals(Integer.valueOf(id))).forEach(module -> {
                        try {
                            module.processCommand(commands);
                        } catch (MaximumRotationAngle | NoItemGrabbed | ItemTooHeavy e) {
                            System.out.println(e.getMessage());
                        }
                    });
                    break;
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Invalid command");
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public Integer getMaximumModules() {
        return maximumModules;
    }

    public void setMaximumModules(Integer maximumModules) {
        this.maximumModules = maximumModules;
    }

    public List<RobotModule> getModules() {
        return modules;
    }

    public void setModules(List<RobotModule> modules) {
        this.modules = modules;
    }
}
