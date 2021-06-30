package main.java.com.oop;

public abstract class Animal {
    String name;

    public Animal(String name) {
        this.name = name;
    }

    abstract void sayName();
}
