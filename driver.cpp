/* @author: SUDARSNA MUKUND
 * @date: September 19, 2020
 *  @version: 1.0
 *
 */

// SYSTEM INCLUDES

#include <iostream>

#include "cdaccount.cpp"
#include "cdaccount.h"

using namespace std;

// MAIN FUNCTION
int main() {
  CDAccount newAcct = CDAccount(1525.60, 4.3, 9);  // constructor
  string inputString;                              // string for input

  cout << "\t\tWhat is your account number ? :" << endl;  // get account number
  getline(cin, inputString);
  int accountnum = std::stoi(inputString);  // string to int

  // VALIDATION : account number

  if (accountnum <= 0) {
    std::cout << "Your account number is invalid. Please try again. " << endl;
    getline(cin, inputString);
  }

  // OUTPUT
  std::cout
      << "\t\t**************************************************************"
         "*** \n\n"
      << endl;
  std::cout << "\t\tCertificate of Deposit\n\n \t\tACCOUNT NUMBER :"
            << accountnum << endl;

  std::cout
      << "\t\t**************************************************************"
         "*** \n\n"
      << endl;

  // VALIDATION : Account Balance
  if (newAcct.isAccountNegative() == true) {
    std::cout
        << "\t\tYour Account balance is negative. Please deposit more money"
        << endl;

  } else {
    std::cout << "\t\tAccount Balance is Valid" << endl;
    std::cout << "\t\tInitial Balance : $" << newAcct.getInitialBalance()
              << endl;
  }

  // VALIDATION : Account Term
  if (newAcct.isTermLimit() == true) {
    std::cout << "\t\tPlease enter a valid term " << endl;
  } else {
    std::cout << "\t\tTerm limit is valid" << endl;
    std::cout << "\t\tTERM : " << newAcct.getTerm() << " months " << endl;
  }

  // FINAL OUTPUT

  std::cout << "\t\t Your Interest Rate : " << newAcct.getInterestRate() << "%"
            << endl;
  std::cout << "\t\t Your Final Balance, after account maturity  : $"
            << newAcct.getFinalBalance() << endl;
}