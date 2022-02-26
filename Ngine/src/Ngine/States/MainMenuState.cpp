#include "nepch.h"
#include "MainMenuState.h"


namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
		: State(window, supportedKeys, states) // ("super" in Java)
	{
		this->InitVariables();
		this->InitBackground();
		this->InitFonts();
		this->InitKeybinds();
		this->InitGui();

		this->buttons["GAME_STATE"] = new gui::Button(100, 100, 150, 50,
			&this->font, "New Game",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		this->buttons["SETTINGS_STATE"] = new gui::Button(100, 160, 150, 50,
			&this->font, "Settings",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		this->buttons["EXIT_STATE"] = new gui::Button(100, 220, 150, 50,
			&this->font, "Quit",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));
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

	void MainMenuState::InitVariables()
	{

	}

	void MainMenuState::InitBackground()
	{
		this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

		if (!this->backgroundTexture.loadFromFile("res/images/mainmenu_bg.png"))
		{
			NE_CORE_ERROR("MAINMENUSTATE::COULD NOT LOAD BACKGROUND IMAGE");
			return;
		}
		this->background.setTexture(&this->backgroundTexture);
	}

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

	void MainMenuState::InitGui()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	void MainMenuState::Update(const float& dt)
	{
		this->UpdateMousePositions();
		this->UpdateInput(dt);
		this->UpdateGui();
	}

	void MainMenuState::RenderGui(sf::RenderTarget* target)
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

		this->RenderGui(target);

		sf::Text mouseText;
		mouseText.setPosition(this->mousePosView.x + 20, this->mousePosView.y);
		mouseText.setFont(this->font);
		mouseText.setColor(sf::Color::White);
		mouseText.setCharacterSize(12);
		
		std::stringstream ss;
		ss << this->mousePosView.x << "\n\n" << this->mousePosView.y;
		mouseText.setString(ss.str());
		target->draw(mouseText);
	}

	void MainMenuState::UpdateInput(const float& dt)
	{

	}

	void MainMenuState::UpdateGui()
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

		// Settings
		if (this->buttons["SETTINGS_STATE"]->IsPressed())
		{
			this->states->push(new SettingsState(this->window, this->supportedKeys, this->states));
		}

		// Quit game
		if (this->buttons["EXIT_STATE"]->IsPressed())
		{
			this->EndState();
		}
	}

#pragma endregion

}
