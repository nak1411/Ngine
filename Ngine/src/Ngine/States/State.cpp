#include "nepch.h"
#include "State.h"


namespace Ngine {

	/*
	* CONSTRUCTOR/DESTRUCTOR
	*/
	State::State(sf::RenderWindow* window)
	{
		this->window = window;
		this->quit = false;
	}

	State::~State()
	{

	}

	/*
	* FUNCTIONS
	*/
	const bool& State::isQuitting() const
	{
		return this->quit;
	}

	void State::CheckForQuit()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->quit = true;
		}
	}
}


