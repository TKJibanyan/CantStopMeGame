//  dice.hpp
//  P1-Khamphouy
//  Dice library to roll dices from 1-10
//  Created by Tony Khamphouy on 1/22/23.
#ifndef dice_hpp
#define dice_hpp
#define fakeDice "fakeDie.txt"
#include "enums.hpp"
#include "badchoice.hpp"
class Dice{
protected:
    int nDice;     //number of dices
    int* rollDie; //array to hold the rolled dice
    int temp1;
    int temp2;
public:
    static int cnt;
    Dice(int n) : nDice(n), rollDie(new int[nDice]){cnt++;
        cerr <<"Dice Allocated:"<<cnt <<"\n";}
    Dice() : nDice(4), rollDie(new int[nDice]){ } //default constructor
    virtual ~Dice(){ delete [] rollDie;cnt--;
        cerr << "Dice Deallocated:" <<cnt <<"\n";}
    virtual const int* roll(); //rolls the dices and puts them in an array
    int fPair(char c, char h);
    int sPair() const { return temp1 + temp2; }
    ostream& print(ostream& o) const;
};
inline ostream& operator <<( ostream& os, Dice& d ){ return d.print(os);}

class CantStopDice: public Dice {
protected:
    int totalDie[2];
    char diePair[2];
    void checkInput();
public:
    CantStopDice(): Dice(4) {}
    virtual ~CantStopDice() = default;
    virtual const int* roll();
};

class FakeDice: public CantStopDice {
private:
    ifstream fDice;
public:
    FakeDice(){ fDice.open(fakeDice, ifstream::in); }
    virtual const int* roll();
    virtual ~FakeDice(){ fDice.close(); }
};

#endif /* dice_hpp */

