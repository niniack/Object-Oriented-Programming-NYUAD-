#include <iostream>
#include "BankAccountUpdated.hpp"
#define SIZE 10

using namespace std;

//function definitions for Person class
Person :: ~Person() {};

//function definitions for BankAccount class
BankAccount :: BankAccount() {};
BankAccount :: BankAccount(string initLastName, string initFirstName, double initBalance)
{
  lastName = initLastName;
  firstName = initFirstName;
  balance = initBalance;
};

void BankAccount :: setName(string newLastName, string newFirstName)
{
  lastName = newLastName;
  firstName = newFirstName;
}
void BankAccount :: getName() const {cout << "Account Holder: " << firstName << " " << lastName << endl;}

void BankAccount :: getBalance() const {cout << "Account Balance: $" << balance << endl;}
void BankAccount :: deposit(int depositValue) {balance += depositValue;}
void BankAccount :: withdraw(int withdrawValue)
{
  if (balance - withdrawValue < 0)
  {
    withdrawable = false;
    cout << "Sorry, insufficient funds for transaction" << endl;
  }
  else {balance -= withdrawValue;}
}

int BankAccount :: accNumber = 0;

void BankAccount :: display() const
{
  cout << endl;
  cout << "Account Holder: " << firstName << " " << lastName << endl;
  cout << "Account Balance: $" << balance << endl;
  cout << endl;
}

//function definitions for CheckingAccount class
CheckingAccount :: CheckingAccount() {};
CheckingAccount :: CheckingAccount(string initLastName,
                                   string initFirstName,
                                   double initBalance=0,
                                   double initMinBalance=0,
                                   float initInterestRate=0,
                                   double initServiceCharge=0)

{
  lastName = initLastName;
  firstName = initFirstName;
  interestRate = initInterestRate;
  minBalance = initMinBalance;
  serviceCharge = initServiceCharge;
  balance = initBalance;
  accNumber++;
  accID = accNumber;
}

void CheckingAccount :: setInterestRate(float newInterestRate) {interestRate = newInterestRate;}
void CheckingAccount :: getInterestRate() const {cout << "Interest Rate: " << interestRate << "%" << endl;}

void CheckingAccount :: setMinBalance(double newMinBalance) {minBalance = newMinBalance;}
void CheckingAccount :: getMinBalance() const {cout << "Minimum Balance: " << minBalance << endl;}

void CheckingAccount :: setServiceCharge(double newServiceCharge) {serviceCharge = newServiceCharge;}
void CheckingAccount :: getServiceCharge() const {cout << "Service Charge: " << serviceCharge << endl;}

void CheckingAccount :: verifyBalance() const
{
  if (minBalance > 0)
  {
    if (balance <= minBalance) {cout << "Your balance is too low! Please add balance to avoid service charge" << endl;}
    else {cout << "Your balance satsifies the requirement." << endl;}
  }

  else {cout << "You must set a minimum balance first.";}

}

void CheckingAccount :: draftCheck(string recipient, double value)
{
  BankAccount :: withdraw(value);

  if (withdrawable == true)
  {cout << "Thank you, an amount of $" << value << " will be transferred to " << recipient << endl;
  }
}

void CheckingAccount :: display() const
{
  cout << endl;
  cout << "Checkings Account" << endl;
  cout << "Account Holder: " << firstName << " " << lastName << endl;
  cout << "Account ID: " << accID << endl;
  cout << "Account Balance: $" << balance << endl;
  cout << "Account Minimum Balance: $" << minBalance << endl;
  cout << "Account Interest Rate: " << interestRate << "%" << endl;
  cout << "Account Service Charge: $" << serviceCharge << endl;
  cout << endl;

  if (balance <= minBalance) {cout << "Your balance is too low! Please add balance to avoid service charge" << endl;}
}


SavingsAccount :: SavingsAccount() {};
SavingsAccount :: SavingsAccount(string initLastName,
                                   string initFirstName,
                                   double initBalance=0,
                                   float initInterestRate=0)

{
  lastName = initLastName;
  firstName = initFirstName;
  interestRate = initInterestRate;
  balance = initBalance;
  accNumber++;
  accID = accNumber;
}

void SavingsAccount :: setInterestRate(float newInterestRate) {interestRate = newInterestRate;}
void SavingsAccount :: getInterestRate() const {cout << "Interest Rate: " << interestRate << "%" << endl;}

void SavingsAccount :: display() const
{
  cout << endl;
  cout << "Savings Account" << endl;
  cout << "Account Holder: " << firstName << " " << lastName << endl;
  cout << "Account Balance: $" << balance << endl;
  cout << "Account Interest Rate: " << interestRate << "%" << endl;
  cout << endl;
}




//main code
int main()
{

  cout << "Account members can be added to the system using the constructor function.";
  cout << "All the checkings account information can then be displayed with the display function.";
  cout << endl;

  CheckingAccount cacc1 ("Smith", "John", 500);
  cacc1.display();
  cout << endl;

  



  cout << "Another account, with a different type, may be added to the system the same way.";
  cout << "Once again the information can be displayed with the display function";
  cout << endl;

  SavingsAccount sacc1 ("Smith", "Apple", 500);
  sacc1.display();
  cout << endl;












}
