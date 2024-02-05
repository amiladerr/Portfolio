#include <iostream>

using namespace std;

template <typename SomeType>
class Collection {
  int capacity;
//  double data[capacity];   Unfortunately, this is not allowed!
  SomeType *data;
  int no_of_items;
public:
  Collection(int cap) {
    no_of_items = 0; capacity = cap;
    data = new SomeType[cap];
  }
  Collection(const Collection &c) {                            // Manually-written copy constructor
    capacity = c.capacity; no_of_items = c.no_of_items;        // which creates a deep copy
    data = new SomeType[c.capacity];
    for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];  // data[i] is the same sd thid->date[i]
  }
  Collection &operator=(const Collection &c) {
    if(this != &c) {                                           // protection against descructive self-assignment
      delete[] data;
      capacity = c.capacity; no_of_items = c.no_of_items;
      data = new SomeType[c.capacity];
      for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];
    }
    return *this;                                              // to suuport multiple assignments...
  }
  int GetNumberOfItems() const { return no_of_items; }
  ~Collection() { delete[] data; }                             // Destructor!
  double GetAverage() const;
  void Insert(SomeType item);
  SomeType operator [](int item_no) const;
  SomeType &operator [](int item_no);
  void ChangeItem(int item_no, SomeType new_value);
  void DisplayAll() { for(int i = 0; i < no_of_items; i++) cout << data[i] << endl; }
};

template <typename SomeType>
double Collection<SomeType>::GetAverage() const {
  double sum = 0;
  for(int i = 0; i < no_of_items; i++) sum += data[i];
  return sum / no_of_items;
}

template <typename SomeType>
void Collection<SomeType>::Insert(SomeType item) {
  if(no_of_items == capacity) throw "Collection is full!";
  data[no_of_items] = item;
  no_of_items++;
}

template <typename SomeType>
SomeType Collection<SomeType>::operator [](int item_no) const {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}

template <typename SomeType>
SomeType &Collection<SomeType>::operator [](int item_no) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}

template <typename SomeType>
void Collection<SomeType>::ChangeItem(int item_no, SomeType new_value) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  data[item_no - 1] = new_value;
}

int main() {
  Collection<double> c(50);
  c.Insert(3);
  c.Insert(5);
  c.Insert(2);
  cout << c.GetNumberOfItems() << endl;    // Displays 3
  cout << c.GetAverage() << endl;          // Displays 3.3333333
  cout << c[2] << endl;            // Displays 5
  c[1] = 5;
  cout << c.GetAverage() << endl;          // Displays 4
  cout << endl;

  Collection<double> c2(c);                        // Now, we have deep (full) copy!
  c2[3] = 10;
  cout << c[3] << endl;
  cout << c2[3] << endl;
  cout << c.GetAverage() << endl;
  cout << c2.GetAverage() << endl;

  Collection<string> students(10);
  students.Insert("Abdulah");
  students.Insert("Salih");
  students.Insert("Amel");
  students.DisplayAll();
  cout << students.GetAverage() << endl;
  return 0;
}
