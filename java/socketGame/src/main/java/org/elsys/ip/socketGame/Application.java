package org.elsys.ip.socketGame;

import java.io.IOException;

public class Application {
    public final static int WIDTH = 100;
    public final static int HEIGHT = 30;
    public final static String EOS = "EOS";
    public static void main(String[] args) throws IOException, InterruptedException {
        if (args.length > 0 && args[0].equals("server")) {
            new GameServer().start();
        } else {
            new GameClient().start();
        }
    }
}
