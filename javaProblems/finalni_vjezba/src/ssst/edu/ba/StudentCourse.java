package ssst.edu.ba;

public class StudentCourse {
    private Student studentName;
    private Course courseName;
    private int score;

    public StudentCourse(Student studentName, Course courseName, int score) {
        this.studentName = studentName;
        this.courseName = courseName;
        this.score = score;
    }

    public Student getStudentName() {
        return studentName;
    }

    public void setStudentName(Student studentName) {
        this.studentName = studentName;
    }

    public Course getCourseName() {
        return courseName;
    }

    public void setCourseName(Course courseName) {
        this.courseName = courseName;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
