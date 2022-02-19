#include "nepch.h"
#include "GameState.h"

namespace Ngine {

	/*
	* CONSTRUCTOR/DESTRUCTOR
	*/	
	Ngine::GameState::GameState(sf::RenderWindow* window) 
		: State(window) //("super" in Java)
	{

	}

	Ngine::GameState::~GameState()
	{

	}

	/*
	* FUNCTIONS
	*/
	void GameState::Update(const float& dt)
	{
		this->UpdateKeybinds(dt);
		this->player.Update(dt);
	}

	void GameState::Render(sf::RenderTarget* target)
	{
		if (target)
		{

		}
		else
		{
			this->player.Render(this->window);
		}
		
	}

	void GameState::UpdateKeybinds(const float& dt)
	{
		this->CheckForQuit();
	}

	void GameState::EndState()
	{
		NE_CORE_INFO("STATE ENDED");
	}
}