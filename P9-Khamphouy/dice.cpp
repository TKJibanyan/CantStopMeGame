//  dice.cpp
//  P1-Khamphouy
//  Dice Library to roll dices from 1-10
//  Created by Tony Khamphouy on 1/22/23.
#include "dice.hpp"
int Dice::cnt = 0;
// ---------------------------------------------------------------------------
// Use to roll a random valued dice and puts it in the array
const int*
Dice :: roll(){
    cout <<"Rolling: " <<nDice <<" Die\n";
    for(int k = 0; k < nDice; k++)
    {
        rollDie[k] = rand() % 6 + 1;
    }
    return rollDie;
}
// ---------------------------------------------------------------------------
// Use to calculate the first pair
int
Dice :: fPair(char c, char h){
    int fVal = 0;
    int sVal = 0;
    temp2 = 0;
    temp1 = 0;
    for(int k = 0; k < 4; k++){
        if(dieLet[k] == c){
            fVal = rollDie[k];
        }
        else if(dieLet[k] == h){
            sVal = rollDie[k];
        }
        else{
            if(temp1 != 0){
                temp2 = rollDie[k];
            }
            else{
                temp1 = rollDie[k];
            }
        }
    }
    return fVal + sVal;
}
// ---------------------------------------------------------------------------
// Used to print out the array of dices
ostream&
Dice :: print(ostream& out) const{
    for( int k = 0; k < nDice; k++)
    {
        out << rollDie[k] << "[" << dieLet[k] << "] ";
    }
    return out;
}
// ---------------------------------------------------------------------------
// Used to roll the game dice
const int*
CantStopDice :: roll(){
    bool success = false;
    Dice::roll();
    while(success != true){
        try{
            Dice::print(cout);
            cout << "\nChoose 2 letters for your 1st pair: ";
            cin >> diePair[0] >> diePair[1];
            checkInput();
            totalDie[0] = Dice::fPair(toupper(diePair[0]), toupper(diePair[1]));
            cout << "Pair sum is: " << totalDie[0];
            totalDie[1] = Dice::sPair();
            cout << "\nSecond pair sum is: " << totalDie[1];
            success = true;
            return totalDie;
        }
        catch(BadChoice& bc){bc.print();}
    }
    return totalDie;
}
// ---------------------------------------------------------------------------
// Used to test the game
const int*
FakeDice :: roll(){
    int fVal, sVal, tVal, lVal = 0;
    int fTotal, sTotal = 0;
    fDice >> fVal >> sVal >> tVal >> lVal;
    temp1 = tVal;
    temp2 = lVal;
    fTotal = fVal + sVal;
    sTotal = tVal + lVal;
    totalDie[0] = fTotal;
    totalDie[1] = sTotal;
    cout << "Pair sum is: " << totalDie[0];
    cout << "\nSecond pair sum is: " << totalDie[1];
    return totalDie;
}
// --------------------------------------------------------------------------
//  checks input
void
CantStopDice :: checkInput(){
    if(toupper(diePair[0]) == toupper(diePair[1])) {
        throw DuplicateSlot(diePair[0], diePair[1]);
    }
    switch(toupper(diePair[0])){
        case 'A':
            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        default:
            throw BadSlot(diePair[0], diePair[1]);
    }
    switch(toupper(diePair[1])){
        case 'A':
            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        default:
            throw BadSlot(diePair[0], diePair[1]);
    }
}


