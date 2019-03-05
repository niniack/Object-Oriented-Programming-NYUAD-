#include <string>
#include <iostream>
#include <time.h>
#include <typeinfo>

#include "CheckingAccount_Lab5.hpp"
#include "SavingsAccount_Lab5.hpp"
#include "Person_Lab5.hpp"
#include "BankAccount_Lab5.hpp"
#include "AccountManager_Lab5.cpp"


#include "CheckingAccount_Lab5.cpp"
#include "SavingsAccount_Lab5.cpp"
#include "BankAccount_Lab5.cpp"
#include "Person_Lab5.cpp"


using namespace std;

int main ()
{
        cout << "This program demonstrates the use of an account container." << endl << endl;
        cout << "Three savings accounts have been instantiated and will added to the account manager";
        cout << endl << endl;
        SavingsAccount sacc1("Shaw", "Jill", 500, 0.5);
        SavingsAccount sacc2("Shaw", "Jill", 600, 0.5);
        SavingsAccount sacc3("Shaw", "Jill", 1000, 0.8);

        AccountManager <BankAccount, SavingsAccount> accMan1(sacc1);
        accMan1.push(sacc2);
        accMan1.push(sacc3);

        cout << "The bank can simply call the display function to view all the accounts stored by the person." << endl;
        accMan1.display();

        cout << "The bank can also call the quick display function to view how many accounts are stored in the manager:";
        cout << endl << endl;

        accMan1.quickDisplay();

        cout << endl;

        cout << "For convenience, it is also possible to start an account group without adding an account. ";
        cout << "This may be useful in cases where an individual plans provide their personal information";
        cout << " but open an account later." << endl;

        Person p1("James", "Shaw");
        AccountManager <BankAccount, SavingsAccount> accMan2(p1);
        cout << endl;

        accMan2.quickDisplay();
        cout << endl;

        cout << "The program also prevents the adding of another user's to a given user's account group.";
        cout << endl << endl;
        accMan2.push(sacc3);

        cout << endl;

        return (0);


}
