package main.com.elsys.Angryman;

import java.util.Random;

public class Die {
    public static int roll(){
        Random r = new Random();
        return r.nextInt(6) + 1;
    }
}
