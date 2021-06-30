package org.elsys.ip.socketGame;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class GameClient {
    private void printScreen(String board) throws IOException, InterruptedException {
        clearConsole();
        System.out.print(board);
    }

    private void clearConsole() throws IOException, InterruptedException {
        if (System.getProperty("os.name").startsWith("Windows")) {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } else {
            new ProcessBuilder("clear").inheritIO().start().waitFor();
        }
    }

    public void start() throws IOException {
        Socket clientSocket = new Socket("192.168.0.104", 6666);
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    StringBuilder screen = new StringBuilder();
                    while (true) {
                        String line = in.readLine();
                        if(line == null){
                            break;
                        }
                        if (Application.EOS.equals(line)) {
                            printScreen(screen.toString());
                            screen = new StringBuilder();
                        } else {
                            screen.append(line);
                            screen.append("\n");
                        }
                    }
                    clientSocket.close();
                } catch (IOException | InterruptedException ignored) {
                }
            }
        }).start();

        Scanner scanner = new Scanner(System.in);
        while (!clientSocket.isClosed()) {
            String next = scanner.next();
            if ("w".equals(next)) {
                out.println("up");
            } else if ("s".equals(next)) {
                out.println("down");
            } else if ("a".equals(next)) {
                out.println("left");
            } else if ("d".equals(next)) {
                out.println("right");
            } else if ("exit".equals(next)) {
                clientSocket.close();
                break;
            }
        }

    }
}
