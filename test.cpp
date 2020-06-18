#include <iostream>
#include "stack.h"
using namespace std;

int main()
{

  // Implement the stack template with both INT and DOUBLE
  Stack<int> intStack;
 Stack<double> doubleStack;
 // doubleStack top and pop. 
  for (double i = 1.1; i <= 10.00 ; i++) {
    doubleStack.push(i);
    cout << "Display the stack by calling display" << endl;

  doubleStack.display();

  cout << "Display the stack by calling top and pop." << endl;

   cout << doubleStack.top()<< endl;
  doubleStack.pop();
  }

  if (doubleStack.empty())
    cout << "Stack is empty\n";

  return 0;


 for (int i = 1; i <= 10 ; i++)
    intStack.push(i);

  cout << "Display the stack by calling display" << endl;

  intStack.display();

  cout << "Display the stack by calling top and pop." << endl;
	
  for (int i = 0; i < 10 ; i++) {
    cout << intStack.top()<< endl;
    intStack.pop();
  }

  if (intStack.empty())
    cout << "Stack is empty\n";

  return 0; 



}
 
