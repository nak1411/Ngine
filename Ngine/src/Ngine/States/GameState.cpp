#include "nepch.h"
#include "GameState.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
		: State(window, supportedKeys, states) // ("super" in Java)
	{
		this->InitKeybinds();
		this->map.CreateBlock();
	}

	Ngine::GameState::~GameState()
	{

	}

#pragma endregion

#pragma region INITIALIZERS

	void GameState::InitKeybinds()
	{
		/*Pull specific keybinds from config file*/
		std::ifstream ifs("conf/gamestate_keybinds.ini");

		if (ifs.is_open())
		{
			std::string key = "";
			std::string key2 = "";
			while (ifs >> key >> key2)
			{
				this->keybinds[key] = this->supportedKeys->at(key2);
			}
		}
		ifs.close();
		/**************************************/
	}

#pragma endregion

#pragma region FUNCTIONS

	void GameState::Update(const float& dt)
	{
		this->UpdateMousePositions();
		this->UpdateInput(dt);
		this->map.Update(dt);
	}

	void GameState::Render(sf::RenderTarget* target)
	{
		if (!target)
		{
			target = this->window;
		}
			this->map.Render(target);
	}

	void GameState::UpdateInput(const float& dt)
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		{															   
			this->block->Move(dt, 0.f, -1.f);
		}															   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		{															   
			this->block->Move(dt, -1.f, 0.f);
		}															   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		{															   
			this->block->Move(dt, 0.f, 1.f);
		}															   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		{
			this->block->Move(dt, 1.f, 0.f);
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		{
			this->EndState();
		}
	}

#pragma endregion

}