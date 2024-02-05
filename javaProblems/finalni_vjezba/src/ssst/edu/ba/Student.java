package ssst.edu.ba;

public class Student {
    private String flName;
    private String dpt;
    private int yos;

    public Student(String flName, String dpt, int yos) {
        this.flName = flName;
        this.dpt = dpt;
        this.yos = yos;
    }

    public String getFlName() {
        return flName;
    }

    public void setFlName(String flName) {
        this.flName = flName;
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
