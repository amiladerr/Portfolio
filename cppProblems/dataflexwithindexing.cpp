#include <iostream>

using namespace std;

class Collection {
  int capacity;
//  double data[capacity];   Unfortunately, this is not allowed!
  double *data;
  int no_of_items;
public:
  Collection(int cap) {
    no_of_items = 0; capacity = cap;
    data = new double[cap];
  }
  Collection(const Collection &c) {                            // Manually-written copy constructor
    capacity = c.capacity; no_of_items = c.no_of_items;        // which creates a deep copy
    data = new double[c.capacity];
    for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];  // data[i] is the same sd thid->date[i]
  }
  Collection &operator=(const Collection &c) {
    if(this != &c) {                                           // protection against descructive self-assignment
      delete[] data;
      capacity = c.capacity; no_of_items = c.no_of_items;
      data = new double[c.capacity];
      for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];
    }
    return *this;                                              // to suuport multiple assignments...
  }
  int GetNumberOfItems() const { return no_of_items; }
  ~Collection() { delete[] data; }                             // Destructor!
  double GetAverage() const;
  void Insert(double item);
  double &operator[](int item_no);                       // returning reference allows usage of [] on the left side
  double operator[](int item_no) const;                  //   of the assignment (=), but only for non-const objects!
  void ChangeItem(int item_no, double new_value);
};

double Collection::GetAverage() const {
  double sum = 0;
  for(int i = 0; i < no_of_items; i++) sum += data[i];
  return sum / no_of_items;
}

void Collection::Insert(double item) {
  if(no_of_items == capacity) throw "Collection is full!";
  data[no_of_items] = item;
  no_of_items++;
}

double &Collection::operator[](int item_no) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}

double Collection::operator[](int item_no) const {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}


// This function is now superfluous, because
// c.ChangaItem(p, q) is now equivalent to
// c[p] = q

void Collection::ChangeItem(int item_no, double new_value) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  data[item_no - 1] = new_value;
}

int main() {
  Collection c(50);
  c.Insert(3);
  c.Insert(5);
  c.Insert(2);
  cout << c.GetNumberOfItems() << endl;    // Displays 3
  cout << c.GetAverage() << endl;          // Displays 3.3333333
  cout << c[2] << endl;                    // Displays 5
  c[1] = 5;                                // This statement has the same effect as the following one...
  c.ChangeItem(1, 5);
  cout << c.GetAverage() << endl;          // Displays 4
  cout << endl;

  Collection c2(c);                        // Now, we have deep (full) copy!
  c2.ChangeItem(3, 10);
  cout << c[3] << endl;
  cout << c2[3] << endl;
  cout << c.GetAverage() << endl;
  cout << c2.GetAverage() << endl;

  Collection c3(100);
  cout << "Now, assignment:\n";
  c3 = c;

  c2 = c3 = c;                             // Multiple assignment works too...

  return 0;
}
