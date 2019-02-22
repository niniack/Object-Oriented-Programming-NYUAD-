#include <string>
#include <stdlib.h>
#include <stdio.h>

class SavingsAccount : public BankAccount
{
public:
  float interestRate;

  //default constructor
  SavingsAccount();

  //constructor
  SavingsAccount( std::string initLastName,
                  std::string initFirstName,
                  double initBalance,
                  float initInterestRate);

  void setInterestRate(float newInterestRate);
  void getInterestRate() const;

  void withdraw(int withdrawValue);
  void deposit(int depositValue);

  void display() const override;

};
