package main.com.elsys.examprep;

public class NoSpaceLeft extends Exception {
    public NoSpaceLeft() {
        super("No space left in the cage.");
    }
}
