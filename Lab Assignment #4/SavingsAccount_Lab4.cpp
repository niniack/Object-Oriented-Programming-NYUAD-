#include <iostream>
#include "SavingsAccount_Lab4.hpp"

using namespace std;

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
