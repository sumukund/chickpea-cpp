#include <fstream>
#include <iomanip>
#include <iostream>
#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

using namespace std;

class CounterType {
 public:
  // constructors
  CounterType() { counter = 0; };
  // overloaded constructor
  CounterType(int z) { counter = z; };
  // Destructor
  ~CounterType(){};

  // methods
  // Get the count (access function)
  int getCount(void) { return counter; };

  // Increment
  int increaseCount();
  // Decrement
  int decreaseCount();
  // Method to output to a stream
  void outputstream(ostream &os);

 protected:
 private:
  int counter;
};

int CounterType::increaseCount() {
  // We are going to ask how many times do you want to count
  int input;
  cout << "How many times do you want to count incrementally? ";
  cin >> input;
  bool isNeg;
  // i must be less than or equal to the input to run. Otherwise it will stop
  // counting (which is what we want)
  for (int i = 0; i <= input; i++) {
    cout << counter << endl;
    counter++;
  }
  return counter;
}

// The only difference in decreaseCount() is that the counter must be above 0.
int CounterType::decreaseCount() {
  int input;
  cout << "How many times do you want to count decrementally? ";
  cin >> input;
  bool isNeg;

  // this is a little bit of logic to get this counter to work. 
  if (counter - input >= 0){
    isNeg = false;
  }
  /* ***************************************************************************************************
  * for i = input, i is greater than 0, i--, nested inside is an if statemen which will BREAK the loop *
  * the condition to meet is either if the input = the counter (then you should stop counting)          *
  * OR if the counter is equal to 0. Then stop counting.                                                
  * ******************************************************************************************************/
   for (int i = input; i > 0; i--) {
     if (input == counter || counter <= 0){
       break;
     }
    cout << counter << endl;
    counter--;
  }
  return counter;
       
}
    
// This will output the counter to the stream.
void CounterType::outputstream(ostream &os) {
  os << "the counter is " << counter << endl;
  return;
}

#endif
