#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "BankAccount_Lab6.hpp"

#include <string>


class SavingsAccount : public BankAccount
{
public:
float interestRate;

//default constructor
SavingsAccount();

~SavingsAccount();

//constructor
SavingsAccount(std::string initLastName, std::string initFirstName, double initBalance, float initInterestRate);

void setInterestRate(float newInterestRate);
void getInterestRate() const;

void withdraw(int withdrawValue);
void deposit(int depositValue);

void display() const;

};

#endif
