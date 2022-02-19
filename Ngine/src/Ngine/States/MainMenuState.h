#pragma once
#include "nepch.h"
#include "GameState.h"

namespace Ngine {
    class MainMenuState :
        public State
    {

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		virtual ~MainMenuState();

		/*FUNCTIONS*/
		void EndState();
		void UpdateInput(const float& dt);
		void Update(const float& dt);
		void Render(sf::RenderTarget* target = nullptr);

	private:
		/*VARS*/
		sf::RectangleShape background;

		/*FUNCTIONS*/
		void InitKeybinds();

    };
}

