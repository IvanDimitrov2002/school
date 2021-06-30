package main.com.elsys.robot;

public class ItemTooHeavy extends Exception {
    public ItemTooHeavy() {
        super("The grabbed item is too heavy to lift.");
    }
}
