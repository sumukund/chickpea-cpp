 /*---------- stack.h  --------------------------------
  This header file defines a Stack data type TEMPLATE
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if a stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Retrieves the top stack value; leaves stack unchanged
    pop:          Modifies stack by removing the value at the top
    display:      Displays all the stack elements
--------------------------------------------------------------*/

#include <iostream>
#pragma once
#ifndef STACK
#define STACK

const int STACK_CAPACITY = 128;
template <typename T> // TEMPLATE
class Stack
{
 public:
  /***** Function Members *****/
  /***** Constructor *****/
  Stack();
  /*----------------------------------------------------------
    Construct a Stack object.

    Precondition:  None.
    Postcondition: An empty Stack object has been constructed
        (myTop is initialized to -1 and myArray is an array
        with STACK_CAPACITY elements of type StackElement).
   -----------------------------------------------------------*/

  bool empty() const;
  /*-----------------------------------------------------------
    Check if stack is empty.
    Precondition: None
    Postcondition: Returns true if stack is empty and 
        false otherwise.
   -----------------------------------------------------------*/

  void push(const T& value);
  /*-----------------------------------------------------------
    Add a value to a stack.
    push to T& (template reference)

    Precondition: value is to be added to this stack
    Postcondition: value is added at top of stack provided 
        there is space; otherwise, a stack-full message is 
        displayed and execution is terminated.
   -----------------------------------------------------------*/


  //  void display(ostream & out) const;

  void display() const;
  /*-----------------------------------------------------------
    Display values stored in the stack. 

    Precondition:  ostream out is open.
    Postcondition: Stack's contents, from top down, have
        been output to out.
   -----------------------------------------------------------*/

  const T& top() const;
  /*-----------------------------------------------------------
    Retrieve value at top of stack (if any).

    Precondition:  Stack is nonempty
    Postcondition: Value at top of stack is returned, unless
        the stack is empty; in that case, an error message is
        displayed and a "garbage value" is returned.
   ----------------------------------------------------------*/

  void pop();
  /*-----------------------------------------------------------
    Remove value at top of stack (if any).

    Precondition:  Stack is nonempty.
    Postcondition: Value at top of stack has been removed, 
        unless the stack is empty; in that case, an error 
        message is displayed and execution allowed to proceed.
   ----------------------------------------------------------*/ 

 private:
  /***** Data Members *****/
  T myArray[STACK_CAPACITY];
  int myTop;
  T* stackPtr;
}; // end of class declaration

/*----------------Stack.cpp  FIG. ------------------------------------

   This file implements Stack member functions.

-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

//#include "Stack.h"

//--- Definition of Stack TEMPLATE
template <typename T>
Stack<T>::Stack()
: myTop(-1)
{}

//--- Definition of empty()
template <typename T>
bool Stack<T>::empty() const
{ 
   return (myTop == -1); 
}

//--- Definition of push()
template <typename T>

void Stack<T>::push(const T& value)
{
   if (myTop < STACK_CAPACITY - 1) 
   { 
      myArray[++myTop] = value;
   }
   else
   {
      cerr << "*** Stack full -- can't add new value ***\n"
              "Must increase value of STACK_CAPACITY in Stack.h\n";
      exit(1);
   }
}

//--- Definition of display()
template <typename T>
void Stack<T>::display() const
{
   for (int i = myTop; i >= 0; i--) 
      cout << myArray[i] << endl;
}

//--- Definition of top()
template <typename T>
const T& Stack<T>::top() const
{
   if ( !empty() ) 
      return (myArray[myTop]);
   else
   {
      cerr << "*** Stack is empty "
              " -- returning garbage value ***\n";
      return *(new T);
   }
}

//--- Definition of pop()
template <typename T>
void Stack<T>::pop()
{
   if ( !empty() )
      myTop--;
   else
      cerr << "*** Stack is empty -- "
              "can't remove a value ***\n";
} 
#endif
