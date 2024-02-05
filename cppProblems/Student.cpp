#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Student{
    string name, surname;
    int id, yearOfStudy, grades[10];
public:
    Student(string newName, string newSurname, int newId){
        if (newId <= 0) throw domain_error("Id cannot be zero or negative!");
        name = newName;surname = newSurname; id = newId;
        yearOfStudy = 1;
        for (int i = 0; i < 10; i++) grades[i] = 1;
    }
    string getName() const { return name; }
    string getSurname() const { return surname; }
    int getId() const { return id; }
    int getYearOfStudy() const { return yearOfStudy; }
    void setGrade(int course, int grade){
        if (course < 1 || course > 10 || grade < 1 || grade > 5)
            throw domain_error("Invalid values.");
        grades[--course] = grade;
    }
    int getGradeByCourse(int course)const{
        if (course < 1 || course > 10) throw domain_error("Invalid course value.");
        return grades[--course];
    }
    bool isAbleToPass() const{
        int fail = 0;
        for (int i = 0; i < 10; i++)
            if (grades[i] == 1) fail++;
        return fail <= 1;
    }
    double getAverage() const{
        int sum = 0, fail = 0;
        for (int i = 0; i < 10; i++)
            if (grades[i] != 1) sum += grades[i];
            else fail++;

        if(10 - fail == 0) return 1;
        else return (double)sum / (10 - fail);
    }
    void nextYear(){
        yearOfStudy++;
        for (int i = 0; i < 10; i++) grades[i] = 1;
    }
    void Display() const{
        cout << "Student: " << name << " " << surname
             << "\nIndex No: " << id
             << "\nYear of study: " << yearOfStudy
             << "Grades by course number: " << endl;
        for (int i = 0; i < 10; i++) cout << i + 1 << ": " << grades[i] << endl;
        cout << "Average: " << getAverage()
             << "Pass: ";
        if (isAbleToPass()==0) cout << "NO";
        else cout << "YES";
    }
};

int main(){
    Student s("Pero", "Peric", 1234);
    s.setGrade(3, 4); s.setGrade(5, 2); s.setGrade(8, 5);
    s.Display();
    return 0;
}
