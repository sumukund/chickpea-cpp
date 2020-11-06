/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * Homework 4 -Operator Overloading
 * October 31, 2020
 * *********/

#include <iostream>
#ifndef NUMBER_H
#define NUMBER_H

class Number {
  friend const Number;

 public:
  double num;
  Number* This() { return this; }
  // default constructor
  Number(double dd = 0) : num(dd) {}

  // destructor
  ~Number() {}

  // Operator: Global
  friend const Number operator+(const Number& left, const Number& right);

  friend const Number operator-(const Number& left, const Number& right);

  friend const Number operator*(const Number& left, const Number& right);

  friend const Number operator/(const Number& left, const Number& right);

  // Operator: type conversion to double
  operator double() const {
    std::cout << "operator double() called" << std::endl;
    return num;
  }
  // Operator: Prefix
  friend const Number& operator++(Number& a);
  // Operator: Postfix
  friend const Number operator++(Number& a, int);
  // Operator: Prefix
  friend const Number& operator--(Number& a);
  // Operator: Postfix
  friend const Number operator--(Number& a, int);

  // Operator: Assignment
  Number& operator=(const Number& right) {
    // Error Checking: Handle self-assignment:
    if (this == &right) return *this;
    num = right.num;
    return *this;
  }
  // Operator: ostream
  friend std::ostream& operator<<(std::ostream&, const Number&);
};

#endif

// Global Operators - return values
const Number operator+(const Number& left, const Number& right) {
  return Number(left.num + right.num);
}

const Number operator-(const Number& left, const Number& right) {
  return Number(left.num - right.num);
}

const Number operator*(const Number& left, const Number& right) {
  return Number(left.num * right.num);
}

const Number operator/(const Number& left, const Number& right) {
  return Number(left.num / right.num);
}

// Prefix; return incremented value
const Number& operator++(Number& a) {
  std::cout << "++Number\n";
  a.num++;
  std::cout << a.num << std::endl;
  return a;
}
// Postfix; return the value before increment:
const Number operator++(Number& a, int) {
  std::cout << "Number++\n";
  Number before(a.num);
  a.num++;
  std::cout << a.num << std::endl;
  return before;
}
// Prefix; return decremented value
const Number& operator--(Number& a) {
  std::cout << "--Number\n";
  a.num--;
  std::cout << a.num << std::endl;
  return a;
}
// Postfix; return the value before decrement:
const Number operator--(Number& a, int) {
  std::cout << "Number--\n";
  Number before(a.num);
  a.num--;
  std::cout << a.num << std::endl;
  return before;
}

// Output : Operators
std::ostream& operator<<(std::ostream& os, const Number& a) {
  os << a.num;
  return os;
}

// Output functions
double g(Number a) { std::cout << a.num; }

void f(Number a) {
  ++a;
  a++;
  --a;
  a--;
}
