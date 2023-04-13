//  dice.hpp
//  P1-Khamphouy
//  Dice library to roll dices from 1-10
//  Created by Tony Khamphouy on 1/22/23.
#ifndef dice_hpp
#define dice_hpp
#define fakeDie "fakeDie.txt"
#include "tools.hpp"
#include "enums.hpp"
class Dice{
protected:
    int nDice;     //number of dices
    int* rollDie; //array to hold the rolled dice
    int* pointer;
    int temp1;
    int temp2;
public:
    Dice(int n) : nDice(n), rollDie(new int[nDice]){ }
    Dice() : nDice(4), rollDie(new int[nDice]){ } //default constructor
    virtual ~Dice(){ delete [] rollDie; } //default destructor
    virtual const int* roll(); //rolls the dices and puts them in an array
    int fPair(char c, char h);
    int sPair() { return temp1 + temp2; }
    ostream& printDice(ostream& o) const;
};
inline ostream& operator <<( ostream& os, Dice& d ){ return d.printDice(os);}

class CantStopDice: public Dice {
protected:
    int totalDie[2];
    char diePair[2];
public:
    CantStopDice(): Dice(4) {}
    virtual ~CantStopDice() = default;
    virtual const int* roll();
};

class FakeDice: public CantStopDice {
private:
    ifstream fDie;
public:
    FakeDice(){ fDie.open(fakeDie, ifstream::in); }
    virtual const int* roll();
    virtual ~FakeDice(){ fDie.close(); }
};

#endif /* dice_hpp */
