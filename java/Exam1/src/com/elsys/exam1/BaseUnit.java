package com.elsys.exam1;

public abstract class BaseUnit implements IMovable {
    protected String name;
    protected Integer speed;
    protected Position currPosition;
    protected Integer currHealth;
    protected Integer maxHealth;

    public BaseUnit(){};

    public BaseUnit(String name, Integer speed, Position position, Integer currHealth, Integer maxHealth) {
        this.name = name;
        this.speed = speed;
        this.currPosition = position;
        this.currHealth = currHealth;
        this.maxHealth = maxHealth;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getSpeed() {
        return speed;
    }

    public void setSpeed(Integer speed) {
        this.speed = speed;
    }

    public Position getPosition() {
        return currPosition;
    }

    public void setPosition(Position position) {
        this.currPosition = position;
    }

    public Integer getCurrHealth() {
        return currHealth;
    }

    public void setCurrHealth(Integer currHealth) {
        this.currHealth = currHealth;
    }

    public Integer getMaxHealth() {
        return maxHealth;
    }

    public void setMaxHealth(Integer maxHealth) {
        this.maxHealth = maxHealth;
    }
}
