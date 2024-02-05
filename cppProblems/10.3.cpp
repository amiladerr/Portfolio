#include <iostream>
#include <string>

using namespace std;
int returnMin (int num1, int num2, int num3){
    if (num1 < num2 && num1 < num3) return num1;
    else if (num2 < num1 && num2 < num3) return num2;
    else return num3;
}
int main(){
    string genome;
    cout << "Enter a genome string: ";
    cin >> genome;

    bool isOutput = false;
    int i = 0;
    while (i < genome.length()){
        int startPosition, endPosition;
        if (genome.find("AGT") == string::npos)break;
        else startPosition = genome.find("ATG");
        int position1 = 100, position2 = 100, position3 = 100;
        if (genome.find("TAG") != string::npos) position1 = genome.find("TAG");
        if (genome.find("TAA") != string::npos) position2 = genome.find("TAA");
        if (genome.find("TGA") != string::npos) position3 = genome.find("TGA");
        endPosition = returnMin(position1, position2, position3);
        string newS = "";
        for (int i = startPosition+3; i < endPosition; i++) newS += genome.at(i);
        if (newS != "" && newS.find("ATG") == string::npos && newS.find("TAG") == string::npos && newS.find("TAA") == string::npos && newS.find("TGA") == string::npos){
            cout << newS << endl;
            isOutput = true;
        }
        genome.erase(0, endPosition+3);
        i++;
   }
    if(!isOutput) cout << "No gene is found" << endl;
    return 0;
}
