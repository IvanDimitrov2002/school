package org.elsys.ip.socketGame;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Player implements Runnable {
    private final static Lock lock = new ReentrantLock();
    private final int id;
    private final Socket socket;
    private final PrintWriter out;
    private final BufferedReader in;
    private final GameServer server;
    private int x;
    private int y;

    public Player(int id, Socket socket, GameServer server, int x, int y) throws IOException {
        this.id = id;
        this.socket = socket;
        this.server = server;
        this.x = x;
        this.y = y;
        out = new PrintWriter(socket.getOutputStream(), true);
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }

    public int getId() {
        return id;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public void run() {
        try {
            server.sendBoardToPlayers();
            while (server.isActive()) {
                String command = in.readLine();
                if (command == null) {
                    break;
                }

                int x = getX();
                int y = getY();

                if (command.equals("up")) {
                    y -= 1;
                } else if (command.equals("down")) {
                    y += 1;
                } else if (command.equals("left")) {
                    x -= 1;
                } else if (command.equals("right")) {
                    x += 1;
                }

                // Win condition
                if(x == Application.WIDTH - 1 && y == Application.HEIGHT - 1){
                    out.print("Player "  + id + " won!");
                }

                try {
                    lock.lock();
                    if (server.isPositionValid(x, y)) {
                        setX(x);
                        setY(y);
                        server.sendBoardToPlayers();

                    }
                } finally {
                    lock.unlock();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            server.getPlayers().remove(this);
            server.sendBoardToPlayers();
            server.getPlayerIds().add(0, id);

        }
    }

    public void sendBoard(String board) {
        out.print(board);
        out.println(Application.EOS);
    }
}
