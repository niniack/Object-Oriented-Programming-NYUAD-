#include <string>


// #include "BankAccount_Lab4.hpp"
// #include "CheckingAccount_Lab4.hpp"
#include "SavingsAccount_Lab4.hpp"
#include "SavingsAccount_Lab4.cpp"
#include "BankAccount_Lab4.cpp"
#include "Person_Lab4.cpp"
// #include "Person_Lab4.hpp"

using namespace std;

void callWithdraw (BankAccount *baptr, int value) {
        baptr->withdraw(value);
}

void callDeposit (BankAccount *baptr, int value) {
        baptr->deposit(value);
}


int main ()
{

        cout << "This program demonstrates what it means to have a virtual function" << endl;
        cout<< "Note that the BankAccount class is abstract and has a derived class SavingsAccount" << endl;
        cout << "A base class pointer is then defined as the address of a derived class object." << endl;
        cout << endl;
        BankAccount *baptr; //base class pointer definition
        SavingsAccount sacc1("Shaw", "Jill", 500, 0.5); //instantiate a derived class object
        baptr = &sacc1; //assign the address of derived object to base class pointer

        cout << "The program has now instantiated an object for " << baptr->person << "." << endl; //note the overload of << operator here

        cout << endl;
        cout << "This is the original information:" <<endl;
        baptr->display();

        cout << "Now we will call the withdraw function, which is by definition virtual." <<endl;
        cout << "Thus the program is 'smart' enough to call the withdraw function from the derived class." <<endl;
        cout << endl;

        callWithdraw(baptr, 50);
        baptr->display();

        cout << "Surely enough, the function did deduct 50 because the derived class' function was called." << endl;
        cout << endl;


        cout << "Now we will call the deposit function, which is NOT virtual." <<endl;
        cout << "Thus the program is NOT 'smart' enough to call the deposit function from the derived class." <<endl;
        cout << endl;
        cout << "Instead it calls the function from the base class, which does nothing but print this message: " <<endl;

        callDeposit(baptr, 50);
        cout << endl;

        cout << "To confirm, we can call the display function and check whether 50 were added back." << endl;

        baptr->display();

        cout << "Confirmed by the printed information, no amount was added back because the base class is incapable of doing so." << endl;
}
