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
		sf::RenderWindow* window;
		std::map<std::string, int>* supportedKeys;
		std::map<std::string, int> keybinds;
		bool quit;

		std::vector<sf::Texture> textures;

		/*FUNCTIONS*/
		virtual void InitKeybinds() = 0;
		
		
	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		virtual ~State();

		const bool& isQuitting() const;

		/*FUNCTIONS*/
		virtual void CheckForQuit();

		// Pure virtual - derived classes MUST implement these
		virtual void EndState() = 0;
		virtual void UpdateInput(const float& dt) = 0;
		// Get reference to dt from application
		virtual void Update(const float& dt) = 0;
		// Set default target window context  
		virtual void Render(sf::RenderTarget* target = nullptr) = 0;

	};
}

