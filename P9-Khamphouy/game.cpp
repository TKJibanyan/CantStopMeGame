//  game.cpp
//  P4-Khamphouy
//  Created by Tony Khamphouy on 2/13/23.
#include "game.hpp"
// ---------------------------------------------------------------------------
// Use to add a new player with name and color
void
Game :: getNewPlayer(){
    do{
        cout <<"How many players will play. Choose from 2-4: ";
        cin >> playNum;
    }while(playNum < 2 || playNum > 4);
    for( int j = 0; j < playNum; j++ ){
        clst.addCell(clst.next());
    }
    clst.init();
}
// ---------------------------------------------------------------------------
// One turn of the game
void
Game :: oneTurn(sharedpt p){
    int fP, sP = 0;
    bool success = false;
    board.startTurn(p);
    cout << "\n\nCurrent Player:\t" << *p;
    while(success != true){
        try{
            cout << "\nWould you like to: Roll[1], Stop[2], Or Resign[3]\n";
            //cin >> in; //uncomment to play fake game
            fRoll >> rollVal; //comment out to use real dice
            cout << rollVal << "\n"; // comment out to use real dice
            checkInput();
            switch(rollVal){ //chance rollVal to in
                case 1:
                    fP = *fourDice->roll();
                    sP = fourDice->sPair();
                    if(board.move(fP) == false && board.move(sP) == false){
                        board.bust();
                        break;
                    }
                    board.move(sP);
                    cout << "\n" << board << "\n";
                    continue;
                case 2:
                    board.stop();
                    cout << "\n" << board << "\n";
                    break;
                case 3:
                    clst.remove();
                    break;
            }
            success = true;
            break;
        }
        catch (BadChoice& bc){bc.print();}
    }
}
// --------------------------------------------------------------------------
//  Plays whole game
void
Game :: play(){
    stat = EStatus::Begun;
    cout <<status[0] << "\n";
    for(;;){
        if(empty()){
            stat = EStatus::Quit;
            cout << "\n" <<status[(int)stat] << "\n";
            break;
        }
        if(won()){
            stat = EStatus::Done;
            cout << clst;
            cout << "\n" <<status[(int)stat] << "\n";
            break;
        }
        oneTurn(getPlay());
    }
}
// ---------------------------------------------------------------------------
// checks input from player
void
Game :: checkInput(){
    //if(in < 1 || in > 3) throw BadChoice(); //uncomment to play real game
    if(rollVal < 1 || rollVal > 3) throw BadChoice(); //comment to play real
}
// ---------------------------------------------------------------------------
// Use to call the roll function from Dice and print
void
Game :: rollDice(){
    fourDice->roll();
    cout << *fourDice << "\n";
}


