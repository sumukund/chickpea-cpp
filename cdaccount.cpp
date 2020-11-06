/* @author: SUDARSNA MUKUND
 * @CDAccount: September 19, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include "cdaccount.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// CDAccount default constructor
CDAccount::CDAccount() {}

// CDAccount constructor
CDAccount::CDAccount(float ab, float ir, int term) {
  dollar = (ab);  // account balance
  cents = (ab * 10);
  interestRate = (ir / 1000);
  accountTerm = term;  // this gives the term
}

// GETTERS (WITH VALIDATIOn)
double CDAccount::getInterestRate() {
  if (interestRate < 0) {
    return NULL;
  } else
    return interestRate * 1000;  // as we divided by 1000 above, * by 1000 here
                                 // to get the percentage.
}

double CDAccount::getInitialBalance() {
  if (cents / 10 < 0) {
    return NULL;
  } else
    return cents / 10;  // If the account balance is less than 0, return 0
}

// if the account term is 12
double CDAccount::getFinalBalance() {
  if (accountTerm > 12 || accountTerm < 0 || (cents / 10) < 0) {
    return NULL;
  } else
    return cents / 10 + ((cents / 10) * (interestRate) * (accountTerm / 12.0));
}

int CDAccount::getTerm() { return accountTerm; }

// BOOLEANS

bool CDAccount::isTermLimit() const {
  if (accountTerm > 12 || accountTerm < 0)
    return true;
  else
    return false;  // over term limit
}

bool CDAccount::isAccountNegative() const {
  if (dollar < 0 || cents < 0)
    return true;
  else
    return false;
}

// Overloaded output operator
ostream &operator<<(ostream &output, const CDAccount &d) {
  cout << std::setprecision(2) << d.dollar << "." << d.cents << endl;  //
  return output;  // enables cascading
}