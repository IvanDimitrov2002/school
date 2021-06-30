package main.com.elsys.examprep;

public class IncorrectAnimalType extends Exception {
    public IncorrectAnimalType() {
        super("There is no pool at the cage.");
    }
}
