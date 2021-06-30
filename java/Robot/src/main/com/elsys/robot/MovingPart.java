package main.com.elsys.robot;

import java.util.List;

public class MovingPart extends RobotModule {
    private Integer speed;
    private Integer position = 0;
    private Integer currRotationAngle = 0;

    public MovingPart(Integer id, String serialNumber, RobotModuleType type, Integer speed) {
        super(id, serialNumber, type);
        this.speed = speed;
    }

    @Override
    public String toString() {
        return "MovingPart{" +
                "speed=" + speed +
                ", position=" + position +
                ", currRotationAngle=" + currRotationAngle +
                ", id=" + id +
                ", serialNumber='" + serialNumber + '\'' +
                ", type=" + type +
                '}';
    }

    @Override
    public void processCommand(String command) {
        try{
            String action = command.split(" ")[0];
            Integer arg = Integer.valueOf(command.split(" ")[1]);
            switch (action) {
                case "move_fwd":
                    position += arg;
                    break;
                case "move_back":
                    position -= arg;
                    break;
                case "rotate_left":
                    currRotationAngle += arg;
                    break;
                case "rotate_right":
                    currRotationAngle -= arg;
                    break;
            }
            System.out.println(this);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid argument.");
        }
    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        if(type == RobotModuleType.LEG){
            return rest.stream().anyMatch(module -> module instanceof Head && ((Head) module).getDeepSight())
                   &&
                   rest.stream().filter(module -> module instanceof MovingPart && module.getType() == RobotModuleType.LEG)
                            .count() >= 2;
        } else if(type == RobotModuleType.CHAIN){
            return rest.stream().filter(module -> module instanceof MovingPart && module.getType() == RobotModuleType.CHAIN)
                    .count() >= 2;
        } else if(type == RobotModuleType.WHEEL){
            return rest.stream().filter(module -> module instanceof MovingPart && module.getType() == RobotModuleType.WHEEL)
                    .count() >= 3;
        }
        return false;
    }

    public Integer getSpeed() {
        return speed;
    }

    public void setSpeed(Integer speed) {
        this.speed = speed;
    }

    public Integer getPosition() {
        return position;
    }

    public Integer getCurrRotationAngle() {
        return currRotationAngle;
    }
}
