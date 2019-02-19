using namespace std;

class Person //abstract class purely for inheritance
{
public:
    string firstName;
    string lastName;

    virtual ~Person() = 0; //required destructor for class
    //virtual specifier makes class abstract
};

class BankAccount : public Person //inherits public info from Person class
{
public:
  int accID; //unique
  static int accNumber; //this variable counts number of objects created
  double balance;  //dollars, annual
  bool withdrawable = true; //used for withdraw balance checking

  //default constructor
  BankAccount();

  //constructor
  BankAccount(string initLastName, string initFirstName, double initBalance);

  //interface for getters and setters (name, number of accounts, balance)
  void func() const; //const used to imply that function does not modify object

  void setName(string newLastName, string newFirstName);
  void getName() const;
  void getAccID() const;

  void getBalance() const;
  void deposit(int depositValue);
  void withdraw(int withdrawValue);

  virtual void display() const; //implies that the BankAccount display function will be overriden by inheriting class
};

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
  CheckingAccount(string initLastName,
                  string initFirstName,
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
  void draftCheck(string recipient, double value);

  void display() const override; //implies that the BankAccount display function will be overriden
};

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

  void display() const override;

};
