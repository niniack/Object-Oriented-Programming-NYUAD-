#ifndef PERSON_HPP
#define PERSON_HPP


#include <iostream>
#include <string>

class Person //this class is an abstract class as it should never be instantiated
{
public:
std::string firstName;
std::string lastName;

Person();   //default constructor

Person(std::string initFirstName, std::string initLastName);   //constructor function


friend std ::ostream & operator << (std::ostream &out, const Person &person); //use of friend function for overloading << operator

friend bool operator == (const Person &person1, const Person &person2); //use of friend function for overloading boolean operator

};




#endif
