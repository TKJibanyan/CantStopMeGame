//  board.cpp
//  P5-Khamphouy
//  Created by Tony Khamphouy on 2/20/23.
#include "board.hpp"
// --------------------------------------------------------------------------
//  Starts new player turn
void
Board :: startTurn(spt p){
    currP = p;
    tCount = 0;
    for(int k = 0; k < 3; k++){
        towInCol[k] = 0;
    }
}
// --------------------------------------------------------------------------
//  Moves tower one slot if available
bool
Board :: move(int col){
    if(backBone[col]->colState() != ECcolumn::Available ) return false;
    if(tCount == 3 && backBone[col]->towInCol() == false) return false;
    if(backBone[col]->towInCol() == true){
        backBone[col]->move();
    }
    else{
        tCount++;
        towInCol[tCount-1] = col;
        backBone[col]->startTower(currP);
    }
    return true;
}
// --------------------------------------------------------------------------
//  Stops the players turn
void
Board :: stop(){
    for(int k = 0; k < 3; k++){
        switch (towInCol[k]){
            case 0:
                cout << "No tower in Column\n";
                break;
            default:
                backBone[towInCol[k]]->stop(currP);
        }
    }
}
// --------------------------------------------------------------------------
//  Bust all the towers in column;
void
Board :: bust(){
    cout << "Busted!\n";
    for(int k = 0; k < 3; k++){
        switch (towInCol[k]){
            case 0:
                cout << "No tower in Column\n";
                break;
            default:
                backBone[towInCol[k]]->bust();
        }
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
