package ssst.edu.ba;

public class Course {
    private String name;
    private int credits;
    private String dpt;
    private int yos;

    public Course(String name, int credits, String dpt, int yos) {
        this.name = name;
        this.credits = credits;
        this.dpt = dpt;
        this.yos = yos;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCredits() {
        return credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

    public String getDpt() {
        return dpt;
    }

    public void setDpt(String dpt) {
        this.dpt = dpt;
    }

    public int getYos() {
        return yos;
    }

    public void setYos(int yos) {
        this.yos = yos;
    }
}
