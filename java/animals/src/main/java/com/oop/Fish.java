package main.java.com.oop;

public abstract class Fish extends Animal {
    public Fish(String name) {
        super(name);
    }

    void spawn(){
        System.out.println("I am fish and I am spawning");
    }
}
