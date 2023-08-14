//  badplayer.cpp
//  P10-Khamphouy
//  Created by Tony Khamphouy on 4/18/23.
#include "badplayer.hpp"
// --------------------------------------------------------------------------
//  prints if both input wrong
void
BadPlayer :: print(){
    cerr <<"\nBoth name and color are taken\n";
    pr();
}
// --------------------------------------------------------------------------
//  reenter
void
BadPlayer :: pr(){
    cerr << "You entered "<<name <<" and " << words[(int)color] <<"."
    <<"Please reenter. \n";
}
// --------------------------------------------------------------------------
//  prints if name is wrong
void
BadName :: print(){
    cerr<<"\nName is taken\n";
    pr();
}
// --------------------------------------------------------------------------
//  prints if color is wrong
void
BadColor :: print(){
    cerr<<"\nColor is taken\n";
    pr();
}
