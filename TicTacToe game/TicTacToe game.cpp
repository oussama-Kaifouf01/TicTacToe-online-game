#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "InputHandler.h"
#define LOG(x) std::cout << x <<std::endl; 
int main()
{
    //link the InputHandler with the Game in order to overload the virtual functions
    InputHandler ih;
    Game *newGame=&ih;
    
    newGame->StartGame();

    auto gridRef = [&](int a, int b, bool swap)
    {
        if (swap)
            return a + b;
        else if (!swap)
            return a * b;

    };

   
    LOG(gridRef(2, 5,false));
    


    return 0;
}