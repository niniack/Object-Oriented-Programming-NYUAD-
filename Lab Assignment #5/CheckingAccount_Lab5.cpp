#include <iostream>
#include "CheckingAccount_Lab5.hpp"

using namespace std;

CheckingAccount :: CheckingAccount() {
};
CheckingAccount :: CheckingAccount(string initLastName,
                                   string initFirstName,
                                   double initBalance,
                                   double initMinBalance=0,
                                   float initInterestRate=0,
                                   double initServiceCharge=0)

{
        person.lastName = initLastName;
        person.firstName = initFirstName;
        interestRate = initInterestRate;
        minBalance = initMinBalance;
        serviceCharge = initServiceCharge;
        balance = initBalance;
        accNumber++; //incremented when an account is made
        accID = accNumber;
}

CheckingAccount :: ~CheckingAccount() {
};

void CheckingAccount :: setInterestRate(float newInterestRate) {
        interestRate = newInterestRate;
}
void CheckingAccount :: getInterestRate() const {
        cout << "Interest Rate: " << interestRate << "%" << endl;
}

void CheckingAccount :: setMinBalance(double newMinBalance) {
        minBalance = newMinBalance;
}
void CheckingAccount :: getMinBalance() const {
        cout << "Minimum Balance: $" << minBalance << endl;
}

void CheckingAccount :: setServiceCharge(double newServiceCharge) {
        serviceCharge = newServiceCharge;
}
void CheckingAccount :: getServiceCharge() const {
        cout << "Service Charge: $" << serviceCharge << "monthly" << endl;
}

void CheckingAccount :: verifyBalance() const
{
        if (minBalance > 0) //logic for checking minimum balance
        {
                if (balance <= minBalance) {cout << "Your balance is too low!" << endl;}
                else {cout << "Your balance satsifies the requirement." << endl;}
        }

        else {cout << "You must set a minimum balance first.";}

}

void CheckingAccount :: draftCheck(string recipient, double value)
{
        BankAccount :: withdraw(value); //relies on withdraw funciton logic to allow check or not

        if (withdrawable == true)
        {cout << "Thank you, an amount of $" << value << " will be transferred to " << recipient << endl;}
}


void CheckingAccount :: withdraw(int withdrawValue)
{
        if (balance - withdrawValue < 0) //logic to allow for valid withdrawals
        {
                withdrawable = false;
                cout << "Sorry, insufficient funds for transaction" << endl;
        }
        else {balance -= withdrawValue;}
}
void CheckingAccount :: deposit(int depositValue) {
        balance += depositValue;
}


void CheckingAccount :: display() const
{
        cout << endl;
        cout << "Checkings Account" << endl;
        cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;
        cout << "Account ID: " << accID << endl;
        cout << "Account Balance: $" << balance << endl;
        cout << "Account Minimum Balance: $" << minBalance << endl;
        cout << "Account Interest Rate: " << interestRate << "%" << endl;
        cout << "Account Service Charge: $" << serviceCharge << " monthly" << endl;
        cout << endl;

        if (balance <= minBalance) {cout << "Your balance is too low!" << endl;}
}
