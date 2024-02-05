#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

void DisplayVector(vector<int> v) {
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

vector<int> MultiplyVectorByNumber(vector<int> v, int num) {
  vector<int> v2(v.size());
  for(int i = 0; i < v.size(); i++) v2[i] = v[i] * num;
  return v2;
}

// Vector is a flexible alternative for arrays (support much more operations)

void VectorDemo() {
  vector<int> v1(10), v2(5), v3, v4;                     // v3 and v4 are initially zero-size
  for(int i = 0; i < 10; i++) v1[i] = 10 + i * i;
  DisplayVector(v1);
  v2 = MultiplyVectorByNumber(v1, 5);
  DisplayVector(v2);
  v3 = v1;
  if(v1 == v3) cout << "Equal\n";
  v2.resize(20);                                // Chante the capatity...
  DisplayVector(v2);
  v2.resize(5);
  DisplayVector(v2);
  v2.push_back(100);
  v2.push_back(1000);
  DisplayVector(v2);
  v2.insert(v2.begin() + 3, 5555);              // Can be slow if vector is big
  DisplayVector(v2);
  v2.erase(v2.begin() + 5);                     // Can be slow too...
  DisplayVector(v2);
  vector<int>::iterator it;                     // Something very simpliar to the pointer which points to the elements of the vector
  for(it = v1.begin(); it != v1.end(); it++)
    cout << *it << " ";
  cout << endl;
}

// Deque is very similar to vector. It supports everything which is supported in vector, with following differences:
//
// Advantages:
//
// - It supports push_front which is very fast (unlike insert)
// - For vectors, push_back can sometimes move elements in the memory which can make their addresses invalid (if they are taken
//   before and stored in pointers). For deques, both pudh_front and puhh_back will never move nothing
//
// Disadvangates:
//
// - Operations witn deques are few times slower than with vectors (including indexing)
//
// Neither disadvantage nor advantage
//
// - You must use iterators with working with deque instead of ordinary pointers. Namely, elements of the deque are not always
//   stored continuously in memory. Ordinary pointers can not track such discontinuities, but iterators can

void DequeDemo() {
  deque<int> d;
  for(int i = 1; i <= 5; i++) d.push_back(i);
  for(int i = 6; i <= 10; i++) d.push_front(i);
  for(int i = 0; i < d.size(); i++) cout << d[i] << " ";
  cout << endl;
  deque<int>::iterator it;
  for(it = d.begin(); it != d.end(); it++)
    cout << *it << " ";
  cout << endl;
}

// List is simpilar with deque, but with foolowing differences:
//
// Advantage: Insert and erase works extremely fast at arbitrary place
// Disadvantage: Indexing does not work, everyting must be done with iterators. Moreover, iterarors for list does not support
// arbitrary aritmetics, only ++ and --

void ListDemo() {
  list<int> l;
  for(int i = 1; i <= 5; i++) l.push_back(i);
  for(int i = 6; i <= 10; i++) l.push_front(i);
  list<int>::iterator it;
  for(it = l.begin(); it != l.end(); it++)
    cout << *it << " ";
  cout << endl;
  it = l.begin();
  it++; it++; it++;
  l.insert(it, 100);                // l.insert(l.begin() + 3, 100); will not work (+ is not supported)
  it++; it++;
  l.erase(it);
  for(it = l.begin(); it != l.end(); it++)
    cout << *it << " ";
  cout << endl;
}

// Set supprts very fast inserting, erasing and searching, but elements have no position: they are simply in the set, at no
// oarticular position. Internally, elements of set are always sortet. push_back and push_front are meainingless. insert requires
// only the element, not the position. Erase also requires slements. Adding elements more than once is ignored.
// Inserting, erasing and searching is very fast

void SetDemo() {
  set<int> s;
  s.insert(3); s.insert(2); s.insert(8); s.insert(4); s.insert(2); s.insert(7); s.insert(4);
  set<int>::iterator it;
  for(it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  s.erase(7);
  for(it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  if(s.count(9) != 0) cout << "9 is in the set\n";
  else cout << "9 is not in the set\n";
}

// Multiset is very similar to the set, bud the multiplicity of the same element is possible

void MultisetDemo() {
  multiset<int> s;
  s.insert(3); s.insert(2); s.insert(8); s.insert(4); s.insert(2); s.insert(7); s.insert(4);
  set<int>::iterator it;
  for(it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  s.erase(7);
  for(it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  if(s.count(9) != 0) cout << "9 is in the set\n";
  else cout << "9 is not in the set\n";
  cout << "4 is stored " << s.count(4) << " times\n";
}

// Map allows storing pairs key-value and effective searching using the key

void MapDemo() {
  map<string, int> inhabitans;
  inhabitans["Sarajevo"] = 400000;
  inhabitans["Banja Luka"] = 280000;
  inhabitans["Mostar"] = 100000;
  inhabitans["Tuzla"] = 120000;
  inhabitans["Bihac"] = 50000;
  cout << inhabitans["Tuzla"] << endl;
  map<string, int>::iterator it;
  for(it = inhabitans.begin(); it != inhabitans.end(); it++)
    cout << it->first << " " << it->second << endl;                 // first is the key, second is the associated value
  it = inhabitans.find("Capljina");
  if(it == inhabitans.end()) cout << "No data avaliable\n";
  else cout << it->second << endl;
  it = inhabitans.find("Tuzla");
  if(it == inhabitans.end()) cout << "No data avaliable\n";
  else cout << it->second << endl;
  map<string, string> dictionary;
  dictionary["Apple"] = "Jabuka";
  dictionary["Hand"] = "Ruka";
  cout << dictionary["Apple"] << endl;
}


int main() {
//  VectorDemo();
//  DequeDemo();
//  ListDemo();
//  SetDemo();
//  MultisetDemo();
//  MapDemo();
  return 0;
}
