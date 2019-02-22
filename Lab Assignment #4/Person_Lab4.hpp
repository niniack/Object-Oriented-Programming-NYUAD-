#include <string>

class Person //this class is an abstract class as it should never be instantiated
{
public:
  std::string firstName;
  std::string lastName;

  Person(); //default constructor

  Person(std::string initFirstName, std::string initLastName); //constructor function

};
