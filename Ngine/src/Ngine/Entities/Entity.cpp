#include "nepch.h"
#include "Entity.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Entity::Entity()
	{
		this->shape.setSize(sf::Vector2f(20.f, 20.f));
		this->shape.setFillColor(sf::Color::Blue);
		this->movementSpeed = 100.f;
	}

	Entity::~Entity()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	void Entity::Move(const float& dt, const float dirX, const float dirY)
	{
		this->shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
	}

	void Entity::Update(const float& dt)
	{

	}	

	void Entity::Render(sf::RenderTarget* target)
	{
		target->draw(this->shape);
	}

#pragma endregion

}
