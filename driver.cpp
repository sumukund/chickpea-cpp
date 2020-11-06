/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * Homework 4 -Operator Overloading
 * October 31, 2020
 * *********/

#include <iostream>

#include "number.h"

using namespace std;

int main() {
  // Instantiate 3 Number Objects
  Number a = 13.25;
  Number b = 2.0;
  Number c = 6.0;
  // A fourth Number object, that will be used to test the type conversion.
  Number d;

  // Test of type conversion
  double denominator;
  cout << "Input any kind of number to test the type conversion operator. This "
          "number will be used as the denominator"
       << endl;
  cin >> denominator;
  // Using Assignment operator
  d = denominator;

  // using Global Operators
  Number answer = (a + b - c) / d;

  cout << "\t\t The values you inputted are as follows: \n\n"
       << a << "A\n\n"
       << b << " B\n\n"
       << c << " C\n\n"
       << endl
       << endl;

  cout << "\t\tCalculating the equation (a + b - c) / " << d << endl
       << answer << endl
       << endl;
  // Testing Prefix and Postfix
  Number x = 36, y = 5.625;
  cout << "\t\tPrefix and postfix operators for Number X: " << x << endl;
  // Output function for Prefix and Postfix
  f(x);

  cout << "\t\tPrefix and postfix operators for Number Y: " << y << endl;
  // Output function for Prefix and Postfix
  f(y);
}