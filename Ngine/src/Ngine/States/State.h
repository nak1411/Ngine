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
		std::vector<sf::Texture> textures;
		bool quit;
		
	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		State(sf::RenderWindow* window);
		virtual ~State();

		const bool& isQuitting() const;

		/*FUNCTIONS*/
		virtual void CheckForQuit();

		// Pure virtual - derived classes MUST implement these
		virtual void EndState() = 0;
		virtual void UpdateKeybinds(const float& dt) = 0;
		// Get reference to dt from application
		virtual void Update(const float& dt) = 0;
		// Set default target window context  
		virtual void Render(sf::RenderTarget* target = nullptr) = 0;

	};
}

