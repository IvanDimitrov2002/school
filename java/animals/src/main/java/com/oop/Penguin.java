package main.java.com.oop;

public class Penguin extends Bird implements ISwimmable, IWalkable {
    public Penguin(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a penguin and my name is " + name + " !");
    }

    @Override
    public void swim() {
        System.out.println("I am a penguin and I can swim");
    }

    @Override
    public void walk() {
        System.out.println("I am a penguin and I can walk");
    }
}
