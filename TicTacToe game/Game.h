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
   //method that contains the game loop
   void StartGame();


protected:
	//Shape of the grid: protected so it can be accessed from the inputHandler
	sf::RectangleShape Grid;
	//Window where the game will be displayed, protected so it can be accessed from the inputHandler
	sf::RenderWindow Window;


private:
	//method that find out in what square the player has clicked, then put the player's piece (x or o) in
	//the GridRef in the right index
	//Basically it detects what position in the grid was clicked
	void _setIndex(sf::Vector2i mousePosition = sf::Vector2i(0, 0));
	//method that checks if a player has won after each move
	bool _CheckWin();
	//method that draws the pieces in the grid
	void _DrawPieces();
	//method to start a new game and Reset the Winner, GirdRef, and EmptyPositions
	void _NewGame();

	/********************* Vritual methods *********************/
	//because the inputHandler function must be called inside the game loop we need to overload these functions

	virtual sf::Vector2i GetClickedPosition() = 0;
	virtual bool IsMousePressed() = 0;
	virtual void SetFocus(bool focus) = 0;
	virtual bool GetFocus() = 0;

	
	//id of the game, will be used in online mode
	int Id;
	//determine what piece should be placed (who gonna play next)
	char Turn;
	//Where the winner gonna be stocked (used to keep the grid getting inputs as long as there is no winner)
	char Winner;
	//Counts how many positions are left empty (used to tell if the game finished with no winner (DRAW))
	int EmptyPositions;
	//Data Structure to stock where X and O pieces are placed, Initially the array contains only 'E' which 
	//'E' stands for Empty position
	//'x'/'o' stands for normal 'X'/'O' Piece
	//'X'/'O' stands for winning 'X'/'O' Piece
	char GridRef[3][3];
	//Texture that should be linked to the grid Shape
	sf::Texture GridTexture;

	//X Piece
	Piece X;
	//O Piece
	Piece O;

	//


};
