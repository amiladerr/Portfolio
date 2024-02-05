package sample;

public class Player {
    private String namePlayer;
    private int score;

    public Player(String namePlayer, int score) {
        this.namePlayer = namePlayer;
        this.score = score;
    }

    public String getNamePlayer() {
        return namePlayer;
    }

    public void setNamePlayer(String namePlayer) {
        this.namePlayer = namePlayer;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

}
