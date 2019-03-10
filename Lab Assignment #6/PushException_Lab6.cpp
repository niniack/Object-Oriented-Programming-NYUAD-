#include <iostream>
#include <exception>

using namespace std;

class PushException : public exception {

private:

Person owner;
Person inserted;

public:

PushException(Person owner, Person inserted)
{
  this->owner = owner;
  this->inserted = inserted;
}

void print() const
{
  cout << "The error is push_Error" << endl;
  cout << "You are trying to add an account held by " << inserted;
  cout << " to an account group held by " << owner << "." << endl;
  cout << "This action is forbidden." << endl;
}


};
