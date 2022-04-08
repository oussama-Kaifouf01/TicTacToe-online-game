#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Piece
{
public:
	Piece();
	sf::RectangleShape GetPiece();
	void SetPiecePosition();
	void SwitchPieceTexture();

protected:
private:
	char Type;
	sf::RectangleShape PieceShape;
	sf::Texture PieceTexture;
	sf::Texture WinPieceTexture;


};
