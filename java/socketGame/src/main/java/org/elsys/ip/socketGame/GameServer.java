package org.elsys.ip.socketGame;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class GameServer {
    private final List<Player> players = Collections.synchronizedList(new ArrayList<>(10));
    private final List<Integer> playerIds = Collections.synchronizedList(new ArrayList<>(Arrays.asList(0,1,2,3,4,5,6,7,8,9)));
    private boolean isActive = false;

    public void start() throws IOException, InterruptedException {
        Scanner scanner = new Scanner(System.in);
        ServerSocket serverSocket = new ServerSocket(6666);
        isActive = true;

        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    System.out.println("Server started");
                    while (isActive) {
                        if(players.size() < 2){
                            Socket accept = serverSocket.accept();
                            Player player = new Player(playerIds.get(0), accept, GameServer.this, playerIds.get(0), playerIds.get(0));
                            playerIds.remove(0);
                            Thread thread = new Thread(player);
                            players.add(player);
                            thread.start();
                        }
                    }
                    serverSocket.close();
                } catch (IOException e) {
                    if(e.getMessage().equals("Socket closed")){
                        System.out.println("Server stopped. Socket closed");
                    }
                }
            }
        }).start();

        while (isActive) {
            String next = scanner.next();
            if ("stop".equals(next)) {
                serverSocket.close();
                isActive = false;
            }
        }
    }

    public void sendBoardToPlayers(){
        players.forEach(p -> p.sendBoard(getBoard()));
    }

    private String getBoard() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < Application.HEIGHT; ++i) {
            for (int j = 0; j < Application.WIDTH; ++j) {
                final int x = j;
                final int y = i;
                Optional<Player> samePosition = players.stream().filter(p -> p.getX() == x && p.getY() == y).findFirst();
                if (samePosition.isPresent()) {
                    result.append(samePosition.get().getId());
                } else {
                    result.append(' ');
                }
            }
            result.append("\n");
        }
        return result.toString();
    }

    public boolean isPositionValid(int x, int y) {
        return x >= 0 && x < Application.WIDTH && y >= 0 && y < Application.HEIGHT &&
                players.stream().noneMatch(p -> p.getX() == x && p.getY() == y);
    }

    public List<Player> getPlayers() {
        return players;
    }

    public List<Integer> getPlayerIds() {
        return playerIds;
    }

    public boolean isActive() {
        return isActive;
    }
}
