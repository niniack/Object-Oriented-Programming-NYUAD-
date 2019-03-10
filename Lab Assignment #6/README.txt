*************************
* Name: Nishant Aswani  *
* NetID: nsa325         *
* Lab: #5               *
*************************

As this assignment is getting larger, here are a few notes/points.
1. Person_Lab5.hpp depicts the use of overloading the boolean (==) operator and the ostream (<<) operator, as well as a friend function (needed to overload the << operator).
However, the boolean operator is made a member function and not friended.


2. Person_Lab5.cpp implements the overloading of the boolean and ostream operators.

3. AccountManager is a template class with a template function called push.

4. AccountManager depicts the use of overloading the constructor function as you can construct an object with an object of type Person or BankAccount.

5. The .cpp file inclusions have been removed from main.cpp and it compiles on my computer through command line.

6. As explicitly stated by the document, the AccountManager class is a container for BankAccount type objects.
Hence, the class dynamically casts the SavingsAccount or CheckingAccount type object into a BankAccount type pointer (derived-to-base casting).
Pointers are used because the BankAccount class is abstract AND because dynamic casting works with pointers and/or references.
