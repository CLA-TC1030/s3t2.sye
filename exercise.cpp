#include <iostream>
#include "GameManual.hpp"
#include "GameAutomatic.hpp"
#include "Ctesconf.hpp"

int main()
{
//  GameManual gm("t1.tab", false, true);
//  GameAutomatic ga("t1.tab", false, true);

//  std::cout << "Juego Manual ...\n";
//  gm.start();

//  std::cout << "Juego Automatico ...\n";
//  ga.start();

    Game *g;

    if (GAME_TYPE == MANUAL)
    {
        g = new GameManual("t1.tab", false, true);
    }
    else {
        g = new GameAutomatic("t1.tab", false, true);
    }

    g->start();
    
    return 0;
}