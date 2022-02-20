#pragma once
#include "nepch.h"
#include "GameState.h"
#include "Ngine/Core/Button.h"

namespace Ngine {
    class MainMenuState :
        public State
    {

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~MainMenuState();

		/*FUNCTIONS*/
		void EndState();
		void UpdateInput(const float& dt);
		void UpdateButtons();
		void Update(const float& dt);
		void RenderButtons(sf::RenderTarget* target = nullptr);
		void Render(sf::RenderTarget* target = nullptr);

	private:
		/*VARS*/
		sf::RectangleShape background;
		sf::Font font;

		std::map<std::string, Button*> buttons;


		/*FUNCTIONS*/
		void InitFonts();
		void InitKeybinds();
		void InitButtons();

    };
}

