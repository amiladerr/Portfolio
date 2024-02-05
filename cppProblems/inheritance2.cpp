#include <iostream>
#include <string>
#include <memory>               // For smart pointers (requires C++11, otherwise delete this include)

using namespace std;

class Student {
  string name;
  int index;
public:
  Student(string name1, int index1) { name = name1; index = index1; }
  string GetName() const { return name; }
  int GetIndex() const { return index; }
  void DisplayNonvirtual() {
    cout << "Name: " << name << " Index: " << index << endl;
  }
  virtual void DisplayVirtual() {
    cout << "Name: " << name << " Index: " << index << endl;
  }
  virtual ~Student() {}                     // Virtual destructor is ALWAYS needed if we want to use polymorphism...
};                                          //   (otherwise, the wrong destructor will be called sometimes)

class StudentMaster : public Student {
  int year_of_graduation;
public:
  StudentMaster(string name1, int index1, int yog) : Student(name1, index1) {
    year_of_graduation = yog;
  }
  int GetYearOfGraduation() const { return year_of_graduation; }
  void DisplayNonvirtual() {

    // cout << "Name: " << GetName() << " " << "Index: " << GetIndex() << endl;
    // if you want to du this, you must use getters (name & index are private!)

    Student::DisplayNonvirtual();
    cout << "Year of graduation: " << year_of_graduation << endl;
  }
  void DisplayVirtual() {       // Keyword virutal is not necessary here (once virtual, always virtaul)
    Student::DisplayVirtual();
    cout << "Year of graduation: " << year_of_graduation << endl;
  }

};

void fun1(Student &s) {         // s is now polymorhnic (it can be Student or StudentMaster, which depends of the
  s.DisplayNonvirtual();        // actual argument passed to fun1
  s.DisplayVirtual();
}

void fun2(Student s) {          // s in NOT polymorpic (it is ALWAYS a Student)
  s.DisplayNonvirtual();
  s.DisplayVirtual();        // no difference...
}

int main() {
  Student s1("Maid Mulabegovic", 1234);
  Student s2("Maida Filipovic", 4132);
  StudentMaster s3("Dzenita Djulovic", 3124, 2016);
  fun1(s3);
  fun2(s3);


  Student *ps;
  ps = new Student("Nedim Ajdin", 3321);
  ps->DisplayNonvirtual();
  ps->DisplayVirtual();                                         // no difference...
  delete ps;                                                    // withozt delete, we will have memory leak
  ps = new StudentMaster("Mujo Cetin", 1123, 2009);             //   (the alternative is usage of smart pointers)
  ps->DisplayNonvirtual();
  ps->DisplayVirtual();
  delete ps;                                                    // If destructor is not virtual, wrong destructor


  StudentMaster *psm;                                           //   is called here (from Student, not from StudentMaster)
  psm = new StudentMaster("Muamer Hasimbegovic", 3322, 2011);
  psm->DisplayNonvirtual();
  psm->DisplayVirtual();
  delete psm;

  Student *niz[5];
  niz[0] = new Student("Sarah Kajevic", 2121);
  niz[1] = new Student("Amna Dziho", 3113);
  niz[2] = new StudentMaster("Dina Bijelonja", 4123, 2014);
  niz[3] = new Student("Merjem Poplata", 4433);
  niz[4] = new StudentMaster("Eldar Doslic", 3342, 2015);
  cout << "----------------\n";
  for(int i = 0; i < 5; i++)
    niz[i]->DisplayNonvirtual();
  cout << "----------------\n";
  for(int i = 0; i < 5; i++)
    niz[i]->DisplayVirtual();
  cout << "----------------\n";
  for(int i = 0; i < 5; i++)
    delete niz[i];                                              // Don't forget

  // Example with smart pointers
  // You must be in C++11 mode to compile this
  // Otherwise, delete the next example

  shared_ptr<Student> sp;                                       // Smart pointer...
  sp = make_shared<Student>("Salih Music", 1112);              // make_shares is amart replacement for new...
  sp->DisplayNonvirtual();

}

