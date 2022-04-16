#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Piece
{
public:
	Piece(char type);
	//Returns the piece's shape (in order to draw it in the window)
	sf::RectangleShape GetPiece();
	//changes the position of the piece
	void SetPiecePosition(float x, float y);
	//switch the texture of the position beetwen, normal and winning piece
	void SwitchPieceTexture();

protected:
private:
	//the type of the piece (X or O)
	char Type;
	//the shape of the piece
	sf::RectangleShape PieceShape;
	//the texture of the normal piece (while playing piece)
	sf::Texture PieceTexture;
	//the texture of the winning piece (after winning piece)
	sf::Texture WinPieceTexture;


};
