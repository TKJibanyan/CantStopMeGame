//  column.cpp
//  P3-Khamphouy
//  Created by Tony Khamphouy on 2/5/23.
#include "column.hpp"
// --------------------------------------------------------------------------
//  Places a tower. Moves tower to tile to capture column
bool
Column :: startTower( spt p ){
    playCol = p->color(); //Used to save player color to use in print();
    if(cState != ECcolumn::Available) return false;
    if(colPos[(int)p->color()] == 0){
        colPos[0] = 1;
    }
    else {
        colPos[0] = colPos[(int)p->color()] + 1;
        if(colPos[0] == cLen){
            cState = ECcolumn::Pending;
        }
    }
    return true;
}
// --------------------------------------------------------------------------
//  Moves the tower 1 square forward.
bool
Column :: move(){
    if(colPos[0] >=1 && cState != ECcolumn::Pending){
        colPos[0] = colPos[0] + 1;
        if(colPos[0] == cLen){
            cState = ECcolumn::Pending;
        }
        return true;
    }
    return false;
}
// --------------------------------------------------------------------------
//  Stops the players turn
void
Column :: stop( spt p){
    colPos[(int)p->color()] = colPos[0];
    colPos[0] = 0;
    if(colState() == ECcolumn::Pending){
        cState = ECcolumn::Captured;
        p->wonColumn(cNum);
    }
}
// --------------------------------------------------------------------------
//  determines if tower in column
bool
Column :: towInCol(){
    if(colPos[0] == 0){
        return false;
    }
    return true;
}

void
Column :: bust(){
    colPos[(int)playCol] = 0;
    colPos[0] = 0;
}
// --------------------------------------------------------------------------
//  Prints
ostream&
Column :: print(ostream& os) const{
    os << cNum <<" " << colString[(int)colState()] << " ";
    for(int k = 1; k <= cLen; k++){
        if(k == colPos[0]){
            os << "T";
        }
        else if(k == colPos[(int)playCol]){
            os << begLet[(int)playCol];
        }
        else{
            os << "-";
        }
    }
    return os;
}


