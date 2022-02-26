#include "nepch.h"
#include "SettingsState.h"


namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
		: State(window, supportedKeys, states), isShown(false) // ("super" in Java)
	{
		this->InitVariables();
		this->InitBackground();
		this->InitFonts();
		this->InitKeybinds();
		this->InitGui();
		this->setup = false;
		this->fullscreen = false;
		this->style = sf::Style::Default;

		this->buttons["RESOLUTION"] = new gui::Button(100, 100, 200, 50,
			&this->font, "RESOLUTION",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		this->buttons["WINDOW"] = new gui::Button(100, 160, 200, 50,
			&this->font, "WINDOW",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		this->buttons["BACK"] = new gui::Button(100, 220, 200, 50,
			&this->font, "BACK",
			sf::Color(70, 70, 70, 200),
			sf::Color(150, 150, 150, 255),
			sf::Color(20, 20, 20, 200));

		/*std::string resolutionSettings[] = {"800X600", "1920X1080", "2560X1440"};
		std::string windowSettings[] = {"WINDOWED", "FULLSCREEN"};
		float xPos = 310;
		float yPos = 100;
		float xOff = 210;
		float yOff = 0;
		this->dropdownButtons.push_back(new gui::DropDownMenu(xPos, yPos, xOff, yOff, font, resolutionSettings, 3));
		this->dropdownButtons.push_back(new gui::DropDownMenu(xPos, yPos, xOff, 60, font, windowSettings, 2));*/

		
	}

	Ngine::SettingsState::~SettingsState()
	{
		auto it = this->buttons.begin();
		for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
		{
			delete it->second;
		}

		for (auto & i : dropdownButtons)
		{
			delete i;
		}
	}

#pragma endregion

#pragma region INITIALIZERS

	void SettingsState::InitVariables()
	{

	}

	void SettingsState::InitBackground()
	{
		this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

		if (!this->backgroundTexture.loadFromFile("res/images/settings_bg.png"))
		{
			NE_CORE_ERROR("SETTINGSSTATE::COULD NOT LOAD BACKGROUND IMAGE");
			return;
		}
		this->background.setTexture(&this->backgroundTexture);
	}

	void SettingsState::InitFonts()
	{
		// Load in font file
		if (!this->font.loadFromFile("fonts/unispace-bd.ttf"))
		{
			NE_CORE_ERROR("ERROR::SETTINGSSTATE:: COULD NOT LOAD FONT");
		}
	}

	void SettingsState::InitKeybinds()
	{
		/*Pull specific keybinds from config file*/
		std::ifstream ifs("conf/settingsstate_keybinds.ini");

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

	void SettingsState::InitGui()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	void SettingsState::Update(const float& dt)
	{
		this->UpdateMousePositions();
		this->UpdateInput(dt);
		this->UpdateGui();
	}

	void SettingsState::RenderGui(sf::RenderTarget* target)
	{
		// Iterate through button map and execute each buttons render
		for (auto& it : this->buttons)
		{
			it.second->Render(target);
		}

		if (this->isShown)
		{
			// Iterate through dropdown button map and execute each buttons render
			for (auto& it : this->dropdownButtons)
			{
				it->Render(target);
			}
		}
	}

	void SettingsState::Render(sf::RenderTarget* target)
	{
		if (!target)
		{
			target = this->window;
		}

		target->draw(this->background);

		this->RenderGui(target);

		/* DEBUG::Show mouse coords next to cursor*/
		sf::Text mouseText;
		mouseText.setPosition(this->mousePosView.x + 20, this->mousePosView.y);
		mouseText.setFont(this->font);
		mouseText.setColor(sf::Color::White);
		mouseText.setCharacterSize(12);

		std::stringstream ss;
		ss << this->mousePosView.x << "\n\n" << this->mousePosView.y;
		mouseText.setString(ss.str());
		target->draw(mouseText);
		/******************************************/
	}

	void SettingsState::UpdateInput(const float& dt)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		{
			this->EndState();
		}
	}

	void SettingsState::UpdateGui()
	{	
		std::cout << this->isShown << std::endl;
		// Iterate through button map and execute each buttons update
		for (auto& it : this->buttons)
		{
			it.second->Update(this->mousePosView);
		}

		if (this->isShown)
		{
			for (auto& it : this->dropdownButtons)
			{
				it->Update(this->mousePosView);
			}
		}

		if (this->buttons["RESOLUTION"]->IsPressed())
		{

			if (this->isShown)
			{
				this->isShown = false;

			}
			else
			{
				this->isShown = true;
			}
			if (this->isShown)
			{
				std::string resolutionSettings[] = { "800X600", "1920X1080", "2560X1440"};
				float xPos = 310;
				float yPos = 100;
				float xOff = 210;
				float yOff = 0;
				this->dropdownButtons.push_back(new gui::DropDownMenu(xPos, yPos, xOff, yOff, font, resolutionSettings, 2));
			}
		}

	
		// Resolution 
		if (this->buttons["WINDOW"]->IsPressed())
		{
			
			if (this->isShown)
			{
				this->isShown = false;
			}
			else
			{
				this->isShown = true;
			}
			if (this->isShown)
			{
				std::string windowSettings[] = { "WINDOWED", "FULLSCREEN" };
				float xPos = 310;
				float yPos = 100;
				float xOff = 210;
				float yOff = 0;
				this->dropdownButtons.push_back(new gui::DropDownMenu(xPos, yPos, xOff, 60, font, windowSettings, 2));
				

			}
		}

		//Back to main menu
		if (this->buttons["BACK"]->IsPressed())
		{
			this->EndState();
		}
	}

#pragma endregion

}