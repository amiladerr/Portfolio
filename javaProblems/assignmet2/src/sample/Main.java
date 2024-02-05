package sample;


import java.io.File;
import java.util.*;

public class Main {
    static HashMap<String, ArrayList<Player>> AddtoList(String team, Player p, HashMap<String, ArrayList<Player>> HM) {
        ArrayList<Player> players = HM.get(team);
        if (players == null) {
            ArrayList<Player> igraci = new ArrayList<>();
            igraci.add(p);
            HM.put(team, igraci);
        } else players.add(p);
        return HM;
    }

    public static void main(String[] args) {
        Scanner scanner = null;
        ArrayList<Player> playerArrayList = new ArrayList<>();
        ArrayList<Team> teamArrayList = new ArrayList<>();
        ArrayList<Score> scoreArrayList = new ArrayList<>();
        try {
            File file = new File("Players.txt");
            scanner = new Scanner(file);
            assert scanner != null;
            while (scanner.hasNextLine()) {
                String nameLine = scanner.nextLine();
                String[] splitLine = nameLine.split(",");
                if (splitLine.length == 2) {
                    String name = splitLine[0].trim();
                    int score = Integer.parseInt(splitLine[1].trim());
                    Player p = new Player(name, score);
                    playerArrayList.add(p);
                }
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        try {
            File file = new File("Teams.txt");
            scanner = new Scanner(file);
            assert scanner != null;
            while (scanner.hasNextLine()) {
                String nameLine = scanner.nextLine();
                String name = nameLine;
                Team t = new Team(name);
                teamArrayList.add(t);
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        try {
            File file = new File("Scores.txt");
            scanner = new Scanner(file);
            assert scanner != null;
            while (scanner.hasNextLine()) {
                String nameLine = scanner.nextLine();
                String[] splitLine = nameLine.split(",");
                if (splitLine.length == 2) {
                    Player p1 = null;
                    Team t1 = null;
                    String player = splitLine[0].trim();
                    String team = splitLine[1].trim();
                    for (Player p : playerArrayList) {
                        if (player.equals(p.getNamePlayer()))
                            p1 = p;
                    }
                    for (Team t : teamArrayList) {
                        if (team.equals(t.getNameTeam()))
                            t1 = t;
                    }
                    Score s = new Score(p1, t1);
                    scoreArrayList.add(s);
                }
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        HashMap<String, ArrayList<Player>> HM = new HashMap<>();
        for (Score s : scoreArrayList) {
            HM = AddtoList(s.getTeamName().getNameTeam(), s.getPlayerName(), HM);
        }
        for (Map.Entry m : HM.entrySet()) {
            int max = 0;
            Player p = null;
            for (Player p1 : HM.get(m.getKey())) {
                int cnt = 0;
                for (Player p2 : HM.get(m.getKey())) {
                    if (p1.getNamePlayer().equals(p2.getNamePlayer()))
                        cnt++;
                }
                if (cnt > max) {
                    p = p1;
                    max = cnt;
                }
            }
            System.out.println(m.getKey() + " je primio najvise golova od " + p.getNamePlayer());
        }
        ArrayList<Player> daliGo = new ArrayList<>();
        daliGo.add(scoreArrayList.get(0).getPlayerName());
        System.out.println(scoreArrayList.get(0).getPlayerName().getNamePlayer());
        for (Score s : scoreArrayList) {
            boolean daLiPostoji = false;
            for (Player p : daliGo) {
                if (s.getPlayerName().getNamePlayer().equals(p.getNamePlayer())) {
                    daLiPostoji = true;
                    break;
                }
            }
            if (daLiPostoji == false) {
                System.out.println(s.getPlayerName().getNamePlayer());
                daliGo.add(s.getPlayerName());
            }

        }
        ArrayList<Player> rightScore = new ArrayList<>();
        for (Score s : scoreArrayList) {
            boolean daLiPostoji = false;
            for (Player p : rightScore) {
                if (s.getPlayerName().getNamePlayer().equals(p.getNamePlayer())) {
                    daLiPostoji = true;
                    p.setScore(p.getScore() + 1);
                    break;
                }
            }
            if (daLiPostoji == false) {
                Player tmp2 = new Player(s.getPlayerName().getNamePlayer(), 1);
                rightScore.add(tmp2);
            }
        }
        for (Player p : rightScore) {
            for (Player p1 : playerArrayList) {
                if (p.getNamePlayer().equals(p1.getNamePlayer())) {
                    if (p.getScore() != p1.getScore()) {
                        System.out.println("The player " + p.getNamePlayer() + " has the correct score of: " + p.getScore());
                    }
                }

            }
        }
        Thread t1 = new Threading(rightScore);
        t1.run();
    }
}

