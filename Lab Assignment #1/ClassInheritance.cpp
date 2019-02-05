#include <iostream>

using namespace std;

// Base vehicle class
 class Vehicle
 {
 public:
   double topSpeed, weight, numSeats, acceleration, numOfWheels;

   void setTopSpeed(double newTopSpeed) {topSpeed = newTopSpeed;}
   void getTopSpeed() {cout << topSpeed;}

   void setWeight(double newWeight) {weight = newWeight;}
   void getWeight() {cout << weight;}

   void setNumSeats(double newNumSeats) {numSeats = newNumSeats;}
   void getNumSeats () {cout << numSeats;}

   void setAcceleration(double newAcceleration) {acceleration = newAcceleration;}
   void getAcceleration() {cout << acceleration;}

   void setNumOfWheels(double initNumOfWheels) {numOfWheels = initNumOfWheels;}
   void getNumOfWheels() {cout << numOfWheels;}
 };

//Derived Class: Car

class Car: public Vehicle
{
public:
  string type = "car";
  string model, color;

  void getType() {cout << type;}

  void setModel(string newModel) {model = newModel;}
  void getModel() {cout << model;}

  void setColor(string newColor) {color = newColor;}
  void getColor() {cout << color;}

  Car (double initTopSpeed, double initWeight, double initNumSeats, double initAcceleration, double initNumOfWheels, string initModel, string initColor)
  {
    topSpeed = initTopSpeed;
    weight = initWeight;
    numSeats = initNumSeats;
    acceleration = initAcceleration;
    numOfWheels = initNumOfWheels;
    model = initModel;
    color = initColor;
  }

  void display()
  {
    cout << "The vehical type is: " << type << endl;
    cout << "The top speed is: " << topSpeed << "km/h" << endl;
    cout << "The weight is: " << weight << "kg" << endl;
    cout << "The number of seats is: " << numSeats << endl;
    cout << "The acceleration is: " << acceleration << "s for 0-97 km/h" << endl;
    cout << "The number of wheels is: " << numOfWheels << endl;
    cout << "The model is: " << model << endl;
    cout << "The color is: " << color << endl;
    cout << endl;
  }

};

class Bike: public Vehicle
{
public:
  string type = "bike";
  string model, color;

  void getType() {cout << type;}

  void setModel(string newModel) {model = newModel;}
  void getModel() {cout << model;}

  void setColor(string newColor) {color = newColor;}
  void getColor() {cout << color;}

  Bike (double initTopSpeed, double initWeight, double initNumSeats, double initAcceleration, double initNumOfWheels, string initModel, string initColor)
  {
    topSpeed = initTopSpeed;
    weight = initWeight;
    numSeats = initNumSeats;
    acceleration = initAcceleration;
    numOfWheels = initNumOfWheels;
    model = initModel;
    color = initColor;
  }

  void display()
  {
    cout << "The vehical type is: " << type << endl;
    cout << "The top speed is: " << topSpeed << "km/h" << endl;
    cout << "The weight is: " << weight << "kg" << endl;
    cout << "The number of seats is: " << numSeats << endl;
    cout << "The acceleration is: " << acceleration << "s for 0-97 km/h" << endl;
    cout << "The number of wheels is: " << numOfWheels << endl;
    cout << "The model is: " << model << endl;
    cout << "The color is: " << color << endl;
    cout << endl;
  }

};

class Train: public Vehicle
{
public:
  string type = "train";
  string model;
  int length;

  void getType() {cout << type;}

  void setModel(string newModel) {model = newModel;}
  void getModel() {cout << model;}

  void setlength(int newlength) {length = newlength;}
  void getlength() {cout << length;}

  Train (double initTopSpeed, double initWeight, double initNumSeats, double initAcceleration, double initNumOfWheels, string initModel, int initlength)
  {
    topSpeed = initTopSpeed;
    weight = initWeight;
    numSeats = initNumSeats;
    acceleration = initAcceleration;
    numOfWheels = initNumOfWheels;
    model = initModel;
    length = initlength;
  }

  void display()
  {
    cout << "The vehical type is: " << type << endl;
    cout << "The top speed is: " << topSpeed << "km/h" << endl;
    cout << "The weight is: " << weight << "kg" << endl;
    cout << "The number of seats is: " << numSeats << endl;
    cout << "The acceleration is: " << acceleration << "s for 0-97 km/h" << endl;
    cout << "The number of wheels is: " << numOfWheels << endl;
    cout << "The model is: " << model << endl;
    cout << "The length is: " << length << "m" << endl;
    cout << endl;
  }

};

int main()
{
  Car car1 (355, 1480, 2, 3.14, 4, "Ferrari Enzo", "red");
  car1.display();

  Car car2 (160, 1890, 8, 6.5, 4, "Toyota Prado", "white");
  car2.display();

  Bike bike1 (20, 13, 1, 30, 2, "Mountain", "grey");
  bike1.display();

  Bike bike2 (25, 9, 1, 25, 2, "Road", "blue");
  bike2.display();

  Train train1 (603, 6300, 350, 4, 0, "Maglev", 600);
  train1.display();

  Train train2 (130, 7000, 300, 10.4, 50, "Steam", 550);
  train2.display();






}
