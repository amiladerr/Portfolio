#include <iostream>

using namespace std;

char* capitalize(char *s){
    char* temp = s;
    while (*s != '\0'){
        while (!isalpha(*s)) s++;
        if (isalpha(*s)){
            *s = toupper(*s);
            s++;
            while (isalpha(*s)) s++;
        }
    }
    return temp;
}

int main(){
    char sentence[1000];
    cout << "Enter text: ";
    cin.getline(sentence, 1000, '\n');
    char* pSentence = sentence;
    pSentence = capitalize(pSentence);
    cout << sentence;
    return 0;
}
