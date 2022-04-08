#pragma once
#include <SFML/Window.hpp>
#include <string>
#include "Game.h"
class InputHandler : public Game
{
public:
	InputHandler();
	~InputHandler();
	sf::Vector2i GetClickedPosition();
	void Setfocus();
	bool Getfocus();
	bool IsMousepressed();

protected:
private:
	bool Clicked;
	bool Focus;
	sf::Vector2i PositionClicked;


};
