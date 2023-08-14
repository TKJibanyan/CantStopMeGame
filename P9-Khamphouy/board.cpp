//  board.cpp
//  P5-Khamphouy
//  Created by Tony Khamphouy on 2/20/23.
#include "board.hpp"
// --------------------------------------------------------------------------
//  constructor assigns backbone
Board :: Board():backBone{nullptr}{
    for(int k = 2; k <= 12; k++){
        backBone[k] = upi(new Column(k));
    }
}
// --------------------------------------------------------------------------
//  Starts new player turn
void
Board :: startTurn(sharedpt p){
    currP = p;
    tCount = 0;
}
// --------------------------------------------------------------------------
//  Moves tower one slot if available
bool
Board :: move(int col){
    if(backBone[col]->colState() != ECcolumn::Available ) return false;
    if(tCount == 3 && !backBone[col]->towInCol()) return false;
    if(backBone[col]->towInCol()){
        backBone[col]->move();
    }
    else{
        towInCol[tCount++] = col;
        backBone[towInCol[tCount-1]]->startTower(currP);
    }
    return true;
}
// --------------------------------------------------------------------------
//  Stops the players turn
void
Board :: stop(){
    for(int k = 0; k < tCount; k++){
        backBone[towInCol[k]]->stop(currP);
    }
}
// --------------------------------------------------------------------------
//  Bust all the towers in column;
void
Board :: bust(){
    cout << "\nBusted!\n";
    for(int k = 0; k < tCount; k++){
        backBone[towInCol[k]]->bust();
    }
}
// --------------------------------------------------------------------------
//  prints columns
ostream&
Board :: print(ostream& os) const{
    for(int k = 2; k <= 12; k++){
        os << *backBone[k] << "\n";
    }
    return os;
}

