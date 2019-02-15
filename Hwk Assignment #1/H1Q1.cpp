#include <iostream>

using namespace std;

void my_func(int size, int *my_arr) //passing an int and a pointer
{
	int j; //declaring an int variable j

	int k; //declaring an int variable j

	k = *++my_arr; //incrementing the pointer by one and then dereferencing
	//incrementing from the 5th element to the 6th element, then setting k equal to the 6th element, k = 30

	cout<<"1. Answer: "<< k<<endl; //Output: 1. Answer: 30

	my_arr = my_arr - 3;//decrementing by 3 elements and saving the address of that element
	//my_arr now stores the address of the 3rd element, which has the value 15

	k = *my_arr++;//this command dereferences the pointer and saves it to k, so that k=15
	//it then increments the pointer to the 4th element

	cout<<"2. Answer: "<< k <<endl;//Output: 2. Answer: 15

	cout<<"3. Answer: "<< *my_arr<<endl;//Output: 3. Answer: 20
	//it is 20 because my_arr was incremented in the previous k assignment, which leaves my_arr in that state (pointing to the 4th element)

	my_arr = my_arr + 4; //my_arr goes from the 4th to the 8th element (4+4)

	*my_arr = *my_arr + 3;//the 8th element is 40; this command means set the value at the 8th element to be 40 + 3

	cout<<"4. Answer: "<< *my_arr<<endl; //Output: 4. Answer: 43

	*(my_arr + 1) = *(my_arr - 1) + *(my_arr + 3); //set the 9th element in my_arr to equal the 7th element + the 11th element
	//however, that shouldn't work well considering there are only 10 elements, thus it will save some gibberish value, say X

	cout<<"5. Answer: "<< *my_arr<<endl; //Output: 5. Answer: 43
	//this is still 43 because my_arr was never incremented. Thus, it is still at the 8th element, which was set to 43 previously

	cout<<"6. Answer: "<< *(my_arr + 1)<<endl; // Output: 6. Answer: Some Gibberish value X
	//the my_arr element only has 10 elements; however, the previous definition of the 9th element involved the addition
	//of the 7th element and the 11th element, which is not possible. Thus, 35 is added to some random gibberish value stored
	//in memory for the "11th element".

	k = --*my_arr;//the pointer still points to the 8th element. Thus, this commmand dereferences the pointer to provide 43 and
	//subtracts one from the value to set k = 42

	cout<<"7. Answer: "<< k <<endl; // Output: 7. Answer: 42
  cout<<"8. Answer: "<< *my_arr <<endl; //Output: 8. Answer: 42
	//the value at the 8th element is now 42 as well because when setting k = 42, the command also changed the very value of
	//of the 8th element by subtracting 1 from it. The command was essentially saying
	//*my_arr = *my_arr - 1


  my_arr = my_arr - 2; //the pointer initially pointing to the 8th element is now moved back 2 elements.
	//the pointer is now pointing to the 6th element

	k = *my_arr++;//this command dereferences the pointer and saves it to k, so that k=30
	//then it increments the pointer to the 7th element

	cout<<"9. Answer: "<< k <<endl; // Output: 9. Answer: 30
  cout<<"10. Answer: "<< *my_arr <<endl; // Output: 10. Answer: 35

	for(j = 0; j<= size -8; j++) //size=10; thus the condition is j<= 2
	//this is a for loop that iterates for 3 loops (j=0,1,2)
	{
	    *my_arr++; //this command first increments the pointer THEN dereferences it
			//This is different from previous similar commands because there is no variable to save it to;
			//therefore, it gives preference to the increment rather than the dereferencing

			*my_arr = *my_arr - 2; //the value of new element is then subtracted by two and overwritten to the same location

	    cout<<j+11<<". Answer: "<<*my_arr<<endl;
			// Output: 11. Answer: 40
			// Output: 12. Answer: X-2; the X refers to some gibberish value saved in element 9 because of line 33
			// Output: 13. Answer: 48
	}
}

int main() {
	int s = 10; //int variable s is set to 10
	int result; //declare an int variable result
	int p[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; //declare an int array p with 10 elements
	my_func(s, &p[4]); // passing int s (of value 10) and the address of the 5th element to my_func
	system("PAUSE"); //note that this is not a “real” C/C++command, thus doesn't work as expected on my Linux machine
	return 0;
}
