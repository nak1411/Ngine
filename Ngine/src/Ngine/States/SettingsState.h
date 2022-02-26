#pragma once
#include "nepch.h"
#include "GameState.h"
#include "Ngine/Gui/Gui.h"

namespace Ngine {
	class SettingsState :
		public State
	{

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~SettingsState();

		/*FUNCTIONS*/
		void UpdateInput(const float& dt);
		void UpdateGui();
		void Update(const float& dt);
		void RenderGui(sf::RenderTarget* target = nullptr);
		void Render(sf::RenderTarget* target = nullptr);

	private:
		/*VARS*/
		sf::Texture backgroundTexture;
		sf::RectangleShape background;
		sf::Font font;
		bool setup;
		bool fullscreen;
		bool style;
		bool isShown;

		std::string resolutionSettings[3] = { "800X600", "1920X1080", "2560X1440" };
		std::string windowSettings[2] = { "WINDOWED", "FULLSCREEN" };
		std::map<std::string, gui::Button*> buttons;
		std::vector<gui::DropDownMenu*> dropdownButtons;

		/*FUNCTIONS*/
		void InitVariables();
		void InitBackground();
		void InitFonts();
		void InitKeybinds();
		void InitGui();
	};
}

