/* @author: SUDARSNA MUKUND
 * @date: September 22, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include <iostream>
#include <string>
using namespace std;

#ifndef CDACCOUNT
#define CDACCOUNT

// cdaccount.h
// definition of class CDAccount

class CDAccount {
  friend ostream &operator<<(ostream &, const CDAccount &);

 public:
  /*LIFECYCLE SECTION */
  CDAccount();
  CDAccount(float, float, int);  // constructor
  ~CDAccount(){};                // destructor

  /* OPERATOR SECTION */

  /*OPERATIONS/ACCESS SECTION */
  double getInterestRate();
  double getInitialBalance();
  double getFinalBalance();
  int getTerm();
  string getAccountNumber();

  /*INQUIRY SECTION */
  bool isTermLimit() const;
  bool isAccountNegative() const;
  bool isAccountNumValid() const;  // is term greater than 12 months?

 protected:
 private:
  int dollar;
  float cents;
  double interestRate;
  int accountTerm;  // account term
};

#endif