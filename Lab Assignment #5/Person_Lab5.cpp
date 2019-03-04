#include "Person_Lab5.hpp"

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

bool operator == (const Person &person1, const Person &person2)
{
        if (person1.firstName == person2.firstName && person1.lastName == person2.lastName)
        {
                return true;
        }

        else
                return false;
}
