#include <iomanip>
#include <iostream>

#include "hw3-2.hpp"

using namespace std;

int main() {
// Instantiate the class object
  Date newdate;


  newdate = Date();
// These are for the traditional 'get and set' date functions.
  bool errflag = false;
    // Setters
  newdate.setDay(3);
  newdate.setMonth(4);
  newdate.setYear(2002);
    cout << "The Get-and-Set date is : " << newdate.getDay() << "/" << newdate.getMonth() << "/"
       << newdate.getYear() << endl;

    // This will take input from the user, validate it.
  newdate.readDate(errflag);
// This will get the date.
  cout << newdate.getDate();
}
