#include "nepch.h"
#include "State.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	{
		this->window = window;
		this->supportedKeys = supportedKeys;
		this->quit = false;
	}

	State::~State()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	const bool& State::isQuitting() const
	{
		return this->quit;
	}

	void State::CheckForQuit()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		{
			this->quit = true;
		}
	}

#pragma endregion

}


