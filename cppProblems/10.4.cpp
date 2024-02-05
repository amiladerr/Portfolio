#include <iostream>
#include <string>

using namespace std;

string Sort(string& s){

   for (int i = 1; i < s.length(); i++){
    bool swap_performed = false;
    for (int j = 0; j < s.length()-i; j++)
        if (s.at(j) > s.at(j+1)){
            swap(s.at(j), s.at(j+1));
            swap_performed = true;
        }
        if(!swap_performed)break;
   }
   return s;
}
int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "The sorted string is " << Sort(str);
    return 0;
}
