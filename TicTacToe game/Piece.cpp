
#include "Piece.h"


Piece::Piece(char type):PieceShape(sf::Vector2f(160, 160))
{
	Type = type;
	PieceTexture.loadFromFile("Resources/img/"+ std::string(1, type) +".png");
	PieceShape.setTexture(&PieceTexture);
	PieceShape.setOrigin(80, 80);
	WinPieceTexture.loadFromFile("Resources/img/" + std::string(1, type) + " Win.png");
}


sf::RectangleShape Piece::GetPiece()
{
	return PieceShape;
}


void Piece::SetPiecePosition(float x, float y)
{
	PieceShape.setPosition(x, y);
}


void Piece::SwitchPieceTexture()
{
	if (PieceShape.getTexture() == &PieceTexture)
		PieceShape.setTexture(&WinPieceTexture);
	else if (PieceShape.getTexture() == &WinPieceTexture)
		PieceShape.setTexture(&PieceTexture);
}