#pragma once
#include "nepch.h"
#include "Core.h"
#include "States/State.h"
#include "States/GameState.h"


namespace Ngine {

	class NGINE_API Application
	{
	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		Application();
		virtual ~Application();
		
		/*FUNCTIONS*/ 
		void Run();
		void Update();
		void UpdateDt();
		void UpdateSFMLEvents();
		void Render();

	private:
		/*FUNCTIONS*/
		void InitWindow();
		void InitStates();
		void EndApp();
		
		/*VARS*/
		sf::RenderWindow* window;
		sf::Event sfEvent;
		sf::Clock dtClock;

		float dt;

		// State is pointer due to being abstract therefore cannot be instantiated
		std::stack<State*> states;

	};

	Application* CreateApplication();
}

