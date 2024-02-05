package ssst.edu.ba;

public class Managers extends Employees implements Department {
    private double bonusYearly;

    Managers (String firstName, String lastName, double salaryMonthly, double bonusYearly){
        super(firstName, lastName, salaryMonthly);
        if (bonusYearly<0.){
            throw new IllegalArgumentException("Yearly bonus can´t be less than 0");
        }
        this.bonusYearly=bonusYearly;
    }

    public double getBonusYearly() {
        return (super.getSalaryMonthly()*bonusYearly)/100;
    }
    @Override
    public String toString(){
        return super.toString() + "Yearly bonus: " + bonusYearly;
    }
}
