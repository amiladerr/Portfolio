#include "StackOfIntegers.h"

using namespace std;

StackOfIntegers::StackOfIntegers(){
    n = 0;
}
bool StackOfIntegers::isEmpty() const{
    return n == 0;
}
int StackOfIntegers::peek() const{
    return elements[n-1];
}
void StackOfIntegers::push(int value){
    elements[n++] = value;
}
int StackOfIntegers::pop(){
    return elements[--n];
}
int StackOfIntegers::getSize() const{
    return n;
}

