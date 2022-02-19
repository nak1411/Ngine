#pragma once
#include"nepch.h"
#include "State.h"

namespace Ngine {
	class GameState : public State
	{

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		GameState(sf::RenderWindow* window);
		virtual ~GameState();

		/*FUNCTIONS*/
		void EndState();
		void UpdateKeybinds(const float& dt);
		void Update(const float& dt);
		void Render(sf::RenderTarget* target = nullptr);

	private:

		Entity player;
		
	};
}


