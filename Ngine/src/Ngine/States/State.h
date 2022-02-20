#pragma once
#include "nepch.h"
#include "Ngine/Entities/Entity.h"

namespace Ngine {
	// Abstract Class
	class State
	{

	private:

	protected:
		/*VARS*/
		// Points to the universal stack of state pointers in Application
		std::stack<State*>* states;

		sf::RenderWindow* window;;
		std::map<std::string, int>* supportedKeys;
		std::map<std::string, int> keybinds;
		bool quit;

		sf::Vector2i mousePosScreen;
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		std::vector<sf::Texture> textures;

		/*FUNCTIONS*/
		void InitVariables();
		virtual void InitKeybinds() = 0;
		
		
	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~State();

		const bool& isQuitting() const;

		/*FUNCTIONS*/
		void EndState();

		// Pure virtual - derived classes MUST implement these
		virtual void UpdateMousePositions();
		virtual void UpdateInput(const float& dt) = 0;
		// Get reference to dt from application
		virtual void Update(const float& dt) = 0;
		// Set default target window context  
		virtual void Render(sf::RenderTarget* target = nullptr) = 0;

	};
}

