package sample;

public class Score {
    private Player playerName;
    private Team teamName;

    public Score(Player playerName, Team teamName) {
        this.playerName = playerName;
        this.teamName = teamName;
    }

    public Player getPlayerName() {
        return playerName;
    }

    public void setPlayerName(Player playerName) {
        this.playerName = playerName;
    }

    public Team getTeamName() {
        return teamName;
    }

    public void setTeamName(Team teamName) {
        this.teamName = teamName;
    }
}
