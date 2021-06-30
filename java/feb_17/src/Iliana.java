public class Iliana {
    public String name;
    private int age;

    public int getAge(){
        return age;
    }

    Iliana(){
//        name = "Iliana";
//        age = 17;
        this("Iliana", 17);
    }

    Iliana(String name, int age){
        this.name = name;
        this.age = age;
    }
}
