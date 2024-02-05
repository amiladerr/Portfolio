#include <iostream>
#include <string>

using namespace std;

class Student {
  string name;
  int index;
public:
  Student(string name1, int index1) { name = name1; index = index1; }
  string GetName() const { return name; }
  int GetIndex() const { return index; }
  virtual void Display() const {
    cout << "Name: " << name << endl << "Index: " << index << endl;
  }
};                                          //   (otherwise, the wrong destructor will be called sometimes)

class StudentMaster : public Student {
  int year_of_graduation;
public:
  StudentMaster(string name1, int index1, int yog) : Student(name1, index1) {
    year_of_graduation = yog;
  }
  int GetYearOfGraduation() const { return year_of_graduation; }
  virtual void Display() const {
    cout << "Name: " << GetName() << endl << "Index: " << GetIndex() << endl
      << "Year of graduation: " << year_of_graduation << endl;
  }
};


int main() {
  Student s1("Maid Mulabegovic", 1234);
  s1.Display();
  StudentMaster s2("Hana Lihovac", 4321, 2022);
  cout << s2.GetName() << endl;
  cout << s2.GetYearOfGraduation() << endl;
  s2.Display();
  s2.Student::Display();

  Student s3 = s2;
  s3.Display();

//  StudentMaster s4 = s1;  (possible only if StudentMaster has constructor with one parameter of type Student


  Student *ps;
  int x;
  cin >> x;
  if(x == 1) ps = &s1;
  else ps = &s2;
  ps->Display();  // Does ps points to an instance of Student or StudentMaster???

  Student &rs1 = s1;
  Student &rs2 = s2;

  rs2.Display();
}

