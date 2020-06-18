#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

using namespace std;

class Date {
  // default constructor
 public:
  Date(){};
  // methods to get and set 
  void setDay(int);
  int getDay();
  void setMonth(int);
  int getMonth();
  void setYear(int);
  int getYear();
  void readDate(bool &errflag);
// this is the method to get the date as an input from the user and validate it. 
  string getDate() { return date; }

 protected:
 //variables. Day, month, year, and string date. 
 private:
  int day;
  int month;
  int year;
  string date;
};

// GETTERS AND SETTERS
void Date::setDay(int dd) { day = dd; }
int Date::getDay() { return day; }
void Date::setMonth(int mm) { month = mm; }
int Date::getMonth() { return month; }
void Date::setYear(int yy) { year = yy; }
int Date::getYear() { return year; }

// method for a full date format read from user input, validated, and then outputted.

void Date::readDate(bool &errflag) {
//Constants: Maximum, minimum.
  const int MAX_YEAR = 9999;
  const int MIN = 0;

// Entered date is a string. We are going to stoi that string below. 
  string entered_date;
  int entered_month;
  int entered_year;
  int entered_day;
  char fill = '/';
  cout << "Enter a date (dd/mm/yyyy): " << endl;
  cin >> entered_date;

// Changing the substrings to integers so that we can evaluate them 

  entered_day = stoi(entered_date.substr(0, 2));
  entered_month = stoi(entered_date.substr(3, 2));
  entered_year = stoi(entered_date.substr(6));

// This if statement checks if any values are negative

  if (entered_day < MIN || entered_month < MIN || entered_year < MIN) {
    errflag = true;
    cout << "Enter a valid date. No negatives. Your date was: \n"
         << entered_date << endl;
    return;
  }

// isLeapYear- this is a boolean value that evaluates whether a given year is a leap year.

  bool isLeapYear = false;

// If statement that evaluates the year. 
  if (entered_year > MAX_YEAR) {
    errflag = true;
    cout << "Enter a valid year. Years cannot be greater than " << MAX_YEAR
         << " Your date was : \n " << entered_date << endl;

  } else if ((entered_year % 4 == 0 && entered_year % 100 != 0) ||
             (entered_year % 400 == 0)) {
    errflag = false;
    isLeapYear = true;
  } else {
    errflag = false;
  }

  // Year is not valid, so exit the program
  if (errflag == true) {
    return;
  }
/*THE SWITCH STATEMENT
* This switch statement evaluates if the month needs 31 days or 30 days.
* In the case of February, the statement evaluates if its a leap year
* If it is a leap year, the maximum days are 29. If not then the maximum days are 28.
*/
  switch (entered_month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (entered_day <= 31) {
        date = entered_date;
        errflag = false;
        cout << "The date is " << date << endl;

      } else {
        errflag = true;
        cout << "Please input a vaild date. \n ex: 4/2/1998 " << endl;
        return;
      }
      break;

    case 4:
    case 6:
    case 9:
    case 11:
      if (entered_day <= 30) {
        date = entered_date;
        errflag = false;
        cout << "The date is " << date << endl;
      } else {
        errflag = true;
        cout << "Please input a vaild date. \n ex: 4/2/1998 " << endl;
        return;
      }

      break;

    case 2:

      if (isLeapYear == true && entered_day <= 29) {
        date = entered_date;
        errflag = false;
        cout << "The date is " << date << endl;

      } else if (isLeapYear == false && entered_day <= 28) {
        date = entered_date;
        errflag = false;
        cout << "The date is " << date << endl;
      } else {
        errflag = true;
        cout << "Please input a vaild date. \n ex: 4/2/1998 " << endl;
        return;
      }

      break;

    default:
      if (entered_month > 12 || entered_month < 1) {
        errflag = true;
        cout << "Please input a vaild date. \n ex: 4/2/1998 " << endl;
        return;
      }

      break;
  }
}

#endif