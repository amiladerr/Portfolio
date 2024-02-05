#include "MyInteger.h"
#include <string>

using namespace std;

MyInteger::MyInteger(int newValue){
    value = newValue;
}
int MyInteger::getValue() const{
    return value;
}
bool MyInteger::isEven() const{
    if (value % 2 == 0) return true;
    return false;
}
bool MyInteger::isOdd() const{
    if (value % 2 != 0) return true;
    return false;
}
bool MyInteger::isPrime() const{
    for (int i = 2; i < value; i++)
        if (value % i == 0) return false;
    return true;
}
bool MyInteger::isEven(int newValue){
    if(newValue % 2 == 0) return true;
    return false;
}
bool MyInteger::isOdd(int newValue){
    if(newValue % 2 != 0) return true;
    return false;
}
bool MyInteger::isPrime(int newValue){
    for (int i = 2; i < newValue; i++)
        if (newValue % i == 0) return false;
    return true;
}
bool MyInteger::isEven(const MyInteger& object){
    if (object.getValue() % 2 == 0) return true;
    return false;
}
bool MyInteger::isOdd(const MyInteger& object){
    if (object.getValue() % 2 != 0) return true;
    return false;
}
bool MyInteger::isPrime(const MyInteger& object){
    for (int i = 2; i < object.getValue(); i++)
        if (object.getValue() % i == 0) return false;
    return true;
}
bool MyInteger::equals(int newValue) const{
    return (value == newValue);
}
bool MyInteger::equals(const MyInteger& object) const{
    return (value == object.getValue());
}
int MyInteger::parseInt(const string& s){
    char c[s.length()];
    for (int i = 0; i < s.length(); i++)
        c[i] = s.at(i);
    return atoi(c);
}
