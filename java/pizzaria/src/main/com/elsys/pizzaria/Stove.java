package main.com.elsys.pizzaria;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.atomic.AtomicInteger;;import static java.lang.Thread.currentThread;

public class Stove implements Runnable {
    private static Integer stoveInstances = 0;
    private Integer id;
    private Integer capacity;
    private AtomicInteger currCapacity = new AtomicInteger(0);
    private Pizzeria pizzeria;
    private Boolean isWorking = false;

    public Stove(Integer capacity, Pizzeria pizzeria) {
        this.id = ++stoveInstances;
        this.capacity = capacity;
        this.pizzeria = pizzeria;
    }

    private Boolean availableForBake(){
        for(Pizza pizza : pizzeria.getPizzas()){
            if(pizza.getStatus() == PizzaStatus.MAKING || pizza.getStatus() == PizzaStatus.BAKING || pizza.getStatus() == PizzaStatus.OCCUPIED){
                return true;
            }
        }
        return false;
    }

    @Override
    public void run() {
        long stoveThreadId = currentThread().getId();
        while(availableForBake()){
            File pizzamanFile = new File( "Stove" + id + "-" + stoveThreadId + ".txt");
            try {
                pizzamanFile.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
            pizzeria.getPizzas().stream().filter(pizza -> currCapacity.get() <= capacity - 1 && pizza.changeStatus(PizzaStatus.BAKING, PizzaStatus.OCCUPIED)).forEachOrdered(pizza -> {
                DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
                try {
                    Date dateobj = new Date();
                    FileWriter fileWriter = new FileWriter("Stove" + id + "-" + stoveThreadId + ".txt", true);
                    fileWriter.write(df.format(dateobj) + " " + stoveThreadId + id + " start " + pizza.getOrderId() + "\n");
                    fileWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                currCapacity.getAndIncrement();
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        Thread pizzaThread = new Thread(pizza);
                        pizzaThread.start();
                        try {
                            pizzaThread.join();
                            Date dateobj = new Date();
                            FileWriter fileWriter = new FileWriter("Stove" + id + "-" + stoveThreadId + ".txt", true);
                            fileWriter.write(df.format(dateobj) + " " + stoveThreadId + id + " end " + pizza.getOrderId() + "\n");
                            fileWriter.close();
                        } catch (IOException | InterruptedException e) {
                            e.printStackTrace();
                        }
                        currCapacity.getAndDecrement();
                    }
                }).start();
            });
        }
        isWorking = false;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getCapacity() {
        return capacity;
    }

    public void setCapacity(Integer capacity) {
        this.capacity = capacity;
    }

    public Integer getCurrCapacity() {
        return currCapacity.get();
    }

    public void setCurrCapacity(Integer currCapacity) {
        this.currCapacity.set(currCapacity);
    }

    public synchronized Boolean getWorking() {
        return isWorking;
    }

    public synchronized void setWorking(Boolean working) {
        isWorking = working;
    }
}
