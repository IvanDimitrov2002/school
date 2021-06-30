package main.com.elsys.examprep;

import java.util.ArrayList;

public class Cage {
    private String id;
    private ArrayList<Animal> animals = new ArrayList<Animal>();
    private Integer capacity;
    private Boolean hasPool;
    private Type animalType;

    public void addAnimal(String cellId, Animal animal) throws NoSpaceLeft, IncorrectAnimalType, PoolRequired {
        if(animals.size() + 1 > capacity){
            throw new NoSpaceLeft();
        }
        if(animal.getPoolRequired() && !hasPool){
            throw new PoolRequired();
        }
        if(animal.getType() != animalType){
            throw new IncorrectAnimalType();
        }
        animals.add(animal);
    }

    public Type getAnimalType() {
        return animalType;
    }

    public void setAnimalType(Type animalType) {
        this.animalType = animalType;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public ArrayList<Animal> getAnimals() {
        return animals;
    }

    public void setAnimals(ArrayList<Animal> animals) {
        this.animals = animals;
    }

    public Integer getCapacity() {
        return capacity;
    }

    public void setCapacity(Integer capacity) {
        this.capacity = capacity;
    }

    public Boolean getHasPool() {
        return hasPool;
    }

    public void setHasPool(Boolean hasPool) {
        this.hasPool = hasPool;
    }
}