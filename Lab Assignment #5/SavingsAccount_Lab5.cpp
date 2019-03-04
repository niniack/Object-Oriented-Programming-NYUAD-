#include "SavingsAccount_Lab5.hpp"
#include <iostream>
#include <string>

using namespace std;

SavingsAccount :: SavingsAccount() {
};
SavingsAccount :: SavingsAccount(std::string initLastName, std::string initFirstName, double initBalance, float initInterestRate)
{
        interestRate = initInterestRate;
        person.firstName = initFirstName;
        person.lastName = initLastName;
        balance = initBalance;
        accNumber++;
        accID = accNumber;
};

SavingsAccount :: ~SavingsAccount() {
};

void SavingsAccount :: setInterestRate(float newInterestRate) {
        interestRate = newInterestRate;
}
void SavingsAccount :: getInterestRate() const {
        cout << "Interest Rate: " << interestRate << "%" << endl;
}

void SavingsAccount ::  withdraw(int withdrawValue) {
        if (balance - withdrawValue < 0) //logic to allow for valid withdrawals
        {
                withdrawable = false;
                cout << "Sorry, insufficient funds for transaction" << endl;
        }
        else {balance -= withdrawValue;}

        cout << "'This output was hardcoded: this withdraw function belongs in the SavingsAccount class.'" << endl;
};

void SavingsAccount :: deposit(int depositValue) {
        balance += depositValue;
        cout << "'This output was hardcoded: this deposit function belongs in the SavingsAccount class.'" << endl;
}

void SavingsAccount :: display() const
{
        cout << endl;
        cout << "Savings Account" << endl;
        cout << "Account ID: " << accID << endl;
        cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;
        cout << "Account Balance: $" << balance << endl;
        cout << "Account Interest Rate: " << interestRate << "%" << endl;
        cout << endl;
}
