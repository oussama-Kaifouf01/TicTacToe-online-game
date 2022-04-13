#pragma once
#include <SFML/Window.hpp>
#include <string>
#include "Game.h"
class InputHandler : public Game
{
public:
	InputHandler();
	~InputHandler();
	//check if the mouse is pressed
	bool IsMousePressed();
	//returns the the current position of the mouse in window coordinates.
	sf::Vector2i GetClickedPosition();
	//check if window in focus or not
	bool GetFocus();
	//Enable Focus to the window
	void SetFocus(bool focus);

protected:
private:
	//right-click flag
	bool Clicked;
	//focus flag
	bool Focus;
	//the right-clicked position
	sf::Vector2i PositionClicked;


};
