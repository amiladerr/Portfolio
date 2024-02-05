#include <iostream>
#include <string>

using namespace std;

string commonChars(const string& s1, const string& s2){
    string newS = "";
    for (int i = 0; i < min(s1.length(), s2.length()); i++)
        if(s1.length() < s2.length()){
            if (s2.find(s1.at(i)) != string::npos)
                newS += s1.at(i);
        }
        else {
            if (s2.find(s1.at(i)) != string::npos)
                newS += s1.at(i);
        }
    return newS;
}
int main(){
    string s1, s2;
    cout << "Enter the first string: ";
    getline(cin, s1);
    cout << "Enter the second string: ";
    getline(cin, s2);

    if(commonChars(s1, s2) == "") cout << "No common characters" << endl;
    else cout << "The common characters are " << commonChars(s1, s2) << endl;
    return 0;
}
