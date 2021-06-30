package main.java.com.squirrels;

public class Nuts extends Food {
    public Nuts(Double quantity, Double quality) {
        super(quantity, quality);
    }

    @Override
    public void passWinter(){
        //Nuts don't expire :)
    };
}
