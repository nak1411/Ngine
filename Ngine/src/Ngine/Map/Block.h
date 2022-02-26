#pragma once

namespace Ngine {

	class Block
	{
	public:
		Block(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture);
		virtual ~Block();

		inline const sf::Color getColor() const { return this->color; }
		inline void setColor(sf::Color color) { this->color = color; }

		inline const sf::Vector2f getSize() const { return this->size; }
		inline void setSize(sf::Vector2f size) { this->size = size; }

		inline const sf::Vector2f getPosition() const { return this->position; }
		inline void setPosition(sf::Vector2f position) { this->position = position; }

		void InitVariables();
		void Render(sf::RenderTarget* target);
		void Update(const float& dt);
		void Move(const float& dt, const float dirX, const float dirY);

	private:
		sf::RectangleShape block;
		sf::Color color;
		sf::Vector2f size;
		sf::Vector2f position;

		float r, g, b, a;
		float movementSpeed;
	};

}
