 
#include "InputHandler.h"

 
InputHandler::InputHandler()
{
}

 
InputHandler::~InputHandler()
{
   // TODO : implement
}


bool InputHandler::IsMousePressed()
{	//firstly check if the left button is pressed
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//then check if the pressed position is inside the gird, if not then the click will be ignored.
		if (sf::Mouse::getPosition(Game::Window).x > Grid.getPosition().x && sf::Mouse::getPosition(Game::Window).x < Grid.getPosition().x + Grid.getTexture()->getSize().x
			&& sf::Mouse::getPosition(Game::Window).y > Grid.getPosition().y && sf::Mouse::getPosition(Game::Window).y < Grid.getPosition().y + Grid.getTexture()->getSize().y)
		{
			return true;
		}
	}
	return false;
}
 
 sf::Vector2i InputHandler::GetClickedPosition()
{
	 //check if the the button is clicked and it's inside the gird only then the flag 'Clicked' will be enabled
	while (IsMousePressed())
	{
		 Clicked = true;
	}
	//only if the flag is enabled
	if(Clicked)
	{	// the method must return the clicked postion
		return sf::Mouse::getPosition(Game::Window);
	}
} 

//focus setter
void InputHandler::SetFocus(bool focus)
{
    Focus = focus;
}

//focus getter 
bool InputHandler::GetFocus()
{
    return Focus;
}
 
