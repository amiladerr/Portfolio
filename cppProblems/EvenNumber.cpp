#include "EvenNumber.h"

using namespace std;

EvenNumber::EvenNumber(){
    value = 0;
}
EvenNumber::EvenNumber(int newValue){
    value = newValue;
}
int EvenNumber::getValue(){
    return value;
}
int EvenNumber::getNext(){
    return value + 2;
}
int EvenNumber::getPrevious(){
    return value - 2;
}
