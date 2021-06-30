package main.java.com.oop;

public class FlyingFish extends Fish implements ISwimmable {
    public FlyingFish(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a flying fish and my name is " + name + " !");
    }

    @Override
    public void swim() {
        System.out.println("I am a flying fish and I can swim");
    }
}
