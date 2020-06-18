
#include <iostream>
#include <cstring>
#include <cassert>
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

using namespace std;

class PhoneNumber{
public:
   PhoneNumber(string x= "", string y="", string z=""): areaCode(x), exchange(y), line(z){}  // conversion/default ctor
  // ~PhoneNumber();                   // destructor

     friend ostream &operator<< (ostream &, const PhoneNumber &);
   friend istream &operator>> (istream &, PhoneNumber &);

private:

  string areaCode, exchange, line;
};

std::ostream& operator<< (std::ostream &out, const PhoneNumber &phone)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Phone # : (" << phone.areaCode << ") - " << phone.exchange << "- " << phone.line << endl;
 
    return out;
}
 
std::istream& operator>> (std::istream &in, PhoneNumber &phone)
{
    // Since operator>> is a friend of the PhoneNumber class
    // note that parameter point must be non-const so we can modify the class members with the input values
    in >> phone.areaCode;
    in >> phone.exchange;
    in >> phone.line;
 
    return in;
}


#endif