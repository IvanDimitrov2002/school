package main.com.elsys.pizzaria;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import static java.lang.Thread.currentThread;
import static java.lang.Thread.sleep;

public class Pizzaman implements Runnable {
    private String fullName;
    private Integer experience;
    private PizzamanType type;
    private Double prepareTime;
    private Boolean isOccupied = false;
    private Pizzeria pizzeria;

    public Pizzaman(String fullName, Integer experience, Pizzeria pizzeria) {
        this.fullName = fullName;
        this.experience = experience;
        if(0 <= experience && experience <= 3){
            this.type = PizzamanType.JUNIOR;
            this.prepareTime = 1.0;
        } else if(4 <= experience && experience <= 8){
            this.type = PizzamanType.SENIOR;
            this.prepareTime = 0.5;
        } else if(9 <= experience){
            this.type = PizzamanType.MASTER;
            this.prepareTime = 0.3;
        }
        this.pizzeria = pizzeria;
    }

    private Boolean availableForMake(){
        for(Pizza pizza : pizzeria.getPizzas()){
            if(pizza.getStatus() == PizzaStatus.MAKING){
                return true;
            }
        }
        return false;
    }

    @Override
    public void run() {
        while(availableForMake()){
            File pizzamanFile = new File(fullName + "-" + currentThread().getId() + ".txt");
            try {
                pizzamanFile.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
            pizzeria.getPizzas().stream().filter(pizza -> pizza.changeStatus(PizzaStatus.MAKING, PizzaStatus.OCCUPIED)).forEach(pizza -> {
                DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
                try {
                    Date dateobj = new Date();
                    FileWriter fileWriter = new FileWriter(fullName + "-" + currentThread().getId() + ".txt", true);
                    fileWriter.write(df.format(dateobj) + " " + fullName + " " + pizza.getOrderId() + "\n");
                    fileWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                long requiredTime = (long) (pizza.getIngredients().size() * prepareTime * 1000);
                try {
                    sleep(requiredTime);
                    Date dateobj = new Date();
                    FileWriter fileWriter = new FileWriter(fullName + "-" + currentThread().getId() + ".txt", true);
                    fileWriter.write(df.format(dateobj) + " " + fullName + " " + pizza.getOrderId() + "\n");
                    fileWriter.close();
                    pizza.setStatus(PizzaStatus.BAKING);
                } catch (InterruptedException | IOException e) {
                    e.printStackTrace();
                }
            });
        }
        isOccupied = false;
}

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public Integer getExperience() {
        return experience;
    }

    public void setExperience(Integer experience) {
        this.experience = experience;
    }

    public PizzamanType getType() {
        return type;
    }

    public void setType(PizzamanType type) {
        this.type = type;
    }

    public Double getPrepareTime() {
        return prepareTime;
    }

    public void setPrepareTime(Double prepareTime) {
        this.prepareTime = prepareTime;
    }

    public synchronized Boolean getOccupied() {
        return isOccupied;
    }

    public synchronized void setOccupied(Boolean occupied) {
        isOccupied = occupied;
    }
}
