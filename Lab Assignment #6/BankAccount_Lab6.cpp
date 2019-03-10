#include <iostream>
#include "BankAccount_Lab6.hpp"
#include "Person_Lab6.hpp"
using namespace std;


//function definitions for BankAccount class
BankAccount :: BankAccount() {
};
BankAccount :: BankAccount(string initLastName, string initFirstName, double initBalance)
{
        person.lastName = initLastName;
        person.firstName = initFirstName;
        balance = initBalance;
};

BankAccount :: ~BankAccount() {
};

void BankAccount :: setName(string newLastName, string newFirstName)
{
        person.lastName = newLastName;
        person.firstName = newFirstName;
}
void BankAccount :: getName() const {
        cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;
}
void BankAccount :: getAccID() const {
        cout << "Account ID: " << accID << endl;
}

void BankAccount :: getBalance() const {
        cout << "Account Balance: $" << balance << endl;
}
void BankAccount :: deposit(int depositValue) {
        //balance += depositValue;
        cout << "'This output was hardcoded: this deposit function belongs in the BankAccount class.'" << endl;
}
void BankAccount :: withdraw(int withdrawValue) {
        cout << "'This output was hardcoded: this withdraw function belongs in the BankAccount class.'" << endl;
}

int BankAccount :: accNumber = 0; //must be initiated to zero to start counting

void BankAccount :: display() const
{
        cout << endl;
        cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;
        cout << "Account Balance: $" << balance << endl;
        cout << endl;
}
