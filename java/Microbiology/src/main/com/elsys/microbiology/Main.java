package main.com.elsys.microbiology;

import java.util.concurrent.CopyOnWriteArrayList;

public class Main {

    public static void main(String[] args) {
        CopyOnWriteArrayList<Object> terrain = new CopyOnWriteArrayList<Object>();

        Paramecium paramecium1 = new Paramecium(new Point(0,0), 3, 2, terrain);
        Paramecium paramecium2 = new Paramecium(new Point(0,0), 3, 2, terrain);
        Paramecium paramecium3 = new Paramecium(new Point(0,0), 3, 2, terrain);

        terrain.add(paramecium1);
        terrain.add(paramecium2);
        terrain.add(paramecium3);
        terrain.add(new Food(new Point(10,10), 10));
        terrain.add(new Food(new Point(5,5), 5));

        new Thread(paramecium1).start();
        new Thread(paramecium2).start();
        new Thread(paramecium3).start();

    }
}
