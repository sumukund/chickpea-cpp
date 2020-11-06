/* @author: SUDARSNA MUKUND
 * @date: September 19, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include <iostream>
using namespace std;

#ifndef DATE
#define DATE

// date.h
// Definition of class Date

class Date {
  friend ostream &operator<<(ostream &, const Date &);

 public:
  /*LIFECYCLE SECTION */

  Date(int m = 1, int d = 1, int y = 1900);  // constructor
  ~Date(){};                                 // destructor

  /* OPERATOR SECTION */

  Date &operator++();           // preincrement operator
  Date operator++(int);         // postincrement operator
  const Date &operator+=(int);  // add days, modify object

  /*OPERATIONS/ACCESS SECTION */
  void setDate(int, int, int);  // set the date

  /*INQUIRY SECTION */
  bool isLeapYear(int) const;    // is this a leap year?
  bool isEndOfMonth(int) const;  // is this end of month?

 protected:
 private:
  int month;  // month variable
  int day;    // day variable
  int year;   // year variable

  static const int sDays[];  // array of days per month
  void helpIncrement();      // utility function
};

#endif