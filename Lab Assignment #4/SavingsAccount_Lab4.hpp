#include "BankAccount_Lab4.hpp"

using namespace std;

class SavingsAccount : public BankAccount
{
public:
  float interestRate;

  //default constructor
  SavingsAccount();

  //constructor
  SavingsAccount(string initLastName,
                  string initFirstName,
                  double initBalance,
                  float initInterestRate);

  void setInterestRate(float newInterestRate);
  void getInterestRate() const;

  void withdraw(int withdrawValue);
  void deposit(int depositValue);

  void display() const override;

};
