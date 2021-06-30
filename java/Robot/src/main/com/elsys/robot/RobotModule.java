package main.com.elsys.robot;

import java.util.List;

public abstract class RobotModule {
    protected Integer id;
    protected String serialNumber;
    protected RobotModuleType type;

    public RobotModule(Integer id, String serialNumber, RobotModuleType type) {
        this.id = id;
        this.serialNumber = serialNumber;
        this.type = type;
    }

    @Override
    public String toString() {
        return this.getClass().getSimpleName() + "{" +
                "id=" + id +
                ", serialNumber='" + serialNumber + '\'' +
                ", type=" + type +
                '}';
    }

    public void processCommand(String command) throws MaximumRotationAngle, NoItemGrabbed, ItemTooHeavy {}

    public boolean isMinimumRequirementCovered(List<RobotModule> rest){
        return true;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public RobotModuleType getType() {
        return type;
    }

    public void setType(RobotModuleType type) {
        this.type = type;
    }
}
