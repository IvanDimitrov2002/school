package main.com.elsys.Angryman;

import java.util.concurrent.CopyOnWriteArrayList;

public class Game {
    private CopyOnWriteArrayList<Player> players = new CopyOnWriteArrayList<Player>();
    private CopyOnWriteArrayList<Player> board = new CopyOnWriteArrayList<Player>();

    public void init(){
        for(int i = 0; i < 20; i++){
            if(i == 0 || i == 5 || i == 10 || i == 15){
                Player player = new Player("Gosho" + i, this);
                board.add(player);
                players.add(player);
            } else {
                board.add(null);
            }
        }
    }

    public void run(){
        players.get(0).setStatus(Status.TURN);
        for(Player player : players){
            new Thread(player).start();
        }
        while(true){
            if(players.size() == 1){
                break;
            }
        }
        for(Player player : players){
            if(player != null){
                player.setStatus(Status.NOT_TURN);
                player.setEliminated(true);
                System.out.println("The winner is " + player.getName());
            }
        }
    }

    public void removePlayer(Player player){
        player.setEliminated(true);
        board.set(board.indexOf(player), null);
        players.remove(player);
    }

    public void finishTurn(Player player){
        player.setStatus(Status.NOT_TURN);
        Integer index = players.indexOf(player);
        if(index == players.size() - 1){
            players.get(0).setStatus(Status.TURN);
        } else {
            players.get(index + 1).setStatus(Status.TURN);
        }
    }

    public CopyOnWriteArrayList<Player> getPlayers() {
        return players;
    }

    public void setPlayers(CopyOnWriteArrayList<Player> players) {
        this.players = players;
    }

    public CopyOnWriteArrayList<Player> getBoard() {
        return board;
    }

    public void setBoard(CopyOnWriteArrayList<Player> board) {
        this.board = board;
    }
}
