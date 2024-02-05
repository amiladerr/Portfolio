package ssst.edu.ba;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Main {
    static HashMap<String, ArrayList<StudentCourse>> AddToList(String student, StudentCourse sc, HashMap<String, ArrayList<StudentCourse>> HM) {
        ArrayList<StudentCourse> kursevi = HM.get(student);
        if (kursevi == null) {
            ArrayList<StudentCourse> course = new ArrayList<>();
            course.add(sc);
            HM.put(student, course);
        } else
            kursevi.add(sc);
        return HM;
    }

    public static void main(String[] args) {
        ArrayList<Course> courseArrayList = new ArrayList<>();
        ArrayList<Student> studentArrayList = new ArrayList<>();
        ArrayList<StudentCourse> studentCourseArrayList = new ArrayList<>();
        try {
            File file = new File("courses.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String namLine = scanner.nextLine();
                String[] split = namLine.split(",");
                if (split.length == 4) {
                    String nameCourse = split[0].trim();
                    int credits = Integer.parseInt(split[1].trim());
                    String dpt = split[2].trim();
                    int yos = Integer.parseInt(split[3].trim());
                    Course c = new Course(nameCourse, credits, dpt, yos);
                    courseArrayList.add(c);
                }
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        try {
            File file = new File("students.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String nameLine = scanner.nextLine();
                String[] split = nameLine.split(",");
                if (split.length == 3) {
                    String name = split[0].trim();
                    String dpt = split[1].trim();
                    int yos = Integer.parseInt(split[2].trim());
                    Student s = new Student(name, dpt, yos);
                    studentArrayList.add(s);
                }
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        try {
            File file = new File("student_courses.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String nameLine = scanner.nextLine();
                String[] split = nameLine.split(",");
                if (split.length == 3) {
                    Student s1 = null;
                    Course c1 = null;
                    String studentName = split[0].trim();
                    String course = split[1].trim();
                    int score = Integer.parseInt(split[2].trim());
                    for (Student s : studentArrayList) {
                        if (studentName.equals(s.getFlName()))
                            s1 = s;
                    }
                    for (Course c : courseArrayList) {
                        if (course.equals(c.getDpt()))
                            c1 = c;
                    }
                    StudentCourse sc = new StudentCourse(s1, c1, score);
                    studentCourseArrayList.add(sc);
                }
            }
            scanner.close();
        } catch (Exception e) {
            System.out.println("Exception " + e);
        }
        HashMap<String, ArrayList<StudentCourse>> HM = new HashMap<>();
        for (StudentCourse sc : studentCourseArrayList) {
            System.out.println("test");
            HM = AddToList(sc.getStudentName().getFlName(), sc, HM);
        }
        ArrayList<Integer> bestStudents = new ArrayList<>();
        ArrayList<Student> passingStudent = new ArrayList<>();
        ArrayList<Student> failedStudent = new ArrayList<>();
        int max = 0;
        for (Map.Entry m : HM.entrySet()) {
            System.out.println("test");
            Student s2 = null;
            int sum = 0;
            int cnt = 0;
            boolean passed = true;
            for (StudentCourse sc1 : HM.get(m.getKey())) {
                s2 = sc1.getStudentName();
                sum += sc1.getScore();
                cnt++;
                if (sc1.getScore() < 51) {
                    passed = false;
                }

            }
            bestStudents.add(sum / cnt);
            if (passed == true) {
                passingStudent.add(s2);
            }
            else failedStudent.add(s2);
        }
        Collections.sort(bestStudents);
        Collections.reverse(bestStudents);
        BufferedWriter bw = null;
        for (int ocjena : bestStudents) {
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("ocjene.txt", true));
                String jeste = String.valueOf(ocjena) + System.lineSeparator();
                writer.append(jeste);
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        for (Student s : passingStudent) {
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("prosli.txt", true));
                String jeste = String.valueOf(s.getFlName()) + System.lineSeparator();
                writer.append(jeste);
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        for (Student s : failedStudent) {
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("pali.txt", true));
                String jeste = String.valueOf(s.getFlName()) + System.lineSeparator();
                writer.append(jeste);
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
