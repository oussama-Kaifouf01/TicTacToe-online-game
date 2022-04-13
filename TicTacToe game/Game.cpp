 
#include "Piece.h"
#include "Game.h"
 

Game::Game():
	Window(sf::VideoMode(700, 700), "Tic-Tac-Toe", sf::Style::Close),
	Grid(sf::Vector2f(466, 466))
{
	EmptyPositions = 9;
    GridTexture.loadFromFile("Resources/img/Grid.png");
    Grid.setTexture(&GridTexture);
	Grid.setPosition(100, 100);
}



Game::~Game()
{
   // TODO : implement
}



void Game::StartGame(void)
{

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
            else if (event.type == sf::Event::GainedFocus)
                SetFocus(true);
            else if (event.type == sf::Event::LostFocus)
                SetFocus(false);

        }
        Window.clear();
        //Testing the input Handler
        if(IsMousePressed())
            std::cout << GetClickedPosition().x << " ; " << GetClickedPosition().y <<std::endl;
        
        Window.draw(Grid);
        Window.display();

    }
}


void Game::_setIndex(sf::Vector2i mousePosition)
{
	// TODO : implement
}

bool Game::_CheckWin()
{
   // TODO : implement
}



void Game::_DrawPieces()
{
   // TODO : implement
}



void Game::_NewGame()
{
   // TODO : implement
}