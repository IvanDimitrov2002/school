package main.com.elsys.pizzaria;

public class InvalidPizzaSauce extends Exception{
    public InvalidPizzaSauce() {
        super("You must select minimum 1 type of sauce and maximum 2 types!");
    }
}
