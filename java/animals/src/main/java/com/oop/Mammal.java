package main.java.com.oop;

public abstract class Mammal extends Animal {
    public Mammal(String name) {
        super(name);
    }

    void giveBirth(){
        System.out.println("I am mammal and I am giving birth");
    }
}
