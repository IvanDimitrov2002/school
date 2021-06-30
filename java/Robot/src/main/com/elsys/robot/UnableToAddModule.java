package main.com.elsys.robot;

public class UnableToAddModule extends Exception {
    public UnableToAddModule() {
        super("Module already exists or maximum modules size reached.");
    }
}
