package main.com.elsys.robot;

public class NoItemGrabbed extends Exception {
    public NoItemGrabbed() {
        super("No item grabbed.");
    }
}
