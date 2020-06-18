#include <iostream>     // std::cout, std::ostream, std::ios
#include <fstream>   
#include "hw3-1.hpp"   // std::filebuf

int main(){
    
    // Instantiate the class objects.
    // Yeezy is a default instantiation with no argument.
    // Potato has one argument, which I have provided

    CounterType yeezy, potato(7);
//Here, I'm going to increase, get, and then output the count.
    yeezy.increaseCount();
    yeezy.getCount();
    yeezy.outputstream(cout);
    
//Here I'm going to decrease, get, and then output the count.
    yeezy.decreaseCount();
    yeezy.getCount();
    yeezy.outputstream(cout);

// This section has the same format as above.
    potato.increaseCount();
    potato.getCount();
    potato.outputstream(cout);
    potato.decreaseCount();
    potato.getCount();
    potato.outputstream(cout);
}
