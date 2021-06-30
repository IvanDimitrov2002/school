package main.java.com.squirrels;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
	    List<Squirrel> squirrels = new ArrayList<Squirrel>();
        Scanner scanner = new Scanner(System.in);
        String squirrelInfo = "";
        String foodInfo = "";
        String[] splittedInfo;
        String[] splittedFoodInfo;
        while(true){
            squirrelInfo = scanner.nextLine();
            if(squirrelInfo.equals("stop")){
                break;
            }
            splittedInfo = squirrelInfo.split("[, ]+");
            squirrels.add(new Squirrel(splittedInfo[0], Integer.valueOf(splittedInfo[1]), splittedInfo[2], new Burrow()));
        }
        while(true){
            foodInfo = scanner.nextLine();
            if(foodInfo.equals("stop")){
                break;
            }
            splittedFoodInfo = foodInfo.split("[, ]+");
            Iterator<Squirrel> iter = squirrels.iterator();
            while(iter.hasNext()){
                Squirrel squirrel = iter.next();
                try{
                    Food food;
                    switch (splittedFoodInfo[0]) {
                        case "nuts":
                            food = new Nuts(Double.valueOf(splittedFoodInfo[1]), Double.valueOf(splittedFoodInfo[2]));
                            break;
                        case "mcburger":
                            food = new McBurger(Double.valueOf(splittedFoodInfo[1]), Double.valueOf(splittedFoodInfo[2]));
                            break;
                        case "cake":
                            food = new Cake(Double.valueOf(splittedFoodInfo[1]), Double.valueOf(splittedFoodInfo[2]));
                            break;
                        default:
                            food = null;
                            break;
                    }
                    squirrel.addFood(food);
                    if(!iter.hasNext() && squirrel.getWentForFood() == squirrel.getLimitFoodGettering()){
                        throw new FoodGetterLimitExceeded();
                    }
                    break;
                } catch (FoodGetterLimitExceeded foodGetterLimitExceeded) {
                    if(!iter.hasNext()){
                        for(Squirrel s : squirrels){
                            s.passWinter();
                            System.out.println(s.getInfo());
                        }
                    }
                }
            }
        }
        for(Squirrel squirrel : squirrels){
            System.out.println(squirrel.getInfo());
        }
    }
}
