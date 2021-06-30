package main.com.elsys.microbiology;

import java.util.ArrayList;

public class Ameba implements Runnable {
    private Point position;
    private Integer rate;
    private Integer speed;
    private ArrayList<Object> terrain = new ArrayList<Object>();

    public Ameba(Point position, Integer rate, Integer speed) {
        this.position = position;
        this.rate = rate;
        this.speed = speed;
    }

    @Override
    public void run() {

    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }

    public Integer getSpeed() {
        return speed;
    }

    public void setSpeed(Integer speed) {
        this.speed = speed;
    }
}
