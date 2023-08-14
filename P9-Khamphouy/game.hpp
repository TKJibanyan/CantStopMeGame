//  game.hpp
//  P4-Khamphouy
//  Created by Tony Khamphouy on 2/13/23.
#ifndef game_hpp
#define game_hpp

#include "dice.hpp"
#include "board.hpp"
#include "clist.hpp"
class Game {
private:
    int playNum;
    int in;
    int rollVal = 0;
    ifstream fRoll;
    unique_ptr<Dice> fourDice;
    Board board;
    CList<sharedpt> clst;
    EStatus stat;
    void checkInput();
public:
    Game():fourDice(new FakeDice()), board(Board()),
    clst(CList<sharedpt>()){
        getNewPlayer();
        fRoll.open("fakeRoll.txt", ifstream::in);
    }
    ~Game() {fRoll.close();} //Dont need to call delete
    void getNewPlayer();
    sharedpt getPlay() {return clst()->pData;}
    // ------------------------------------------------------------------------
    // Testing functions to interact with other classes
    void rollDice();   //rolls die
    bool won(){if(clst.next()->pData->score() == 3) return true;
        return false;}
    bool empty(){if(clst.empty())return true; return false;}
    void oneTurn(sharedpt p);
    void play();
};

#endif /* game_hpp */

