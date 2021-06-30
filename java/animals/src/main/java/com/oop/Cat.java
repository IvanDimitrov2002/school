package main.java.com.oop;

public class Cat extends Mammal implements IWalkable, ISwimmable {
    public Cat(String name) {
        super(name);
    }

    @Override
    void sayName() {
        System.out.println("I am a cat and my name is " + name + " !");
    }

    @Override
    public void walk() {
        System.out.println("I am a cat and I can walk");
    }

    @Override
    public void swim() {
        System.out.println("I am a cat and I can swim");
    }
}
