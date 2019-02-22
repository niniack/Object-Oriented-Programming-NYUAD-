#include <string>

class Person;

class BankAccount //abstract class
{
public:
  int accID; //unique
  static int accNumber; //this variable counts number of objects created
  double balance;  //dollars, annual
  Person person();
  bool withdrawable = true; //used for withdraw balance checking

  //default constructor
  BankAccount();

  //constructor
  BankAccount(std::string initLastName, std::string initFirstName, double initBalance);

  //interface for getters and setters (name, number of accounts, balance)
  void func() const; //const used to imply that function does not modify object

  void setName(std::string newLastName, std::string newFirstName);
  void getName() const;
  void getAccID() const;

  void getBalance() const;
  void deposit(int depositValue); //this function is not virtual
  virtual void withdraw(int withdrawValue) = 0; //this is purely virtual

  virtual void display() const; //implies that the BankAccount display function will be overriden by inheriting class
};
