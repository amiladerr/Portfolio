#include "Loan.h"
#include <cmath>

using namespace std;

Loan::Loan(){
    annualInterestRate = 9.5;
    years = 30;
    loanAmount = 100000;
}
Loan::Loan(double rate, int year, double amount){
    annualInterestRate = rate;
    years = year;
    loanAmount = amount;
}
double Loan::getAnnualInterestRate(){
    return annualInterestRate;
}
int Loan::getNumberOfYears(){
    return years;
}
double Loan::getLoanAmount(){
    return loanAmount;
}
void Loan::setAnnualInterestRate(double newRate){
    annualInterestRate = newRate;
}
void Loan::setNumberOfYears(int year){
    years = year;
}
void Loan::setLoanAmount(double amount){
    loanAmount = amount;
}
double Loan::getMonthlyPayment(){
    double monthlyInterestRate = annualInterestRate / 1200;
    return loanAmount * monthlyInterestRate / (1 - (pow(1/(1+monthlyInterestRate), years * 12)));
}
double Loan::getTotalPayment(){
    return getMonthlyPayment() * years * 12;
}
double Loan::getMonthlyPayment(double rate, int n, double amount){
    double monthlyInterestRate = rate / 1200;
    return amount * monthlyInterestRate / (1 - (pow(1/(1+monthlyInterestRate), n * 12)));
}
double Loan::getTotalPayment(double rate, int year, double amount){
    return getMonthlyPayment(rate, year, amount) * year * 12;
}
