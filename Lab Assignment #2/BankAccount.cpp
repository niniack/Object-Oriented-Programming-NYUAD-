#include <iostream>
#define SIZE 10

using namespace std;

class BankAccount
{
private:
  string name, accType;
  static int accNumber;
  int accID;
  double balance, interestRate;   //dollars, annual

public:

  //getters and setters
  void setName (string newName);
  void getName ();

  void setType (string newType);
  void getType ();

  void getAccNumber ();
  void getAccID();

  void setBalance (double newBalance);
  void getBalance ();

  void setInterestRate (double newInterestRate);
  void getInterestRate ();

  void display();

  BankAccount()
  {
    name = "";
    accType = "";
    balance = 0;
    interestRate = 0;
    accNumber;
    accID = 0;
  };

  BankAccount (string initName, string initAccType, double initBalance, double initInterestRate)
  {
    name = initName;
    accType = initAccType;
    balance = initBalance;
    interestRate = initInterestRate;
    accNumber++;
    accID = accNumber;

  };

};

void BankAccount :: setName (string newName) {name = newName;}
void BankAccount :: getName() {cout << name << endl;}

void BankAccount :: setType (string newType) {accType = newType;}
void BankAccount :: getType() {cout << accType << endl;}

void BankAccount :: getAccNumber () {cout << accNumber << endl;}
void BankAccount :: getAccID () {cout << accID << endl;}

void BankAccount :: setBalance (double newBalance) {balance = newBalance;}
void BankAccount :: getBalance() {cout << balance << endl;}

void BankAccount :: setInterestRate (double newInterestRate) {interestRate = newInterestRate;}
void BankAccount :: getInterestRate() {cout << interestRate << endl;}

int BankAccount :: accNumber = 0;

void BankAccount :: display()
{
  cout << "Account Holder Name: " << name << endl;
  cout << "Account ID: " << accID << endl;
  cout << "Account Type: " << accType << endl;
  cout << "Account Balance: $" << balance << endl;
  cout << "Account Interest Rate: " << interestRate << "% Annual"<< endl;
  cout << endl;
}


int main()
{
  BankAccount acc1("John Smith", "Debit", 500, 2.0);
  BankAccount acc2 ("Apple Smith", "Debit", 100, 2.0);
  BankAccount acc3("Banana Smith", "Credit", 1000, 2.0);
  acc1.display();
  acc2.display();
  acc3.display();
  acc1.getAccNumber();
  //acc2.display();
}
