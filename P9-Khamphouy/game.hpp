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
    unique_ptr<Dice> fourDie;
    spt users[3] = {};
    unique_ptr<Board> board;
    unique_ptr<CList<spt>> clst;
    bool avalCol[5];
public:
    Game():fourDie(new FakeDice()), board(new Board()),
    clst(new CList<spt>()){
        getNewPlayer();
        clst->init();
    }
    ~Game() = default; //Dont need to call delete
    void getNewPlayer();
    spt getPlay(){return clst->nextPlayer();}
    // ---------------------------------------------------------------------------
    // Testing functions to interact with other classes
    void rollDie();   //rolls die
    void printName();  //prints player name and color
    void oneTurn(spt p);
    void startPlay();
    void stopPlay();
    void moveTow(int a); //moves tower
    void printCol(); //prints columns
};

#endif /* game_hpp */
