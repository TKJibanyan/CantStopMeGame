//  column.cpp
//  P3-Khamphouy
//  Created by Tony Khamphouy on 2/5/23.
#include "column.hpp"
int Column::colCt=0;
// --------------------------------------------------------------------------
//  Places a tower. Moves tower to tile to capture column
bool
Column :: startTower( sharedpt p ){
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
    if(towInCol() && cState != ECcolumn::Pending){
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
Column :: stop( sharedpt p){
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
// --------------------------------------------------------------------------
//  resets all towers and tiles
void
Column :: bust(){
    colPos[(int)playCol] = 0;
    colPos[0] = 0;
}
// --------------------------------------------------------------------------
//  Prints
ostream&
Column :: print(ostream& os) const{
    os <<left <<setw(12) << cNum << colString[(int)colState()] << "\t";
    for(int k = 1; k <= cLen; k++){
        if(k == colPos[0]){
            os << "T";
        }
        else if(k == colPos[1]){
            os << begLet[1];
        }
        else if(k == colPos[2]){
            os << begLet[2];
        }
        else if(k == colPos[3]){
            os << begLet[3];
        }
        else if(k == colPos[4]){
            os << begLet[4];
        }
        else{
            os << "-";
        }
    }
    return os;
}



