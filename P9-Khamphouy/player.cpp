//  player.cpp
//  P2-Khamphouy
//  Created by Tony Khamphouy on 1/26/23.
#include "player.hpp"
// --------------------------------------------------------------------------
//  Increase Score, determine if player won
bool
Player :: wonColumn(int colNum){
    switch (playSco[columnScore]){
        case 0:
            playSco[columnScore] = colNum;
            columnScore ++;
            return true;
        case 3:
            return true;
        default:
            return false;
    }
}
// --------------------------------------------------------------------------
//  A way to print the name and scores for testing
ostream&
Player :: print(ostream& os) const{
    os <<"Name: " << pName;
    os <<"\tColor: " << words[(int)color()];
    os <<"  Player Score: " << columnScore;
    os <<"\tColumn's won:[ ";
    for(int k = 0; k < 3; k++){
        os << playSco[k] << " ";
    }
    os <<"]\n";
    return os;
}


