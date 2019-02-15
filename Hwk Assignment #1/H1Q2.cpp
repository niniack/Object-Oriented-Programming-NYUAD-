#include <iostream>
#include <string.h>
#define SOURCE 12
#define DEST 18

using namespace std;

void copyOne(char destinationOne[], char sourceOne[])
{
  strcpy(destinationOne, sourceOne);
};

void copyTwo(char *pd, char *ps)
{
  strcpy(pd, ps);
};

void copyThree(char *pd2, char *ps2)
{
  strcpy(pd2, ps2);
}

int main()
{
  //code for trial one
  char sourceOne[] = "sourceOne";
  char destinationOne[] = "destinationOne";
  copyOne(destinationOne, sourceOne); //pass array by reference
  cout << "Function copyOne results in the destination array showing: " << destinationOne << endl;

  //code for trial two
  char sourceTwo[] = "sourceTwo";
  char destinationTwo[] = "destinationTwo";
  char *ps = sourceTwo;
  char *pd = destinationTwo;
  copyTwo(pd, ps); //pass array by pointers
  cout << "Function copyTwo results in the destination array showing: " << destinationTwo << endl;

  //code for trial three
  char *ps2 = new char[SOURCE];
  char sourceThree[SOURCE] = "sourceThree";
  for (int i =0; i < SOURCE; i++)
  {
    *ps2 = sourceThree[i];
    ++ps2;
  }
  ps2 = ps2 - SOURCE;

  char *pd2 = new char[DEST];
  char destinationalThree[DEST] = "destinationThree";
  for (int i =0; i < DEST; i++)
  {
    *pd2 = destinationalThree[i];
    ++pd2;
  }
  pd2 = pd2 - DEST;

  copyThree(pd2, ps2); //pass array by pointers pointing to allocated memory
  cout << "Function copyThree results in the destination array showing: "<< pd2 << endl;
  delete [] ps2;
  delete [] pd2;

}
