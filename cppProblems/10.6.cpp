#include <iostream>
#include <string>

using namespace std;

int countVowels (const string& s){
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (tolower(s.at(i)) == 'a' || tolower(s.at(i)) == 'e' || tolower(s.at(i)) == 'i' || tolower(s.at(i)) == 'o' || tolower(s.at(i)) == 'u') cnt++;
    return cnt;
}
int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Number of vowels in the string is " << countVowels(s) << endl;
    return 0;
}
