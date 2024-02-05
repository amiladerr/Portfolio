#include <iostream>
#include <string>

using namespace std;

struct StudentData {
  int index;
  string name;
};

class Collection {
  int capacity;
  StudentData *data;
  int no_of_items;
public:
  Collection(int cap) {
    no_of_items = 0; capacity = cap;
    data = new StudentData[cap];
  }
  Collection(const Collection &c) {
    capacity = c.capacity; no_of_items = c.no_of_items;
    data = new StudentData[c.capacity];
    for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];
  }
  ~Collection() { delete[] data; }
  Collection &operator=(const Collection &c) {
    if(this != &c) {
      delete[] data;
      data = new StudentData[c.capacity];
      capacity = c.capacity; no_of_items = c.no_of_items;
      for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];
    }
    return *this;
  }
  int GetNumberOfItems() const { return no_of_items; }
  void Insert(StudentData item);
  void Insert(int index, string name);
  StudentData GetItem(int item_no) const;
  void ChangeItem(int item_no, StudentData new_data);
  void ChangeItem(int item_no, int new_index, string new_name);
  void DisplayAll() const;
  int FindPosition(int index) const;
  string GetNameByIndex(int index) const;
  void ChangeNameByIndex(int index, string new_name);
};

void Collection::Insert(StudentData item) {
  if(no_of_items == capacity) throw "Collection is full!";
  data[no_of_items] = item;
  no_of_items++;
}

void Collection::Insert(int index, string name) {
  StudentData item;
  item.index = index; item.name = name;
  Insert(item);
}

StudentData Collection::GetItem(int item_no) const {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  return data[item_no - 1];
}

void Collection::ChangeItem(int item_no, StudentData new_data) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item!";
  data[item_no - 1] = new_data;
}

void Collection::ChangeItem(int item_no, int new_index, string new_name) {
  StudentData new_data;
  new_data.index = new_index; new_data.name = new_name;
  ChangeItem(item_no, new_data);
}

void Collection::DisplayAll() const {
  for(int i = 0; i < no_of_items; i++)
    cout << data[i].index << ": " << data[i].name << endl;
}

int Collection::FindPosition(int index) const {
  for(int i = 0; i < no_of_items; i++)
    if(data[i].index == index) return i + 1;
  throw "Not found!";
}

/*

// Manual implementation...

string Collection::GetNameByIndex(int index) const {
  for(int i = 0; i < no_of_items; i++)
    if(data[i].index == index) return data[i].name;
  throw "Not found!";
}

*/

// Elegant implementation...

string Collection::GetNameByIndex(int index) const {
  return GetItem(FindPosition(index)).name;
}

// Elegant implementation...

void Collection::ChangeNameByIndex(int index, string new_name) {
  ChangeItem(FindPosition(index), index, new_name);
}

/*

// Manual implementation...

void Collection::ChangeNameByIndex(int index, string new_name) {
  for(int i = 0; i < no_of_items; i++)
    if(data[i].index == index) {
      data[i].name = new_name;
      return;
    }
  throw "Not found!";
}

*/

int main() {
  Collection c(10);
  c.Insert(1234, "Djenita Djulovic");
  c.Insert(2341, "Sarah Kajevic");

  StudentData sd;
  sd.index = 3412; sd.name = "Amna Dziho";
  c.Insert(sd);

  c.DisplayAll();
  cout << endl;

  cout << c.GetItem(2).index << endl;
  cout << c.GetItem(2).name << endl;
  cout << endl;

  cout << c.GetItem(c.FindPosition(3412)).name << endl;
  cout << c.GetNameByIndex(3412) << endl;
  cout << endl;

  cout << c.GetNameByIndex(1234) << endl;
  c.ChangeNameByIndex(1234, "Dzenita Djulovic");
  cout << c.GetNameByIndex(1234) << endl;



  return 0;
}
