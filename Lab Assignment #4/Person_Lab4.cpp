
#include "Person_Lab4.hpp"
#include <iostream>
using namespace std;

Person :: Person(string initFirstName, string initLastName)
{
        lastName = initLastName;
        firstName = initFirstName;
}

Person :: Person() {
}

ostream & operator << (ostream &out, const Person &person) //overloading the << operator
{
        out << person.firstName << " " << person.lastName;
        return out;
}
