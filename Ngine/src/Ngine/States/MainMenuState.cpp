#include "nepch.h"
#include "MainMenuState.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
		: State(window, supportedKeys) // ("super" in Java)
	{
		this->InitKeybinds();
		this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
		this->background.setFillColor(sf::Color::Magenta);
	}

	Ngine::MainMenuState::~MainMenuState()
	{

	}

#pragma endregion

#pragma region INITIALIZER

	void MainMenuState::InitKeybinds()
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

	void MainMenuState::Update(const float& dt)
	{
		this->UpdateInput(dt);
	}

	void MainMenuState::Render(sf::RenderTarget* target)
	{
		if (!target)
		{
			target = this->window;
		}

		target->draw(this->background);
	}

	void MainMenuState::UpdateInput(const float& dt)
	{
		this->CheckForQuit();

	}

	void MainMenuState::EndState()
	{
		NE_CORE_INFO("MAINMENU STATE ENDED");
	}

#pragma endregion

}
