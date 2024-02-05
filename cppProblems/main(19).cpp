#include <iostream>
#include "Account.h"

using namespace std;

void printMenu(){
    cout << "\nMain menu\n1: Check balance\n2: Withdraw\n3: Deposit\n4: exit\nEnter a choice: ";
}
int returnId(){
    int id = -1;
    while (id < 0 || id > 9){
            cout << "\nEnter an id: ";
            cin >> id;
        }
    return id;
}
int main()
{
    int id = -1, option;
    Account account[10];
    for (int i = 0; i < 10; i++){
        account[i].setId(i);
        account[i].setBalance(100);
    }
    id = returnId();
    while(1){
        printMenu();
        cin >> option;
        switch(option){
            case 1: cout << "\nThe balance is " << account[id].getBalance(); break;
            case 2: {
                    cout << "\nEnter an amount to withdraw: ";
                    double amount;
                    cin >> amount;
                    account[id].withdraw(amount); break;
                    }
            case 3: {
                    cout << "\nEnter an amount to deposit: ";
                    double amountD;
                    cin >> amountD;
                    account[id].deposit(amountD); break;
                    }
            case 4: id = returnId(); break;
        }
    }
    return 0;
}
