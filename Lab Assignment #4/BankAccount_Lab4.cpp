#include <iostream>
#include "BankAccount_Lab4.hpp"
using namespace std;


//function definitions for BankAccount class
BankAccount :: BankAccount() {};
BankAccount :: BankAccount(string initLastName, string initFirstName, double initBalance)
{
  person.lastName = initLastName;
  person.firstName = initFirstName;
  balance = initBalance;
};

void BankAccount :: setName(string newLastName, string newFirstName)
{
  person.lastName = newLastName;
  person.firstName = newFirstName;
}
void BankAccount :: getName() const {cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;}
void BankAccount :: getAccID() const {cout << "Account ID: " << accID << endl;}

void BankAccount :: getBalance() const {cout << "Account Balance: $" << balance << endl;}
void BankAccount :: deposit(int depositValue) {balance += depositValue;}
void BankAccount :: withdraw(int withdrawValue) {}

int BankAccount :: accNumber = 0; //must be initiated to zero to start counting

void BankAccount :: display() const
{
  cout << endl;
  cout << "Account Holder: " << person.firstName << " " << person.lastName << endl;
  cout << "Account Balance: $" << balance << endl;
  cout << endl;
}
