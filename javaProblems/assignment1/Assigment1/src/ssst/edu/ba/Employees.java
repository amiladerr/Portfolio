package ssst.edu.ba;

public class Employees implements Department {
    private String firstName;
    private String lastName;
    private double salaryMonthly;

    Employees (String firstName, String lastName, double salaryMonthly){
        this.firstName =firstName;
        this.lastName = lastName;
        if (salaryMonthly<0.)
        {
            throw new IllegalArgumentException("Salary can´t be less than 0");
        }
        this.salaryMonthly = salaryMonthly;
    }

    @Override
    public String getFirstName() {
        return firstName;
    }

    @Override
    public String getLastName() {
        return lastName;
    }

    public double getSalaryMonthly() {
        return salaryMonthly;
    }

    @Override
    public String toString(){
        return firstName + " " + lastName + " ,monthly salary " + salaryMonthly;
    }
}
