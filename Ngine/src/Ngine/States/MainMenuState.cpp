#include "nepch.h"
#include "MainMenuState.h"


namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
		: State(window, supportedKeys, states) // ("super" in Java)
	{
		this->InitFonts();
		this->InitKeybinds();
		this->InitButtons();

		this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
			&this->font, "New Game",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
			&this->font, "Quit",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));


		this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
		this->background.setFillColor(sf::Color::Magenta);
	}

	Ngine::MainMenuState::~MainMenuState()
	{
		auto it = this->buttons.begin();
		for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
		{
			delete it->second;
		}
		
	}

#pragma endregion

#pragma region INITIALIZERS

	void MainMenuState::InitFonts()
	{
		// Load in font file
		if (!this->font.loadFromFile("fonts/unispace-bd.ttf"))
		{
			NE_CORE_ERROR("ERROR::MAINMENUSTATE:: COULD NOT LOAD FONT");
		}
	}

	void MainMenuState::InitKeybinds()
	{
		/*Pull specific keybinds from config file*/
		std::ifstream ifs("conf/mainmenustate_keybinds.ini");

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

	void MainMenuState::InitButtons()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	void MainMenuState::Update(const float& dt)
	{
		this->UpdateMousePositions();
		this->UpdateInput(dt);
		this->UpdateButtons();

		
		NE_CORE_ERROR(std::to_string(this->mousePosWindow.x) + " " + std::to_string(this->mousePosWindow.y));
	}

	void MainMenuState::RenderButtons(sf::RenderTarget* target)
	{
		// Iterate through button map and execute each buttons render
		for (auto& it : this->buttons)
		{
			it.second->Render(target);
		}
	}

	void MainMenuState::Render(sf::RenderTarget* target)
	{
		if (!target)
		{
			target = this->window;
		}

		target->draw(this->background);

		this->RenderButtons(target);
	}

	void MainMenuState::UpdateInput(const float& dt)
	{
		this->CheckForQuit();

	}

	void MainMenuState::UpdateButtons()
	{
		// Iterate through button map and execute each buttons update
		for(auto &it : this->buttons)
		{
			it.second->Update(this->mousePosView);
		}

		// New game
		if (this->buttons["GAME_STATE"]->IsPressed())
		{
			this->states->push(new GameState(this->window, this->supportedKeys, this->states));
		}

		// Quit game
		if (this->buttons["EXIT_STATE"]->IsPressed())
		{
			this->EndState();
		}
	}

	void MainMenuState::EndState()
	{
		NE_CORE_INFO("MAINMENU STATE ENDED");
		this->quit = true;
	}

#pragma endregion

}
