#include <iostream>
#include <string>

using namespace std;

bool isAnagram(const string& s1, const string& s2){
    if (s1.length() != s2.length()) return false;
    else {
        for (int i = 0; i < s1.length(); i++)
            if(s2.find(s1.at(i)) == string::npos) return false;
    }
    return true;
}
int main(){
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if(isAnagram(s1, s2)) cout << s1 << " and " << s2 << " are anagrams" << endl;
    else  cout << s1 << " and " << s2 << " are not anagrams" << endl;

    return 0;
}
