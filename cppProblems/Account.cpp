#include "Account.h"

using namespace std;

Account::Account(){
    id = 0;
    balance = 0;
    annualInterestRate = 0;
}
int Account::getId(){
    return id;
}
double Account::getBalance(){
    return balance;
}
double Account::getAnnualInterestRate(){
    return annualInterestRate;
}
void Account::setId(int newId){
    id = newId;
}
void Account::setBalance(double newBalance){
    balance = newBalance;
}
void Account::setAnnualInterestRate(double rate){
    annualInterestRate = rate;
}
double Account::getMonthlyInterest(){
    return annualInterestRate / 1200;
}
void Account::withdraw(double amount){
    if (balance >= amount) balance -= amount;
    else return;
}
void Account::deposit(double amount){
    balance += amount;
}
