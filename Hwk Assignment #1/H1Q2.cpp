#include <iostream>
#include <string.h>
#define SOURCE 12
#define DEST 18

using namespace std;


//string copy functions

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
  char sourceOne[] = "sourceOne"; //declare character array and initialize
  char destinationOne[] = "destinationOne"; //declare character array and initialize
  copyOne(destinationOne, sourceOne); //pass array by reference
  cout << "Function copyOne results in the destination array showing: " << destinationOne << endl; //print the destination array

  //code for trial two
  char sourceTwo[] = "sourceTwo"; //declare character array and initialize
  char destinationTwo[] = "destinationTwo";//declare character array and initialize
  char *ps = sourceTwo; //declare pointer for character array and initialize with appropriate array
  char *pd = destinationTwo;//declare pointer for character array and initialize with appropriate array
  copyTwo(pd, ps); //pass array by pointers
  cout << "Function copyTwo results in the destination array showing: " << pd << endl; //print the destination array

  //code for trial three
  char *ps2 = new char[SOURCE]; //declare a pointer and initialize it with allocated memory for character string
  char sourceThree[SOURCE] = "sourceThree"; //declare character array and initialize it
  for (int i =0; i < SOURCE; i++) //run a for loop to store the characters into the allocated memory
  {
    *ps2 = sourceThree[i];
    ++ps2;
  }
  ps2 = ps2 - SOURCE;  //place the pointer back to the beginning

  char *pd2 = new char[DEST]; //declare a pointer and initialize it with allocated memory for character string
  char destinationalThree[DEST] = "destinationThree"; //declare character array and initialize it
  for (int i =0; i < DEST; i++)//run a for loop to store the characters into the allocated memory
  {
    *pd2 = destinationalThree[i];
    ++pd2;
  }
  pd2 = pd2 - DEST;//place the pointer back to the beginning

  copyThree(pd2, ps2); //pass array by pointers pointing to allocated memory
  cout << "Function copyThree results in the destination array showing: "<< pd2 << endl; //print the destination array
  delete [] ps2; //important to deallocate memory
  delete [] pd2; //important to deallocate memory

}
