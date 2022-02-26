#include "nepch.h"
#include "Entity.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Entity::Entity()
	{
		this->InitVariables();
			
	}

	Entity::~Entity()
	{
		for (auto& i : sprites) {
			for (auto& j : i) {
				delete j;
			}
		}
	}

#pragma endregion

#pragma region INITIALIZERS

	void Entity::InitVariables()
	{
		this->movementSpeed = 200.f;
	}

#pragma endregion

#pragma region FUNCTIONS

	void Entity::Move(const float& dt, const float dirX, const float dirY)
	{
		for (auto& i : sprites) {
			for (auto& j : i) {
				j->move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
			}
		}
	}

	void Entity::Update(const float& dt)
	{
		for (auto i = 0; i < numOfSprites; ++i)
		{
			for (auto j = 0; j < numOfSprites; ++j)
			{
				
			}
		}
	}	

	void Entity::Render(sf::RenderTarget* target)
	{
		for (auto& i : sprites) {
			for (auto& j : i) {
				target->draw(*j);
			}
		}	
	}

#pragma endregion

}
