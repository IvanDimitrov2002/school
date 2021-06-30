package main.com.elsys.robot;

import java.util.ArrayList;
import java.util.HashSet;

public class Head extends RobotModule {
    private ArrayList<String> sensors;
    private Integer maxRotationAngle;
    private Integer currRotationAngle = 0;
    private Boolean deepSight = false;

    public Head(Integer id, String serialNumber, Integer maxRotationAngle, ArrayList<String> sensors) {
        super(id, serialNumber, null);
        this.maxRotationAngle = maxRotationAngle;
        this.sensors = sensors;
        deepSight = (sensors.size() != new HashSet<>(sensors).size());
    }

    @Override
    public String toString() {
        return "Head{" +
                "sensors=" + sensors +
                ", maxRotationAngle=" + maxRotationAngle +
                ", currRotationAngle=" + currRotationAngle +
                ", deepSight=" + deepSight +
                ", id=" + id +
                ", serialNumber='" + serialNumber + '\'' +
                ", type=" + type +
                '}';
    }

    @Override
    public void processCommand(String command) throws MaximumRotationAngle {

        try{
            String action = command.split(" ")[0];
            Integer arg = Integer.valueOf(command.split(" ")[1]);

            if(action.equals("rotate_left")){
                if(currRotationAngle.equals(maxRotationAngle)){
                    throw new MaximumRotationAngle();
                }
                if(currRotationAngle + arg > maxRotationAngle){
                    currRotationAngle = maxRotationAngle;
                } else {
                    currRotationAngle += arg;
                }
            } else if(action.equals("rotate_right")){
                if(Math.abs(currRotationAngle) == maxRotationAngle && currRotationAngle < 0){
                    throw new MaximumRotationAngle();
                }
                if(Math.abs(currRotationAngle - arg) > maxRotationAngle){
                    currRotationAngle = -maxRotationAngle;
                } else {
                    currRotationAngle -= arg;
                }
            }
            System.out.println(this);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid argument.");
        }
    }

    public Integer getMaxRotationAngle() {
        return maxRotationAngle;
    }

    public void setMaxRotationAngle(Integer maxRotationAngle) {
        this.maxRotationAngle = maxRotationAngle;
    }

    public Integer getCurrRotationAngle() {
        return currRotationAngle;
    }

    public void setCurrRotationAngle(Integer currRotationAngle) {
        this.currRotationAngle = currRotationAngle;
    }

    public Boolean getDeepSight() {
        return deepSight;
    }

    public ArrayList<String> getSensors() {
        return sensors;
    }

    public void setSensors(ArrayList<String> sensors) {
        this.sensors = sensors;
        deepSight = (sensors.size() != new HashSet<>(sensors).size());
    }
}
