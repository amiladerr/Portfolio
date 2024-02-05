#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string amount;
    cout << "Enter amount: ";
    cin >> amount;
    stringstream ss(amount);
    vector<string> tokens;
    string word;
    while (getline(ss, word, '.'))
        if (!word.empty()) tokens.push_back(word);

    string dollar1 = tokens[0];
    string cents1 = tokens[1];
    char dollar[dollar1.length()], cents[cents1.length()];
    for (int i = 0; i < dollar1.length(); i++) dollar[i] = dollar1.at(i);
    for (int i = 0; i < cents1.length(); i++) cents[i] = cents1.at(i);

    int numberOfOneDollars = atoi(dollar);
    int remainingAmount = atoi(cents);
    int numberOfQuarters = remainingAmount / 25;
    remainingAmount = remainingAmount % 25;
    int numberOfDimes = remainingAmount / 10;
    remainingAmount = remainingAmount % 10;
    int numberOfNickels = remainingAmount / 5;
    remainingAmount = remainingAmount % 5;
    int numberOfPennies = remainingAmount;

    cout << amount << " consists of:\n" << "- dollars: " << numberOfOneDollars << "\n- quarters: "
         << numberOfQuarters << "\n- dimes: " << numberOfDimes << "\n- nickels: " << numberOfNickels
         << "\n- pennies: " << numberOfPennies << endl;
    return 0;
}
