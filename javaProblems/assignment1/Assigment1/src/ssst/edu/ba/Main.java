package ssst.edu.ba;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        File employees = new File ("employees.txt");
        File managers = new File ("managers.txt");
        HashMap<String, ArrayList<Department>> departments = new HashMap<>();


        try{
            Scanner scanner = new Scanner(employees);
            while (scanner.hasNextLine()){
                String line = scanner.nextLine();
                String[] element = line.split(",");
                if (element.length == 4){
                    String firstName = element[0].trim();
                    String lastName = element[1].trim();
                    String department = element[2].trim();
                    double salaryMonthly = Double.parseDouble(element[3].trim());

                    Employees emp = new Employees(firstName, lastName, salaryMonthly);
                    if (departments.containsKey(department)) {
                        departments.get(department).add(emp);
                    }
                    else {
                        departments.put(department, new ArrayList<Department>());
                        departments.get(department).add(emp);
                    }
                }
            }

            System.out.println("Employees input completed!");

            Scanner scannerOne = new Scanner (managers);
            while(scannerOne.hasNextLine()){
                String line = scannerOne.nextLine();
                String[] elements = line.split(",");

                if (elements.length == 5){
                    String department = elements[0].trim();
                    String firstName = elements[1].trim();
                    String lastName = elements[2].trim();
                    double salaryMonthly = Double.parseDouble(elements[3].trim());
                    double bonusYearly = Double.parseDouble(elements[4].trim());

                    Managers man = new Managers(firstName, lastName, salaryMonthly, bonusYearly);

                    if (departments.containsKey(department)){
                        departments.get(department).add(man);
                    }
                    else {
                        departments.put(department, new ArrayList<Department>());
                        departments.get(department).add(man);
                    }

                }
            }
            System.out.println("Managers input completed!");

            for (Map.Entry<String, ArrayList<Department> > entry : departments.entrySet()){
                String key = entry.getKey();
                Double numOfPpl = 0.;
                Double  totMoney = 0.;
                Double bonusManger = 0.;
                Double  highestSalary = 0.;
                Double lowestSalary = Double.MAX_VALUE;
                ArrayList<Department> paidHighest = new ArrayList<>();
                ArrayList<Department> lowestPaid = new ArrayList<>();

                for (Department temp: entry.getValue()){
                    numOfPpl++;
                    totMoney = totMoney + temp.getSalaryMonthly();
                    if (highestSalary<temp.getSalaryMonthly()){
                        highestSalary = temp.getSalaryMonthly();
                        paidHighest.clear();
                        paidHighest.add(temp);
                    }
                    else if (highestSalary==temp.getSalaryMonthly()){
                        paidHighest.add(temp);
                    }
                    if (lowestSalary>temp.getSalaryMonthly()){
                        lowestSalary=temp.getSalaryMonthly();
                        lowestPaid.clear();
                        lowestPaid.add(temp);
                    }
                    else if (lowestSalary==temp.getSalaryMonthly()){
                        lowestPaid.add(temp);
                    }
                    Boolean itsManager = temp.getClass() == Managers.class;
                    if (itsManager){
                        bonusManger = bonusManger +((Managers)temp).getBonusYearly();
                    }
                }

                File newFile = new File(key);
                newFile.createNewFile();

                FileWriter writer = new FileWriter(newFile);
                writer.write("Department: "+ key + "\n");
                String mean = String.format("%.2f", totMoney/numOfPpl);
                writer.write("Average salary is:" + mean + "\n");
                writer.write("Total amount of money needed to pay all the salaries in the department(monthly):" + totMoney + "\n");
                writer.write("Total amount of money needed to pay all the salaries in the department(yearly): " + totMoney*12 + "\n");
                writer.write("Total yearly bonus for managers is: " + bonusManger + "\n");
                writer.write("The highest salary is:" + highestSalary + " the names of those with the highest salary are " + "\n");

                for(Department temp :  paidHighest){
                    writer.write(temp.getFirstName() + " " + temp.getLastName() + "\n");
                }
                writer.write("The lowest salaries are: " + lowestSalary + " the names of those with the lowest salaries are " + "\n");
                for (Department temp : lowestPaid){
                    writer.write(temp.getFirstName() + " " + temp.getLastName() + "\n");
                }
                writer.close();

            }
        }



        catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
