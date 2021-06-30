package main.java.com.squirrels;

public class McBurger extends Food {
    private Boolean passedWinter = false;

    public McBurger(Double quantity, Double quality) {
        super(quantity, quality);
    }

    @Override
    public void passWinter() {
        if(!passedWinter){
            passedWinter = true;
            quantity *= 0.8;
            quality *= 0.5;
        }
    }

    public Boolean getPassedWinter() {
        return passedWinter;
    }

    public void setPassedWinter(Boolean passedWinter) {
        this.passedWinter = passedWinter;
    }
}
