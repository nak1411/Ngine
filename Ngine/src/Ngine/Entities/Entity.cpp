#include "nepch.h"
#include "Entity.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Entity::Entity()
	{
		this->InitVariables();
		this->movementSpeed = 100.f;
	}

	Entity::~Entity()
	{
		delete this->sprite;
	}

#pragma endregion

#pragma region INITIALIZERS

	void Entity::InitVariables()
	{
		this->sprite = nullptr;
		this->texture = nullptr;
	}

#pragma endregion

#pragma region FUNCTIONS

	void Entity::CreateSprite(sf::Texture* texture)
	{
		this->texture = texture;
		this->sprite->setTexture(*this->texture);
	}

	void Entity::Move(const float& dt, const float dirX, const float dirY)
	{
		if (this->sprite)
		{
			this->sprite->move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
		}
	}

	void Entity::Update(const float& dt)
	{

	}	

	void Entity::Render(sf::RenderTarget* target)
	{
		if (this->sprite)
		{
			target->draw(*this->sprite);
		}
	}

#pragma endregion

}
