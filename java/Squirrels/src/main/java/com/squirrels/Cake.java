package main.java.com.squirrels;

public class Cake extends Food {
    private Integer age = 0;

    public Cake(Double quantity, Double quality) {
        super(quantity, quality);
    }

    @Override
    public void passWinter() {
        age++;
        quantity *= 0.7;
        quality *= (0.1 + 1.99 / Math.pow(2, (age / 0.85)));
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }


}
