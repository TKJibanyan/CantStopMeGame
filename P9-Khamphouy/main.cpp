//  main.cpp
//  P11-Khamphouy
//  Created by Tony Khamphouy on 5/1/23.
#include "game.hpp"
void testGame(Game* g);
int main(int argc, const char * argv[]) {
    banner();
    Game gameOne;
    testGame(&gameOne);
    bye();
    return 0;
}

void testGame( Game* g ){
    g->play();
}

