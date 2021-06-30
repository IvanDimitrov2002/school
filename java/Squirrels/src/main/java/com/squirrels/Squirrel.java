package main.java.com.squirrels;

public class Squirrel {
    private String name;
    private String type;
    private Integer age;
    private Burrow burrow;
    private Integer wentForFood = 0;
    private Integer limitFoodGettering = 4;

    public Squirrel(String name, Integer age, String type) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.burrow = new Burrow();
    }

    public Squirrel(String name, Integer age, String type, Burrow burrow) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.burrow = burrow;
    }

    public void addFood(Food food) throws FoodGetterLimitExceeded {
        if(wentForFood < limitFoodGettering){
            burrow.addFood(food);
            wentForFood++;
        } else {
            throw new FoodGetterLimitExceeded();
        }
    }

    public void passWinter(){
        age++;
        wentForFood = 0;
        burrow.passWinter();
    }

    public String getInfo(){
        return "<" + type + "> " + name + "(" + age + ") " +  String.format("%.2f", burrow.getTotalFoodScore()) + "\n"
                + burrow.getInfo();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public Burrow getBurrow() {
        return burrow;
    }

    public void setBurrow(Burrow burrow) {
        this.burrow = burrow;
    }

    public Integer getWentForFood() {
        return wentForFood;
    }

    public void setWentForFood(Integer wentForFood) {
        this.wentForFood = wentForFood;
    }

    public Integer getLimitFoodGettering() {
        return limitFoodGettering;
    }

    public void setLimitFoodGettering(Integer limitFoodGettering) {
        this.limitFoodGettering = limitFoodGettering;
    }
}
