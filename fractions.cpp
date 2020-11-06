
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * Exam 2
 * Nov 5 2020
 * *********/

/*
 * This is a fraction class. It takes a numerator and denominator
 * and uses overloaded operators to perform functions.
 *
 */

#include <iostream>

#include "header.h"

// CODE FOR CONSTRUCTORS

Fraction::Fraction(int num, int den) {
  numerator = num;
  denominator = den;
}

Fraction::Fraction(int num) {
  numerator = num;
  denominator = 1;
}
Fraction::Fraction() {
  denominator = 1;
  numerator = 0;
}

// OPERATORS

Fraction& Fraction::operator-=(const Fraction& right) {
  // a/b - c/d = (a*d - b*c) / (b*d)
  int a = numerator;
  int b = denominator;
  int c = right.numerator;
  int d = right.denominator;
  if (b == 0 || d == 0) {
    std::cout << "error. please input a valid denominator. Remember, you "
                 "cannot divide by 0"
              << std::endl;
  } else
    numerator = (a * d - b * c);
  denominator = (b * d);

  return *this;
}

Fraction& Fraction::operator+=(const Fraction& right) {
  // a/b + c/d = (a*d + b*c) / (b*d)
  int a = numerator;
  int b = denominator;
  int c = right.numerator;
  int d = right.denominator;

  if (b == 0 || d == 0) {
    std::cout << "error. please input a valid denominator. Remember, you "
                 "cannot divide by 0"
              << std::endl;
  } else
    numerator = (a * d) + (b * c);
  denominator = (b * d);

  return *this;
}

Fraction& Fraction::operator*=(const Fraction& right) {
  // a/b * c/d = (a*c) / (b*d)
  int a = numerator;
  int b = denominator;
  int c = right.numerator;
  int d = right.denominator;
  if (b == 0 || d == 0) {
    std::cout << "error. please input a valid denominator. Remember, you "
                 "cannot divide by 0"
              << std::endl;
  } else
    numerator = (a * c);
  denominator = (b * d);

  return *this;
}

Fraction& Fraction::operator/=(const Fraction& right) {
  // a/b / c/d = (a*d) / (b*c)
  int a = numerator;
  int b = denominator;
  int c = right.numerator;
  int d = right.denominator;
  if (b == 0 || d == 0) {
    std::cout << "error. please input a valid denominator. Remember, you "
                 "cannot divide by 0"
              << std::endl;
  } else
    numerator = (a * d);
  denominator = (b * c);
  return *this;
}

// Output : Operators
std::ostream& operator<<(std::ostream& os, const Fraction& a) {
  os << a.numerator << "/" << a.denominator;
  return os;
}
