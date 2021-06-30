package com.elsys.exam1;

import java.util.ArrayList;
import java.util.List;

public class Simulation {
    private List<Resource> resources = new ArrayList<Resource>();
    private List<Worker> workers = new ArrayList<Worker>();
    private Integer totalQuantity = 0;

    void run(){
        for(Worker worker : workers){
            while(worker.getResource().getQuantity() > 0){
                worker.nextTick();
            }
            totalQuantity += worker.getTotalQuantity();
            cleanupResources();
            worker.findNewResource(resources);
        }
    }

    private void cleanupResources(){
        resources.removeIf(resource -> resource.getQuantity() == 0);
    }
}
