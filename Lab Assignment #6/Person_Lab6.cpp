#include "Person_Lab6.hpp"

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

bool Person :: operator == (const Person &person2) const
{
        if (this->firstName == person2.firstName && this->lastName == person2.lastName)

                return true;

        else
                return false;
}
