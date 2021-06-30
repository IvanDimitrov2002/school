package com.elsys.exam1;

import java.util.List;

public class Raider extends BaseUnit {
    private Integer power;
    private Integer range;
    private Worker target;
    private Resource resource;

    public void findNewVictim(List<Worker> workers) {
        Integer minDistance = workers.get(0).getPosition().getSum();
        for(Worker worker : workers) {
            if(worker.getPosition().getSum() < minDistance){
                minDistance = worker.getPosition().getSum();
                target = worker;
            }
        }
    }




    @Override
    public void nextTick() {

    }

    @Override
    public void move() {

    }
}
