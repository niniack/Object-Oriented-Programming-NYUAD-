#include <string>
#include <iostream>
#include <time.h>
#include <typeinfo>

#include "CheckingAccount_Lab6.hpp"
#include "SavingsAccount_Lab6.hpp"
#include "Person_Lab6.hpp"
#include "BankAccount_Lab6.hpp"
#include "AccountManager_Lab6.cpp"
// #include "PushException_Lab6.cpp"


#include "CheckingAccount_Lab6.cpp"
#include "SavingsAccount_Lab6.cpp"
#include "BankAccount_Lab6.cpp"
#include "Person_Lab6.cpp"


using namespace std;


int main ()
{

        /*
           first try and catch block, catches the error when a different user's account
           is being added to a given owner's account
         */
        try {
                SavingsAccount sacc1("Shaw", "Jill", 500, 0.5);
                SavingsAccount sacc2("Shaw", "Jill", 1000, 0.5);
                AccountManager <BankAccount, SavingsAccount> accMan1(sacc1);
                accMan1.push(sacc2);

                Person p1("James", "Shaw");
                AccountManager <BankAccount, SavingsAccount> accMan2(p1);

                accMan2.push(sacc2);
        }

        catch(const PushException &pe)
        {
                cout << endl;
                pe.print();
                cout << endl;
        }

        /*
           second try and catch block, catches the error when the number of accounts added
           to an account manager have exceeded the MAXSIZE (5).
         */

        try {
                SavingsAccount saccA("Shaw", "Jill", 500, 0.5);
                SavingsAccount saccB("Shaw", "Jill", 1000, 0.5);
                SavingsAccount saccC("Shaw", "Jill", 50, 0.05);
                SavingsAccount saccD("Shaw", "Jill", 400, 0.3);
                SavingsAccount saccE("Shaw", "Jill", 5000, 0.7);

                SavingsAccount saccF("Shaw", "Jill", 300, 0.2);

                AccountManager <BankAccount, SavingsAccount> accMan2(saccA);

                accMan2.push(saccB);
                accMan2.push(saccC);
                accMan2.push(saccD);
                accMan2.push(saccE);

                accMan2.push(saccF);

        }

        catch(const bad_alloc &ba)
        {
                cout << endl;
                cout << "The error is " << ba.what() << endl;
                cout << "You have attempted to exceed the number of allowed accounts (5).";
                cout << endl << endl;
        }










}
