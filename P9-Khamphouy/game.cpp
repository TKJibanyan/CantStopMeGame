//  game.cpp
//  P4-Khamphouy
//  Created by Tony Khamphouy on 2/13/23.
#include "game.hpp"
// ---------------------------------------------------------------------------
// Use to add a new player with name and color
void
Game :: getNewPlayer(){
    cout <<"How many players will play. Choose from 2-4: ";
    cin >> playNum;
    while( playNum < 2 || playNum > 4 ){
        cout <<"How many players will play. Choose from 2-4: ";
        cin >> playNum;
    }
    for( int j = 0; j < playNum; j++ ){
        clst->addCell(clst->next());
    }
}
// ---------------------------------------------------------------------------
// One turn of the game
void
Game :: oneTurn(spt p){
    int in = 0;
    int fP = 0;
    int sP = 0;
    board->startTurn(p);
    cout << *p;
    string menu = "\nWould you like to: Roll[1], Stop[2], Or Resign[3]\n";
    for(;;){
        cout << menu;
        cin >> in;
        switch(in){
            case 1:
                fP = *fourDie->roll();
                sP = fourDie->sPair();
                if(board->move(fP) == false && board->move(sP) == false){
                    board->bust();
                    break;
                }
                moveTow(sP);
                printCol();
                continue;
            case 2:
                board->stop();
                printCol();
                break;
            case 3:
                clst->remove();
                break;
        }
        break;
    }
}
// ---------------------------------------------------------------------------
// Use to call the roll function from Dice and print
void
Game :: rollDie(){
    fourDie->roll();
    cout << *fourDie << "\n";
}
// ---------------------------------------------------------------------------
// Use to call the print function from Player
void
Game :: printName(){
    cout << *clst << "\n";
}
// ---------------------------------------------------------------------------
// Delegation calling from board to start
void
Game :: startPlay(){
    board->startTurn(users[0]);
}
// ---------------------------------------------------------------------------
// Use to call the move function from Column
void
Game :: moveTow(int a){
    board->move(a);
}
// ---------------------------------------------------------------------------
// Delegation calling stop from board
void
Game :: stopPlay(){
    board->stop();
}
// ---------------------------------------------------------------------------
// Use to call the print function from Column
void
Game :: printCol(){
    cout << "\n" << *board << "\n";
}
