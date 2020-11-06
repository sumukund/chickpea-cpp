/* @author: SUDARSNA MUKUND
 * @date: September 19, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include <iostream>
#include "date.h"
#include "Date.cpp"

using namespace std;


// MAIN FUNCTION
int main() {
  Date newDate;        // constructor
  string inputString;  // string for input

  newDate.setDate(3, 3, 2007);  // set the date here
  cout << "\t\tThe Date is set as " << newDate
       << endl;  // output with overloaded operator
  cout
      << "\t\t*****************************************************************"
      << endl;
  cout << "\t\tPlease input the number of times you want to increment the date"
       << endl;
  cout
      << "\t\t*****************************************************************"
      << endl;
  cin >> inputString;  // input

  int inputInt = stoi(inputString);  // change the string to int
  int i;
  for (i = 0; i <= inputInt; i++) {
    cout << "\t" << newDate++ << endl;  // increment with increment operator
  }

  if (newDate.isLeapYear(2007) == false) {  // check errors in Leap Year
    cout << "\t\t**************************************************************"
            "***"
         << endl;
    cout << "\t\tIt's not a leap year" << endl;
  } else {
    cout << "\t\t**************************************************************"
            "***"
         << endl;
    cout << "\t\tIt is a leap Year " << endl;
  }
}