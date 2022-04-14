 
#include "Piece.h"
#include "Game.h"
 

Game::Game():
	Window(sf::VideoMode(700, 700), "Tic-Tac-Toe", sf::Style::Close),
	Grid(sf::Vector2f(466, 466))
{
    Turn = 'X';
    Winner = ' ';
	EmptyPositions = 9;
    GridTexture.loadFromFile("Resources/img/Grid.png");
    Grid.setTexture(&GridTexture);
	Grid.setPosition(100, 100);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            GridRef[i][j] = 'E';
        }
    }
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
        Window.draw(Grid);



#pragma region Game Logic

        //check if the player has clicked inside the grid and if no player has won yet
        if (IsMousePressed() && Winner==' ')
        {
            //detect what square has the player clicked on and save his move, only if the square is empty
            _setIndex(GetClickedPosition());
#pragma region Debug and test
            std::cout << "-----" << std::endl;
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++) 
                {

                    std::cout << GridRef[j][i] << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << "-----" << std::endl;

            ///////DEBUG/////////
#pragma endregion
        }


#pragma endregion



        Window.display();

    }
}


void Game::_setIndex(sf::Vector2i mousePosition)
{
    int x;
    int y = 100;
    int i = 0;
    int j;
    bool found;
    while (i < 3)
    {
        x = 100;
        j = 0;
        found = false;
        while (j < 3)
        {
            if (mousePosition.x > x && mousePosition.x < x + 145 && mousePosition.y > y && mousePosition.y < y + 145)
            {
                if (GridRef[i][j] == 'E')
                {
                    GridRef[i][j] = Turn;
                    EmptyPositions--;
                    found = true;

                    if (Turn == 'X')
                    {
                        Turn = 'O';
                    }
                    else if (Turn == 'O')
                    {
                        Turn = 'X';
                    }
                }
                found = true;
                break;
            }
            x = x + 160;
            j++;
        }
        if (found == true)
            break;
        y = y + 160;
        i++;
    }
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