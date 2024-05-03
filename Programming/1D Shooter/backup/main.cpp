#include <iostream>
#include "Game.h"

//using namespace sf;

int main()
{
    //Init srand
    std::srand(static_cast<unsigned> (time(nullptr)));

    //Init Game engine
    Game game;

    //Game loop
    while(game.running() and !game.getEndGame())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

    //End of appliccation
    return 0;
}
