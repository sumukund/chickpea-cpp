/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * Exam 2
 * Nov 5 2020
 * *********/

#include <iostream>

#include "fractions.cpp"
#include "header.h"

using namespace std;

int main() {
  cout << "***************************************************"
       << "\t\t\n\nFraction Program, Sudarsna Mukund" << endl;
  // these are used for input.
  int input;
  int a, b, c, d;

  // this for loop is allowing you to choose your operation and then output the
  // result 8 times.
  for (int i = 0; i < 8; i++) {
    cout << "\t\tInput a number to choose your operation :" << endl;
    cout << "\n 1: Addition \n\n 2: Subtraction \n\n 3 : Multiplication \n\n "
            "4: Division"
         << endl;
    cin >> input;

    cout << "\t\tInput your first numerator " << endl;
    cin >> a;
    cout << " \t\tInput your first denominator : " << endl;
    cin >> b;
    cout << " \t\tInput your second numerator : " << endl;
    cin >> c;
    cout << "\t\tInput your second denominator: " << endl;
    cin >> d;

    Fraction x(a, b);
    Fraction y(c, d);
    // Output the user fraction
    cout << "\n\nYour first fraction is : " << x << endl;
    cout << "\n\nYour second fraction is : " << y << endl;

    // The reason why I used a switch case is because there are 4 different
    // operations and I wanted to be able to cycle between them.
    switch (input) {
      case 1:
        cout << "\t\tAddition Function: " << x << " + " << y << " = "
             << (x += y) << endl;
        break;
      case 2:
        cout << "\t\tSubtraction Function: " << x << " - " << y << " = "
             << (x -= y) << endl;
        break;
      case 3:
        cout << "\t\tMultiplication Function: " << x << " * " << y << " = "
             << (x *= y) << endl;
        break;
      case 4:
        cout << "\t\tDivision Function: " << x << " / " << y << " = "
             << (x /= y) << endl;
        break;

      default:
        cout << "please input a number! \n" << endl;
    }
  }

  return 0;
}