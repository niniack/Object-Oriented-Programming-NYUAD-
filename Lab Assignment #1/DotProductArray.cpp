#include <iostream> //input output stream library

using namespace std;

double calc_dot_product(int size,  double *p1,  double *p2); //passing pointers

int main()
{
  int size; //declare size variable as integer
  cout << "Please enter the vectors' size: " << endl; //request input from user
  cin >> size; //place input into size variable

  double v1[size], v2[size]; //declare arrays for vectors
  double *p1, *p2; //declare pointers for the arrays
  p1 = v1;  //store vector 1 address into pointer
  p2 = v2;  //store vector 2 address into pointer

  cout << "Please consecutively enter values for vector 1: " << endl; //request input for vector 1
  for (int i = 0; i < size; i++) //for loop to store input into array
  {
    cin >> v1[i];
  }

  cout << "Please consecutively enter values for vector 2: " << endl; //request input for vector 1
  for (int j = 0; j < size; j++) //for loop to store input into array
  {
    cin >> v2[j];
  }

  double sum = calc_dot_product(size, p1, p2); //call function to calculate dot product; passing pointers instead of vector

  cout << "The dot product for vector 1 and vector 2 is: " << sum; //final output showing dot product
}

double calc_dot_product(int size, double *p1, double *p2)
{
  int sum = 0; //running sum
  for (int i=0; i < size; i++)
  {
    sum += p1[i]*p2[i]; //mathematical equation to calculate dot product
  }
  return sum; //returns final sum to main
}
