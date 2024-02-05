#include "Stock.h"
#include <string>
#include <cmath>

using namespace std;

Stock::Stock(string newSymbol, string newName){
    symbol = newSymbol;
    name = newName;
}
string Stock::getSymbol()const{
    return symbol;
}
string Stock::getName()const{
    return name;
}
double Stock::getPreviousClosingPrice()const{
    return previousClosingPrice;
}
double Stock::getCurrentPrice()const{
    return currentPrice;
}
void Stock::setPreviousClosingPrice(double newPrice){
    previousClosingPrice = newPrice;
}
void Stock::setCurrentPrice(double newPrice){
    currentPrice = newPrice;
}
double Stock::getChangePercentage()const{
    double diff = abs(currentPrice - previousClosingPrice);
    return (diff / previousClosingPrice) * 100;
}
