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
  int GetNumberOfItems() const { return no_of_items; }
  double GetAverage() const;
  void Insert(double item);
  double GetItem(int item_no) const;
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

double Collection::GetItem(int item_no) const {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}

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
  cout << c.GetItem(2) << endl;            // Displays 5
  c.ChangeItem(1, 5);
  cout << c.GetAverage() << endl;          // Displays 4
  cout << endl;

  Collection c2(c);                        // Something is strange:
  c2.ChangeItem(3, 10);                    // Shallow copy!!!
  cout << c.GetItem(3) << endl;
  cout << c2.GetItem(3) << endl;
  cout << c.GetAverage() << endl;
  cout << c2.GetAverage() << endl;
  return 0;
}
