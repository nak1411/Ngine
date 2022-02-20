#include "nepch.h"
#include "State.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	{
		this->InitVariables();

		this->window = window;
		this->supportedKeys = supportedKeys;
		this->states = states;
		this->quit = false;
	}

	State::~State()
	{

	}

#pragma endregion

#pragma region INITIALIZERS

	void State::InitKeybinds()
	{

	}

	void State::InitVariables()
	{
		this->window = nullptr;
		this->quit = false;
	}

#pragma endregion


#pragma region FUNCTIONS

	const bool& State::isQuitting() const
	{
		return this->quit;
	}

	void State::EndState()
	{
		this->quit = true;
	}

	void State::UpdateMousePositions()
	{
		this->mousePosScreen = sf::Mouse::getPosition();
		this->mousePosWindow = sf::Mouse::getPosition(*this->window);
		this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	}

#pragma endregion

}


