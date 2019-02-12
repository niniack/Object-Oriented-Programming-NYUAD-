#include <iostream>
#define SIZE 10

using namespace std;

class BankAccount
{
private:
  string name, accType;
  static int accNumber; //this variable counts number of objects created
  int accID;
  double balance, interestRate;   //dollars, annual

public:

  //interface for getters and setters (name, accType, number of accounts, ID, balance, interestRate)
  //note that account number and ID don't have setters
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

  //default constructor
  BankAccount ()
  {
    name = "";
    accType = "";
    balance = 0;
    interestRate = 0;
    accNumber;
    accID = 0;
  };

  //constructor
  BankAccount (string initName, string initAccType="Undeclared", double initBalance=0, double initInterestRate=0)
  {
    name = initName;
    accType = initAccType;
    balance = initBalance;
    interestRate = initInterestRate;
    accNumber++;
    accID = accNumber;

  };

};

//function definitions
void BankAccount :: setName (string newName) {name = newName;}
void BankAccount :: getName() {cout << name << endl;}

void BankAccount :: setType (string newType) {accType = newType;}
void BankAccount :: getType() {cout << accType << endl;}

void BankAccount :: getAccNumber () {cout << accNumber;}
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


//main code
int main()
{
  cout << "Account members can be added to the system using the constructor function. All the account information can then be displayed with the display function." << endl;
  cout << endl;
  BankAccount acc1("John Smith", "Debit", 500, 2.0);
  acc1.display();
  cout << endl;

  cout << "There are "; acc1.getAccNumber(); cout << " account(s) in the system." << endl;
  cout << endl;

  cout << "It is also possible to initialize a group of accounts at once. All information does not necessarily have to be input at the time of initialization. The bank account can be initialized with just the name." << endl;
  cout << endl;

  BankAccount accArray[10]={BankAccount("Alice"),BankAccount("Beth"), BankAccount("Catherine"), BankAccount("Drake"), BankAccount("Elijah"), BankAccount("Francis"), BankAccount("George"), BankAccount("Harry"), BankAccount("India"), BankAccount("Jonathan") };
  cout << "There are "; acc1.getAccNumber(); cout << " account(s) in the system." << endl;
  cout << endl;

  cout << "For example, an account for Alice was initialized with just her name. Alice's information (account type, balance, and interest rate) can then be updated on an individual basis. The ID assigned to her is unchangeable." << endl;
  cout << endl;
  accArray[0].display();
  accArray[0].setType("Credit");
  accArray[0].setBalance(1000);
  accArray[0].setInterestRate(3);

  cout << "Alice's banking information has now been updated." << endl;
  cout << endl;
  accArray[0].display();

  cout << "Banking accounts must be initialized with at least a name. Otherwise a dummy account is generated with no unique ID." << endl;
  BankAccount newAcc();

}
