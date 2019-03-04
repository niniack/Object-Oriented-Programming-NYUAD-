#include <iostream>
#include <vector>
#include <typeinfo>

#include "BankAccount_Lab5.hpp"
#include "Person_Lab5.hpp"
// #define MAXSIZE 5

using namespace std;

template <typename T, typename T2> //template class
class AccountManager {
private: //information that should not be changed, thus private
Person owner;
vector <T*> accList;

public:
AccountManager(T2 acc) //constructor for template class
{
        T* baptr;
        baptr = dynamic_cast<T*>(&acc);
        owner = baptr->person; //defines the owner as the person holding the account
        accList.push_back(baptr); //then adds the account to vecotr

};

AccountManager(Person person) //overloading constructor
{
        owner = person; //you can also set the owner without adding any accounts
};

AccountManager();

void push(T2 acc) //template function
{

        if (acc.person == owner) //note that the boolean == operator is being overloaded
        {
                BankAccount* baptr;
                baptr = dynamic_cast<T*>(&acc);
                accList.push_back(baptr);
        }

        else
        {
                cerr << "You are trying to add an account from " << acc.person << " to an account group held by " << owner << endl;
                //note the person object is being overloaded.
                cerr << "This action is forbidden." << endl;
        }

};

void quickDisplay()
{
        cout << "There are " << accList.size() << " accounts held by " << owner << endl;
}

void display()
{
        cout << "Here are all the accounts held by " << owner << " in this group:"<<endl;

        for (unsigned int x=0; x<accList.size(); x++)
        {
                accList[x]->display();
        }
}

};
