 
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

        }
        GridTexture.loadFromFile("Resources/img/Grid.png");
        Grid.setTexture(&GridTexture);
        Grid.setPosition(100, 100);
        Window.clear();
        Window.draw(Grid);
        Window.display();

    }
}


void Game::_setIndex(sf::Vector2i mousePosition)
{
	// TODO : implement
}

bool Game::CheckWin()
{
   // TODO : implement
}



void Game::DrawPieces()
{
   // TODO : implement
}



void Game::_NewGame()
{
   // TODO : implement
}