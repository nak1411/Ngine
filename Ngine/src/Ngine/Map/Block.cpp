#include "nepch.h"
#include "Block.h"

namespace Ngine {

	Ngine::Block::Block(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture)
		: position(position), size(size)
	{
		InitVariables();
		//this->block.setFillColor(color);
		this->block.setSize(size);
		this->block.setTexture(&texture);
		this->block.setOutlineColor(sf::Color::Black);
		this->block.setOutlineThickness(1);
		this->block.setPosition(position);
		this->movementSpeed = 200.f;
	}

	Ngine::Block::~Block()
	{

	}

	void Ngine::Block::InitVariables()
	{

	}

	void Block::Move(const float& dt, const float dirX, const float dirY)
	{
		this->block.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
	}

	void Block::Render(sf::RenderTarget* target)
	{
		target->draw(this->block);
	}

	void Block::Update(const float& dt)
	{
		
	}

}
