#include <iostream>
#include <iomanip>
#include "Loan.h"

using namespace std;

int main()
{
    double rate, amount;
    int years;
    cout << "Enter yearly interest rate, number of years and loan amount: ";
    cin >> rate >> years >> amount;
    Loan loan;
    cout << fixed << setprecision(2) << "The monthly payment is: " << loan.getMonthlyPayment(rate, years, amount) << endl
         << "The total payment is " << loan.getTotalPayment(rate, years, amount) << endl;
    return 0;
}
