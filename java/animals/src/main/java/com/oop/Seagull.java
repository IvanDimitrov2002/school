package main.java.com.oop;

public class Seagull extends Bird implements IWalkable, ISwimmable, IFlyable {
    public Seagull(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a seagull and my name is " + name + " !");
    }

    @Override
    public void fly() {
        System.out.println("I am a seagull and I can fly");
    }

    @Override
    public void swim() {
        System.out.println("I am a seagull and I can swim");
    }

    @Override
    public void walk() {
        System.out.println("I am a seagull and I can walk");
    }
}
