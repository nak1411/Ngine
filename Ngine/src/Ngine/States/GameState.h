#pragma once
#include "nepch.h"
#include "Ngine/Map/Block.h"
#include "State.h"
#include "Ngine/Map/Map.h"

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

		Map map;

		/*FUNCTIONS*/
		void InitKeybinds();
	};
}


