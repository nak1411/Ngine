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
		void CreateSprite(sf::Texture* texture);

		virtual void Move(const float& dt, const float dirX, const float dirY);
		virtual void Update(const float& dt);
		virtual void Render(sf::RenderTarget* target);

	protected:

		/*VARS*/
		sf::Texture* texture;
		sf::Sprite* sprite;

		float movementSpeed;

	private:

		/*VARS*/

		/*FUNCTIONS*/
		void InitVariables();

	};
}

