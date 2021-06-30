package main.com.elsys.pizzaria;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IngredientAlreadyExists, InvalidIngredients {
        Pizzeria pizzeria = new Pizzeria();

        String inputInfo = "";
        String[] splittedInputInfo;
        Scanner scanner = new Scanner(System.in);

        while(true) {
            inputInfo = scanner.nextLine();
            if(inputInfo.equals("close")){
                break;
            }
            splittedInputInfo = inputInfo.trim().split("\\s*,\\s*");
            switch(splittedInputInfo[0].toLowerCase()){
                case "hirepizzaman":
                    pizzeria.getPizzamen().add(new Pizzaman(splittedInputInfo[1] + " " + splittedInputInfo[2],
                                    Integer.valueOf(splittedInputInfo[3]), pizzeria));
                    break;

                case "stove":
                    pizzeria.getStoves().add(new Stove(Integer.valueOf(splittedInputInfo[1]), pizzeria));
                    break;

                case "ingredient":
                    try{
                        if(pizzeria.getIngredients().stream().map(Ingredient::getName).collect(Collectors.toList()).contains(splittedInputInfo[1])){
                            throw new IngredientAlreadyExists();
                        }
                        pizzeria.getIngredients().add(new Ingredient(splittedInputInfo[1], splittedInputInfo[2]));
                    } catch(IngredientAlreadyExists e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case "hiredeliveryman":
                    pizzeria.getDeliverymen().add(new Deliveryman(splittedInputInfo[1] + " " + splittedInputInfo[2], pizzeria));
                    break;

                case "order":
                    ArrayList<Ingredient> newIngredients = new ArrayList<Ingredient>();
                    try{
                        for(int i = 2; i < splittedInputInfo.length; i++){
                            boolean isAvailable = false;
                            for(Ingredient ingredient : pizzeria.getIngredients()){
                                if(splittedInputInfo[i].equals(ingredient.getName())){
                                    newIngredients.add(ingredient);
                                    isAvailable = true;
                                    break;
                                }
                            }
                            if(!isAvailable){
                                throw new InvalidIngredients();
                            }
                        }
                        List<IngredientType> newIngredientsType = newIngredients.stream().map(Ingredient::getIngredientType).collect(Collectors.toList());
                        if(Collections.frequency(newIngredientsType, IngredientType.DOUGH) != 1){
                            throw new InvalidPizzaDough();
                        }
                        if(Collections.frequency(newIngredientsType, IngredientType.SAUCE) == 0 ||
                                Collections.frequency(newIngredientsType, IngredientType.SAUCE) > 2){
                            throw new InvalidPizzaSauce();
                        }
                        if(Collections.frequency(newIngredientsType, IngredientType.CHEESE) == 0){
                            throw new InvalidPizzaCheese();
                        }
                        pizzeria.getPizzas().add(new Pizza(Integer.valueOf(splittedInputInfo[1]), newIngredients));
                        for(Pizzaman pizzaman : pizzeria.getPizzamen()){
                            if(!pizzaman.getOccupied()){
                                pizzaman.setOccupied(true);
                                new Thread(pizzaman).start();
                            }
                        }
                        for(Stove stove : pizzeria.getStoves()){
                            if(!stove.getWorking()){
                                stove.setWorking(true);
                                new Thread(stove).start();
                            }
                        }
                        for(Deliveryman deliveryman : pizzeria.getDeliverymen()){
                            if(!deliveryman.getOccupied()){
                                deliveryman.setOccupied(true);
                                new Thread(deliveryman).start();
                            }
                        }
                    } catch (InvalidIngredients | InvalidPizzaDough | InvalidPizzaSauce | InvalidPizzaCheese e){
                        System.out.println(e.getMessage());
                    }
                    break;
            }
        }
    }
}