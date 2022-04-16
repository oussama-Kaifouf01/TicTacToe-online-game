#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "InputHandler.h"
int main()
{
    //link the InputHandler with the Game in order to overload the virtual functions
    InputHandler ih;
    Game *newGame=&ih;
    
    newGame->StartGame();

    return 0;
}