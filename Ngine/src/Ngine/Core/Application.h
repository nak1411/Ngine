#pragma once
#include "Core.h"
#include "Ngine/States/State.h"
#include "Ngine/States/MainMenuState.h"

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
		void InitKeys();
		void InitStates();
		void EndApp();
		
		/*VARS*/
		sf::RenderWindow* window;
		sf::Event sfEvent;
		sf::Clock dtClock;

		float dt;

		// State is pointer due to being abstract therefore cannot be instantiated
		std::stack<State*> states;

		std::map<std::string, int> supportedKeys;

	};

	Application* CreateApplication();
}


