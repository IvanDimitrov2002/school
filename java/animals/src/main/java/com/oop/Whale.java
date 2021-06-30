package main.java.com.oop;

public class Whale extends Mammal implements ISwimmable {
    public Whale(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a whale and my name is " + name + " !");
    }

    @Override
    public void swim() {
        System.out.println("I am a whale and I can swim");
    }
}
