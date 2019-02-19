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
void BankAccount :: getAccID() const {cout << "Account ID: " << accID << endl;}

void BankAccount :: getBalance() const {cout << "Account Balance: $" << balance << endl;}
void BankAccount :: deposit(int depositValue) {balance += depositValue;}
void BankAccount :: withdraw(int withdrawValue)
{
  if (balance - withdrawValue < 0) //logic to allow for valid withdrawals
  {
    withdrawable = false;
    cout << "Sorry, insufficient funds for transaction" << endl;
  }
  else {balance -= withdrawValue;}
}

int BankAccount :: accNumber = 0; //must be initiated to zero to start counting

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
  accNumber++; //incremented when an account is made
  accID = accNumber;
}

void CheckingAccount :: setInterestRate(float newInterestRate) {interestRate = newInterestRate;}
void CheckingAccount :: getInterestRate() const {cout << "Interest Rate: " << interestRate << "%" << endl;}

void CheckingAccount :: setMinBalance(double newMinBalance) {minBalance = newMinBalance;}
void CheckingAccount :: getMinBalance() const {cout << "Minimum Balance: $" << minBalance << endl;}

void CheckingAccount :: setServiceCharge(double newServiceCharge) {serviceCharge = newServiceCharge;}
void CheckingAccount :: getServiceCharge() const {cout << "Service Charge: $" << serviceCharge << "monthly" << endl;}

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
  cout << "Account Service Charge: $" << serviceCharge << " monthly" << endl;
  cout << endl;

  if (balance <= minBalance) {cout << "Your balance is too low!" << endl;}
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




//main code with output
int main()
{

  cout << "Account members can be added to the system using the constructor function. ";
  cout << "All the checkings account information can then be displayed with the display function.";
  cout << endl;

  CheckingAccount cacc1 ("Smith", "John", 500);
  cacc1.display();
  cout << endl;

  cout << "The initiated account is missing min. balance, interest rate, and service charge data. ";
  cout << "This can be added using getter functions and displayed using setter functions.";
  cout << endl;
  cout << endl;

  cacc1.setMinBalance(100);
  cacc1.setInterestRate(1);
  cacc1.setServiceCharge(5);

  cout << "This information has now been updated." << endl;
  cacc1.display();

  cout << "The checkings account can also confirm that the account balance is above the minimum.";
  cout << endl;
  cout << endl;

  cacc1.verifyBalance();
  cout << endl;

  cout << "Seems good. It is also possible to draft a check, given that you provide a receipient and an amount. ";
  cout << "The system disallows a check witdhrawal if it exceeds the balance. Let's send $600 to Jacob";
  cout << endl;
  cout << endl;

  cacc1.draftCheck("Jacob", 600);
  cout << endl;

  cout << "Now, let's send $450 and then verify the balance;" << endl << endl;

  cacc1.draftCheck("Jacob", 450);
  cacc1.getBalance();
  cacc1.verifyBalance();
  cout << endl;


  cout << "A savings account may be added to the system.";
  cout << "Once again the information can be displayed with the display function.";
  cout << endl;

  SavingsAccount sacc1 ("Shaw", "Jill", 500);
  sacc1.display();

  cout << "We will now update the interest rate information." << endl;

  sacc1.setInterestRate(0.5);
  sacc1.getInterestRate();

  cout << "Both accounts are capable of common requirements such as deposits and withdrawals." << endl;

  sacc1.withdraw(100);
  cacc1.deposit(100);

  cout << "Accounts can also retrieve their ID." << endl << endl;

  cout << "For John's account: " << endl;
  cacc1.getAccID();
  cout << endl;

  cout << "For Jill's account: " << endl;
  sacc1.getAccID();

}
