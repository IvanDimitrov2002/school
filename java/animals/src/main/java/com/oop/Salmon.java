package main.java.com.oop;

public class Salmon extends Fish implements ISwimmable {
    public Salmon(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a salmon and my name is " + name + " !");
    }

    @Override
    public void swim() {
        System.out.println("I am a salmon and I can swim");
    }
}
