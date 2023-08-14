//  badchoice.cpp
//  P10-Khamphouy
//  Created by Tony Khamphouy on 4/26/23.
#include "badchoice.hpp"
// --------------------------------------------------------------------------
//  prints if roll is wrong
void
BadChoice :: print(){
    cerr <<"\nChoice inputted was incorrect\n";
    cerr <<"You entered a number greater than 3 or less than 1.\n"
    <<"Please reenter.\n";
}
// --------------------------------------------------------------------------
//  prints if imput is the same
void
DuplicateSlot :: print(){
    cerr<<"\nEntered same input twice\n";
    cerr<<"You entered " << let << " and " << slet
    <<"\nPlease reenter.\n";
}
// --------------------------------------------------------------------------
//  wrong input
void
BadSlot :: print(){
    cerr<<"\nWrong input\n";
    cerr<<"You entered " << let << " and " << slet
    <<"\nPlease reenter.\n";
}
