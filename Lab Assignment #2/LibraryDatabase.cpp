#include <iostream>
#define SIZE 4 //easily manipulable size for author array
#define LIB 100 //library size

using namespace std;

class BookType //class declaration
{
private:
  string title, publisher, isbn; //hiding information as private
  float price;
  int stock;
  string author[SIZE];


public:
  //getters and setters function declarations
  void getTitle();
  void setTitle(string newTitle);
  string returnTitle();

  void getPublisher();
  void setPublisher (string newPublisher);
  string returnPublisher();

  void getISBN();
  void setISBN(string newISBN);
  string returnISBN();

  void getPrice();
  void setPrice (float newPrice);
  float returnPrice();

  void getAuthor();
  void setAuthor(int offset, string newAuthor);

  void getStock();
  void setStock(int newStock);
  int returnStock();

  void display();

  //default constructor
  BookType () {};

  //constructor
  BookType (string initTitle, string initPublisher, string initISBN, float initPrice, string initAuthor[], int initStock)
  {
    title = initTitle;
    publisher = initPublisher;
    isbn = initISBN;
    price = initPrice;
    for (int i=0; i<SIZE; i++) {author[i] = initAuthor[i];}
    stock = initStock;
  };

};

//member function definitions (getters and setters)
void BookType :: getTitle() {cout << "Title: " << title << endl;}
void BookType :: setTitle (string newTitle) {title = newTitle;}
string BookType :: returnTitle() {return title;}

void BookType :: getPublisher() {cout << "Title: " << title <<  endl; cout << "Publisher: "<< publisher << endl; cout << endl;}
void BookType :: setPublisher (string newPublisher) {publisher = newPublisher;}
string BookType :: returnPublisher() {return publisher;}

void BookType :: getISBN() {cout << "Title: " << title <<  endl; cout << "ISBN: "<< isbn << endl; cout << endl;}
void BookType :: setISBN (string newISBN) {isbn = newISBN;}
string BookType :: returnISBN() {return isbn;}

void BookType :: getPrice() {cout << "Title: " << title <<  endl; cout << "Price: $"<< price << endl; cout << endl;}
void BookType :: setPrice(float newPrice) {price = newPrice;}
float BookType :: returnPrice() {return price;}

void BookType :: getStock() {cout << "Title: " << title <<  endl; cout << "Stock: "<< stock << endl; cout << endl;}
void BookType :: setStock(int newStock) {stock = newStock;}
int BookType :: returnStock() {return stock;}

void BookType :: getAuthor()
{
  cout << "Title: " << title <<  endl;
  cout << "Author(s): ";
  for (int i=0; i < SIZE; i++)
  {
    if (author[i]=="") {break;}
    if (author[i+1]=="") {cout << author[i];}
    else {cout << author[i] << ", ";}
  }

  cout << endl;
  cout << endl;
}

  void BookType :: setAuthor(int offset, string newAuthor)
{
  author[offset-1] = newAuthor;
}


//display function defition
void BookType :: display()
{
  cout << "Title: " << title <<  endl;
  cout << "Author(s): ";

  //for and if statements to avoid awkward comma print outs
  for (int i=0; i < SIZE; i++)
  {
    if (author[i]=="") {break;}
    if (author[i+1]=="") {cout << author[i];}
    else {cout << author[i] << ", ";}
  }
  cout << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "Price: $" << price << endl;
  cout << "In Stock: " << stock << endl;
  cout << endl;
}

class Library: public BookType
{
public:
  BookType books[LIB]; //initializes an array of 100 books

  void byTitle(string searchTitle);
  void byISBN(string searchISBN);
};

void Library :: byTitle(string searchTitle)
{
  bool found = false;
  for (int i=0; i<SIZE; i++)
  {
    if(searchTitle == books[i].returnTitle()) {cout << "Library ID: " << i << endl; books[i].display(); found = true;}
  }

  if(found=false) {cout << "Sorry, the book was not found." << endl;}
}

void Library :: byISBN(string searchISBN)
{
  bool found = false;
  for (int i=0; i<SIZE; i++)
  {
    if(searchISBN == books[i].returnISBN()) {cout << "Library ID: " << i << endl; books[i].display(); found = true;}
  }

  if(found=false) {cout << "Sorry, the book was not found." << endl;}
}

int main()
{
  //EXERCISE PART 1
  cout << "The following is an example of initializing a book outside of the library." << endl;
  string nightvaleAuthor[SIZE] = {"Joseph Fink", "Jeffrey Cranor"}; //author array
  BookType nightvale("Welcome to Night Vale", "Harper Perennial", "9780062351427", 14.31, nightvaleAuthor, 15); //constructor
  nightvale.display(); //information display

  //example updating the stock number (works this way with any other parameter with the exception of author)
  cout << "The following will demonstrate updating the stock number:" << endl;
  nightvale.getStock();
  nightvale.setStock(5);
  nightvale.getStock();

  cout << "The following will demonstrate adding and removing an author:" << endl;
  //example adding/ updating author (requires input of author number, counting from 1)
  nightvale.getAuthor();
  nightvale.setAuthor(3, "Unknown Author");
  nightvale.getAuthor();

  //example removing author (print statement does not print if there are no authors!)
  nightvale.setAuthor(3, "");
  nightvale.getAuthor();


  //EXERCISE PART 2

  //lets initialize a few books
  Library library;
  library.books[0].setTitle("The Catcher in the Rye");
  library.books[0].setISBN("9785699661121");

  library.books[1].setTitle("Nineteen Eighty-Four");
  library.books[1].setISBN("9788026874256");

  library.books[2].setTitle("Catch-22");
  library.books[2].setISBN("9780099529118");

  //searching by title
  cout << "Let's search for the book 'Catch-22' by title and add the author" << endl;
  library.byTitle("Catch-22");
  //let's update the author (the ID is given to you as a result)
  library.books[2].setAuthor(1, "Joseph Heller");
  //search again
  library.byTitle("Catch-22");

  //searching by ISBN
  cout << "Let's search for the book with ISBN 9788026874256 and update the Publisher" << endl;
  library.byISBN("9788026874256");
  //let's update the publisher (the ID is given to you as a result)
  library.books[1].setPublisher("Penguin Books");
  //search again
  library.byTitle("Nineteen Eighty-Four");

  cout << "It is also easy to pass information directly to the constructor from the BookType class as it is inherited. The following book was added to the library using the originally constructed book." << endl;
  cout << endl;
  //call constructor from parent class
  library.books[3] = nightvale;
  //call display function to show in output
  library.byTitle("Welcome to Night Vale");


}
