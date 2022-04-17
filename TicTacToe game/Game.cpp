 
#include "Piece.h"
#include "Game.h"
 

Game::Game():
	Window(sf::VideoMode(700, 700), "Tic-Tac-Toe", sf::Style::Close),
	Grid(sf::Vector2f(466, 466)),
    X('X'),
    O('O')
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
            //check if a player has won
            //bool a = _CheckWin();
            
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
            if (_CheckWin())
            {
                std::cout << "winner:" << Winner << std::endl;
                std::cout << "-----" << std::endl;
            }
#pragma endregion
        

        }


#pragma endregion
        _DrawPieces();
        
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
    //Horizontal and Vertical
    int i = 0;
    bool Swap_row_col = false;
    auto getGridRef = [&](int i, int j)
    {
        if (!Swap_row_col)
            return Game::GridRef[i][j];
        else if (Swap_row_col)
            return Game::GridRef[j][i];
    };
swap_row_and_col:
    i = 0;
    while (i < 3)
    {
        if (getGridRef(i, 0) == getGridRef(i, 1) && getGridRef(i, 1)== getGridRef(i, 2)&& getGridRef(i, 0) != 'E')
        {
            Winner = getGridRef(i,0);
            goto winner_found;
        }
        i++;
    }
    if (Swap_row_col==false)
    {
        Swap_row_col = true;
        goto swap_row_and_col;
    }
    //Diagonal
    Swap_row_col = false;
    if (getGridRef(1, 1) != 'E')
    {
        if (getGridRef(0,0) == getGridRef(1, 1) && getGridRef(1, 1) == getGridRef(2, 2))
        {
            Winner = getGridRef(1, 1);
            goto winner_found;
        }
        else if (getGridRef(0,2) == getGridRef(1, 1) && getGridRef(1, 1) == getGridRef(2, 0))
        {
            Winner = getGridRef(1, 1);
            goto winner_found;
        }
    }
winner_found:
    if (Winner == ' ')
        return false;
    else if (Winner != ' ')
        return true;
}



void Game::_DrawPieces()
{
    int i;
    int j = 0;
    int x;
    int y = 100;
    while (j < 3)
    {
        i = 0;
        x = 100;
        while (i < 3)
        {
            if (GridRef[j][i] == 'O')
            {
                O.SetPiecePosition((x + 245) / 2, (y + 245) / 2);
                Window.draw(O.GetPiece());
            }
            else if (GridRef[j][i] == 'X')
            {
                X.SetPiecePosition((x + 245) / 2, (y + 245) / 2);
                Window.draw(X.GetPiece());
            }
            i++;
            x = x + 320;
        }
        y = y + 320;
        j++;
    }
}



void Game::_NewGame()
{
   // TODO : implement
}