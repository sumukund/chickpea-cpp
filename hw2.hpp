/*
*SUDARSNA MUKUND
*CET 2200 DATA STRUCTURES AND ALGORITHMS
* MAY 14 2020
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#ifndef TIME_H
#define TIME_H
// Definitions, Preprocessor Directives
using namespace std;

//Class Declaration
class Time {
		public:
        // Constructor Default
			Time(){};
        int subtractTimes(Time t){
                int difference;
              difference = minutes - t.minutes; 
              return difference;
            }
			void readTime(bool & errFlag);
            int getTime(){
                return minutes;
            }
            ~Time() {};
        protected:
		private:
			int minutes;
	};

//Method Declaration
void Time::readTime(bool & errFlag)
{
// Hours, input, Meridian is an ENUM which translates to 0 or 1. 
    int hours;
    string input;
    enum meridian {AM, PM};
// Enter the hours
    cout << "Enter hours : " << endl;
    cin >> hours;
            // Check if the hours are correctly formatted
        if (hours > 0 && hours <= 12){
                errFlag = false;
            } else {
                errFlag = true;
                cout << "Enter a number between 1 and 12" << endl;
                return;
            }
            // Enter Minutes
            cout << "Enter minutes : " << endl;
            cin >> minutes;
// Check if minutes are correctly formatted
            if (minutes >= 0 && minutes < 60) {
                errFlag = false;
            } else {
                errFlag = true;
                cout << "enter a number betweeen 0 and 59" << endl;
                return;
            }
// Enter AM or PM
            cout << "Enter AM or PM " << endl;
            cin >> input;
            // Stringstream (input) converts the string input to integer
            stringstream myStream(input);
            meridian meri;
// if input = AM then change the hours to minutes, add them together
            if (input == "AM"){
                meri = AM;
                minutes = (hours*60) + minutes;
                errFlag = false;
    // Else if input = PM then add 12*60 to the total time
            } else if (input == "PM"){
                meri = PM;
                minutes = (12*60) + (hours*60) + minutes;
                errFlag = false;
            } else {
                errFlag = true;
                cout << "input a valid meridian" << endl;
            }
   return;

}
 

#endif 