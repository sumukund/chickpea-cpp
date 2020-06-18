#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

#include "phonenumber.h"

using namespace std;

int main()
{
    std::cout << "Enter a phone number: \n";
 
    PhoneNumber phone;
    std::cin >> phone;
 
    std::cout << "You entered: " << phone << '\n';
 
    return 0;
}