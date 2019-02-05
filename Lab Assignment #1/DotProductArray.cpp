#include <iostream>

using namespace std;

double calc_dot_product(int,  double[],  double[]);

int main()
{
  int size;
  cout << "Please enter the vectors' size: " << endl;
  cin >> size;

  double v1[size], v2[size];

  cout << "Please consecutively enter values for vector 1: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> v1[i];
  }

  cout << "Please consecutively enter values for vector 2: " << endl;
  for (int j = 0; j < size; j++)
  {
    cin >> v2[j];
  }

  double sum = calc_dot_product(size, v1, v2);

  cout << "The cross product for vector 1 and vector is: " << sum;
}

double calc_dot_product(int size, double v1[], double v2[])
{
  int sum = 0;
  for (int i=0; i < size; i++)
  {
    sum += v1[i]*v2[i];
  }
  return sum;
}
