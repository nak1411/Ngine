#pragma once
#include "nepch.h"
#include "GameState.h"
#include "SettingsState.h"
#include "Ngine/Gui/Gui.h"

namespace Ngine {
    class MainMenuState :
        public State
    {

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~MainMenuState();

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

		std::map<std::string, gui::Button*> buttons;


		/*FUNCTIONS*/
		void InitVariables();
		void InitBackground();
		void InitFonts();
		void InitKeybinds();
		void InitGui();

    };
}

