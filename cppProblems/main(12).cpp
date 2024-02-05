#include <iostream>
#include <string>

using namespace std;

int main()
{
    string words[] = {"that", "program"};
    string chosen = words[1];
    char user[chosen.length()], real[chosen.length()];
    for (int i = 0; i < chosen.length(); i++){
        user[i] = '*';
        real[i] = chosen.at(i);
    }
    int cnt = 0, cntMisses = 0;
    while (cnt != chosen.length()){
        cout << "Enter a letter in word ";
        for (int i = 0; i < chosen.length(); i++) cout << user[i];
        cout << " --> ";
        char guess;
        cin >> guess;
        bool in = false;
        for (int i = 0; i < chosen.length(); i++){
            if (real[i] == guess){
                if (user[i] == guess){ cout << guess << " is already in the word" << endl; in = true; cntMisses++; break;}
                else {user[i] = guess; cnt++;}
                in = true;
            }
        }
        if (!in){ cout << guess << " is not in the word" << endl; cntMisses++;}
    }
    cout << "You misses: " << cntMisses << " times" << endl;
    return 0;
}
