#include <iostream>
#include <vector>

using namespace std;

int calc_dot_product(int,  vector<int>&,  vector<int>&);

int main ()
{
  int size;
  cout << "Please enter the vectors' size: " << endl;
  cin >> size;

  vector<int> v1(size);
  cout << "Please consecutively enter values for vector 1: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> v1[i];
  }

  vector<int> v2(size);
  cout << "Please consecutively enter values for vector 2: " << endl;
  for (int j = 0; j < size; j++)
  {
    cin >> v2[j];
  }

int sum = calc_dot_product(size, v1, v2);


cout << "The dot product for vector 1 and vector is: " << sum;
}

int calc_dot_product(int size, vector<int> &v1,  vector<int> &v2)
{
  int sum = 0;
  for (int i=0; i < size; i++)
  {
    sum += v1[i]*v2[i];
  }
  return sum;
}
