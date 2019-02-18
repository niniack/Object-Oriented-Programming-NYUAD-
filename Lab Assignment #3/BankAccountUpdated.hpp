using namespace std;

class Person
{
public:
    string firstName;
    string lastName;

    virtual ~Person() = 0; //required destructor for abstract class
};

class BankAccount : public Person
{
public:
  int accID;
  static int accNumber; //this variable counts number of objects created
  double balance;  //dollars, annual
  bool withdrawable = true;

  //default constructor
  BankAccount();

  //constructor
  BankAccount(string initLastName, string initFirstName, double initBalance);

  //interface for getters and setters (name, number of accounts, balance)
  void func() const;

  void setName(string newLastName, string newFirstName);
  void getName() const;

  void getBalance() const;
  void deposit(int depositValue);
  void withdraw(int withdrawValue);

  virtual void display() const;
};

class CheckingAccount : public BankAccount
{
protected:
  float interestRate;
  double minBalance;
  double serviceCharge;

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

  void display() const override;
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
