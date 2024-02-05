package sample;

import java.util.ArrayList;

public class Threading extends Thread implements Runnable {
    private ArrayList<Player> rightScores = new ArrayList<>();

    public Threading(ArrayList<Player> rightScores) {
        this.rightScores = rightScores;
    }

    @Override
    public void run(){
        Player max = rightScores.get(0);
        for (Player p : rightScores) {
            if (p.getScore() > max.getScore())
                max=p;
        }
        System.out.println("The player with the highest score is " + max.getNamePlayer());

    }
}
