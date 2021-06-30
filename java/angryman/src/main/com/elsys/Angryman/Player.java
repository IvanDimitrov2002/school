package main.com.elsys.Angryman;

import static java.lang.Thread.sleep;

public class Player implements Runnable {
    private String name;
    private Boolean eliminated = false;
    private Status status = Status.NOT_TURN;
    private Game game;

    public Player(String name, Game game) {
        this.name = name;
        this.game = game;
    }

    @Override
    public void run() {
        while(true){
            if(eliminated){
                break;
            }

//            System.out.println("TEST");

            if(status == Status.TURN){
                System.out.println("Player " + name + " started his turn!");
                Integer result = Die.roll();
                System.out.println("Player " + name + " rolled " + result + ".");
                Integer position = game.getBoard().indexOf(this);
                game.getBoard().set(position, null);
                System.out.println("Player " + name + " start from " + (position + 1) + " field.");

                if(position + result > 19){
                    position = (position + result) - 20;
                } else {
                    position += result;
                }

                if(game.getBoard().get(position) != null){
                    System.out.println(name + " eliminated " + game.getBoard().get(position).getName() + "!");
                    game.removePlayer(game.getBoard().get(position));
                }
                System.out.println("Player " + name + " went to " + (position + 1) + " field.");
                game.getBoard().set(position, this);
                System.out.println("Player " + name + " finished his turn!");
                game.finishTurn(this);
            }

            try {
                sleep(2500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public Boolean getEliminated() {
        return eliminated;
    }

    public synchronized void setEliminated(Boolean eliminated) {
        this.eliminated = eliminated;
    }

    public Game getGame() {
        return game;
    }

    public void setGame(Game game) {
        this.game = game;
    }

    public Status getStatus() {
        return status;
    }

    public synchronized void setStatus(Status status) {
        this.status = status;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
