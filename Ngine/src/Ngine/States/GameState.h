#pragma once
#include "nepch.h"
#include "State.h"

namespace Ngine {
	class GameState : public State
	{

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~GameState();

		/*FUNCTIONS*/
		void UpdateInput(const float& dt);
		void Update(const float& dt);
		void Render(sf::RenderTarget* target = nullptr);

	private:

		Entity player;

		/*FUNCTIONS*/
		void InitKeybinds();
	};
}


