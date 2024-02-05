#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s){
    string s1, s2;
    for (int i = 0; i < s.length(); i++)
        if (isalpha(s.at(i))) s1 += tolower(s.at(i));
    for (int i = s1.length()-1; i >= 0; i--)
        s2 += s1.at(i);

    if (s1 == s2) return true;
    else return false;
}
int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (isPalindrome(str)) cout << str << " is a palindrome" << endl;
    else cout << str << " is not a palindrome" << endl;
    return 0;
}
