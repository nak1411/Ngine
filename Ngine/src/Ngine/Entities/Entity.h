#pragma once
#include "nepch.h"

namespace Ngine {

	class Entity
	{

	public:

		/*CONSTRUCTOR / DESTRUCTOR*/
		Entity();
		virtual ~Entity();

		/*FUNCTIONS*/
		void CreateSprite(float xPos, float yPos, float width, float height, sf::Color color, int numOfSprites);

		virtual void Move(const float& dt, const float dirX, const float dirY);
		virtual void Update(const float& dt);
		virtual void Render(sf::RenderTarget* target);

	protected:

		/*VARS*/
		std::vector<std::vector<sf::RectangleShape*>> sprites;

		int numOfSprites;
		float movementSpeed;
		float r, g, b, a;
		int tileSize;

	private:

		/*VARS*/

		/*FUNCTIONS*/
		void InitVariables();

	};
}

