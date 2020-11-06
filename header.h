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
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
 public:
  // default constructor

  Fraction(int numerator, int denominator);

  Fraction(int numerator);
  Fraction();

  // destructor
  ~Fraction() {}

  // Operators: Global

  Fraction& operator*=(const Fraction& right);
  Fraction& operator-=(const Fraction& right);
  Fraction& operator+=(const Fraction& right);
  Fraction& operator/=(const Fraction& right);

  // OPERATOR : ostream
  friend std::ostream& operator<<(std::ostream&, const Fraction&);

 protected:
 private:
  int numerator;
  int denominator;
};

#endif
