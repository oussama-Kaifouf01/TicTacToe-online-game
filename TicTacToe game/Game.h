#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Piece.h"

class Game
{
public:
   Game();
   ~Game();
   void StartGame();


protected:

	sf::RectangleShape Grid;
	sf::RenderWindow Window;

private:
   bool CheckWin();
   void DrawPieces();
   void NewGame();

   int Id;
   char Turn;
   char Winner;
   int EmptyPosition;
   char GridRef[3][3];
   sf::Texture GridTexture;
   Piece X;
   Piece O;


};
