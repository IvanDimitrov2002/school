package main.com.elsys.robot;

import java.util.List;

public class Arm extends RobotModule {
    private Integer joints;
    private Integer currLift = 0;
    private Integer maxLift;

    public Arm(Integer id, String serialNumber, RobotModuleType type, Integer joints, Integer maxLift) {
        super(id, serialNumber, type);
        this.joints = joints;
        this.maxLift = maxLift;
    }

    @Override
    public String toString() {
        return "Arm{" +
                "joints=" + joints +
                ", currLift=" + currLift +
                ", maxLift=" + maxLift +
                ", id=" + id +
                ", serialNumber='" + serialNumber + '\'' +
                ", type=" + type +
                '}';
    }

    @Override
    public void processCommand(String command) throws NoItemGrabbed, ItemTooHeavy {
        try{
            String action = command.split(" ")[0];

            Integer arg = command.split(" ").length > 1
                    ?
                    Integer.parseInt(command.split(" ")[1])
                    :
                    0;
            switch (action) {
                case "grab":
                    currLift = arg;
                    break;
                case "release":
                    if (currLift == 0) {
                        throw new NoItemGrabbed();
                    }
                    currLift = 0;
                    break;
                case "lift":
                    if (currLift == 0) {
                        throw new NoItemGrabbed();
                    }
                    if (currLift > maxLift) {
                        throw new ItemTooHeavy();
                    }
                    break;
            }
            System.out.println(this);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid argument.");
        }
    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        if(type == RobotModuleType.WITH_FINGERS){
            return rest.stream().anyMatch(module -> module instanceof Head && ((Head) module).getDeepSight());
        }
        return true;
    }

    public Integer getCurrLift() {
        return currLift;
    }

    public Integer getJoints() {
        return joints;
    }

    public void setJoints(Integer joints) {
        this.joints = joints;
    }

    public Integer getMaxLift() {
        return maxLift;
    }

    public void setMaxLift(Integer maxLift) {
        this.maxLift = maxLift;
    }
}
