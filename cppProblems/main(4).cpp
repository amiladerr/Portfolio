#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account account;
    account.setId(1122);
    account.setBalance(20000);
    account.setAnnualInterestRate(4.5);
    account.withdraw(2500);
    account.deposit(3000);
    cout << "Balance: " << account.getBalance() << "\nMonthly interest rate: " << account.getMonthlyInterest() << endl;
    return 0;
}
