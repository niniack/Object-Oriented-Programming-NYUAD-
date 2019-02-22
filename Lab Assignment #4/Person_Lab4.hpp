using namespace std;

class Person //this class is an abstract class as it should never be instantiated
{
public:
  string firstName;
  string lastName;

  Person(string initFirstName, string initLastName); //constructor function
};
