 /*
*SUDARSNA MUKUND
*CET 2200 DATA STRUCTURES AND ALGORITHMS
* MAY 14 2020
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "hw2.hpp"

using namespace std;

int main(){
    Time start;
    Time stop;

    start = Time();
    stop = Time();
    
    bool errFlag = false;
    start.readTime(errFlag);

    cout << "Your start time is : " << start.getTime() << endl;
    cout << "Enter stop time : " << endl;
    errFlag = false;
    stop.readTime(errFlag);

    cout << "Your stop time is : " << stop.getTime() << endl;

    int diff;
    diff = stop.subtractTimes(start);

    cout << "The difference is : " << diff << endl;
    int miles;
    cout << "enter miles travelled: " << endl;
    cin >> miles;

    cout << "Your speed is : " << (diff / miles) << " miles per minute " << endl;
    return 0;    

  
}

