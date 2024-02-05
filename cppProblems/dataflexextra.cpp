#include <iostream>

using namespace std;

class Collection {
  int capacity;
  double *data;
  int no_of_items;
  mutable int last_pos;                         // Only for SearchNext
  mutable double last_search;                   // Only for SearchNext
public:
  Collection(int cap) {
    no_of_items = 0; capacity = cap;
    data = new double[cap];
  }
  Collection(const Collection &c) {                             // Manually-written copy constructor
    capacity = c.capacity; no_of_items = c.no_of_items;         // which creates a deep copy
    data = new double[c.capacity];
    for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];   // data[i] is the same as this->date[i]
  }
  Collection &operator=(const Collection &c) {
    if(c.capacity > capacity || c.capacity < 0.8 * capacity) {  // If newsize is greater than oldsize or smaller than
      delete[] data;                                            //   80% of oldsize, do reallocation!
      data = new double[c.capacity];
    }                                                           // Note that self-assignment is not destructive anymore!
    capacity = c.capacity; no_of_items = c.no_of_items;
    for(int i = 0; i < no_of_items; i++) data[i] = c.data[i];
    return *this;
  }
  int GetNumberOfItems() const { return no_of_items; }
  ~Collection() { delete[] data; }                              // Destructor!
  double GetAverage() const;
  void Insert(double item);
  int SearchFirst(double item) const;                           // returns position of first appearance of item or 0 if not found
  int SearchNext() const;                                       // returns position of next apperance
  void InsertUnique(double item);                               // inserts item only if not already inserted
  double GetItem(int item_no) const;
  void ChangeItem(int item_no, double new_value);
  void EraseByPos(int item_no);                                 // erase item at position item_no
  void EraseByValue(double item);                               // erase first occurrence of item
  void EraseAllByValue(double item);                            // erase all occurrences of item
  void EraseByPosInOrder(int item_no);                          // as EraseByPos, but keeps order of items
  void EraseByValueInOrder(double item);                        // as EraseByValue, but keeps order of items
  void EraseAllByValueInOrder(double item);                     // as EraseAllByValue, but keeps order of items
  void DisplayAll() const;
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

int Collection::SearchFirst(double item) const {
  last_search = item;
  for(int i = 0; i < no_of_items; i++)
    if(data[i] == item) {
      last_pos = i + 1;
      return i + 1;
    }
  last_pos = 0;
  return 0;                                         // Not found
}

int Collection::SearchNext() const {
  for(int i = last_pos; i < no_of_items; i++)
    if(data[i] == last_search) {
      last_pos = i + 1;
      return i + 1;
    }
  last_pos = 0;
  return 0;                                         // Not found
}

void Collection::InsertUnique(double item) {
  if(SearchFirst(item) == 0) Insert(item);
}

double Collection::GetItem(int item_no) const {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item number!";
  return data[item_no - 1];
}

void Collection::ChangeItem(int item_no, double new_value) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item number!";
  data[item_no - 1] = new_value;
}

void Collection::EraseByPos(int item_no) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item number!";
  data[item_no - 1] = data[no_of_items - 1];
  no_of_items--;
}

void Collection::EraseByValue(double item) {
  int where_is = SearchFirst(item);
  if(where_is != 0) EraseByPos(where_is);
}

// This is short but tricky implementation
void Collection::EraseAllByValue(double item) {
  int where_is;
  while((where_is = SearchFirst(item)) != 0) EraseByPos(where_is);
}

/*
// This is longer but more clear implementation
void Collection::EraseAllByValue(double item) {
  int where_is = SearchFirst(item);
  while(where_is != 0) {
    EraseByPos(where_is);
    where_is = SearchFirst(item);
  }
}
*/


void Collection::EraseByPosInOrder(int item_no) {
  if(item_no < 1 || item_no > no_of_items) throw "Bad item number!";
  for(int i = item_no - 1; i < no_of_items - 1; i++)
    data[i] = data[i + 1];
  no_of_items--;
}

void Collection::EraseByValueInOrder(double item) {
  int where_is = SearchFirst(item);
  if(where_is != 0) EraseByPosInOrder(where_is);
}

void Collection::EraseAllByValueInOrder(double item) {
  int where_is;
  while((where_is = SearchFirst(item)) != 0) EraseByPosInOrder(where_is);
}

void Collection::DisplayAll() const {
  for(int i = 0; i < no_of_items; i++) cout << data[i] << " ";
  cout << endl;
}

int main() {
  Collection c(50);
  c.Insert(3);
  c.Insert(5);
  c.Insert(6);
  c.Insert(2);
  c.Insert(6);
  c.Insert(4);
  cout << c.SearchFirst(2) << endl;
  cout << c.SearchFirst(7) << endl;
  c.DisplayAll();
  c.InsertUnique(9);
  c.InsertUnique(3);
  c.Insert(6);
  c.DisplayAll();
  int where = c.SearchFirst(6);
  while(where != 0) {
    cout << "6 found at position " << where << endl;
    where = c.SearchNext();
  }
  c.EraseAllByValueInOrder(6);
  c.DisplayAll();
  return 0;
}
