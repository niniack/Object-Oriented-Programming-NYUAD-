#include <string>
#include <stdlib.h>
#include <stdio.h>

class CheckingAccount : public BankAccount //inherits public info from BankAccount class
{
protected:
  float interestRate; //dollars, annual
  double minBalance; //dollars
  double serviceCharge; //dollars, monthly

public:
  //default constructor
  CheckingAccount();

  //constructor
  CheckingAccount(std::string initLastName,
                  std::string initFirstName,
                  double initBalance,
                  double initMinBalance,
                  float initInterestRate,
                  double initServiceCharge);

  void setInterestRate(float newInterestRate);
  void getInterestRate() const;

  void setMinBalance(double newMinBalance);
  void getMinBalance() const;

  void setServiceCharge(double newServiceCharge);
  void getServiceCharge() const;

  void verifyBalance() const;
  void draftCheck(std::string recipient, double value);

  void withdraw(int withdrawValue);
  void deposit(int depositValue);

  void display() const override; //implies that the BankAccount display function will be overriden
};
