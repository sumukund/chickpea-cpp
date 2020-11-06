/* @author: SUDARSNA MUKUND
 * @date: September 19, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include <iostream>
#include "date.h"
using namespace std;

const int Date::sDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Date constructor
Date::Date(int m, int d, int y) { setDate(m, d, y); }

void Date::setDate(int mm, int dd, int yy) {
  month = (mm >= 1 && mm <= 12) ? mm : 1;
  year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

  // test for a leap year
  if (month == 2 && isLeapYear(year))
    day = (dd >= 1 && dd <= 29) ? dd : 1;
  else
    day = (dd >= 1 && dd <= sDays[month]) ? dd : 1;
}

// Preincrement operator
Date &Date::operator++() {
  helpIncrement();
  return *this;  // reference return to create an lvalue
}

// Postincrement operator
Date Date::operator++(int) {
  Date temp = *this;
  helpIncrement();

  // return non-incremented, saved, temporary object
  return temp;  // value return; not a reference return
}

const Date &Date::operator+=(int additionalDays) {
  for (int i = 0; i < additionalDays; i++) helpIncrement();

  return *this;  // enables cascading
}

bool Date::isLeapYear(int y) const {
  if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
    return true;  // a leap year
  else
    return false;  // not a leap year
}

// Determine if the day is the end of the month
bool Date::isEndOfMonth(int d) const {
  if (month == 2 && isLeapYear(year))
    return d == 29;  // last day of Feb. in leap year
  else
    return d == sDays[month];
}

void Date::helpIncrement() {
  if (isEndOfMonth(day) && month == 12) {  // end year
    day = 1;
    month = 1;
    ++year;
  } else if (isEndOfMonth(day)) {  // end month
    day = 1;
    ++month;
  } else  // not end of month or year; increment day
    ++day;
}

// Overloaded output operator
ostream &operator<<(ostream &output, const Date &d) {
  static char *monthName[13] = {
      "",     "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};

  output << monthName[d.month] << ' ' << d.day << ", " << d.year;

  return output;  // enables cascading
}