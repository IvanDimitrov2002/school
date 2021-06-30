package main.java.com.oop;

public abstract class Bird extends Animal {
    public Bird(String name) {
        super(name);
    }

    void layEggs(){
        System.out.println("I am bird and I am laying eggs");
    }
}
