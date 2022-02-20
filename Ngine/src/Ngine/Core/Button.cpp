#include "nepch.h"
#include "Button.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Ngine::Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
	{
		this->InitVariables();
		

		this->buttonState = BTN_IDLE;

		this->shape.setPosition(sf::Vector2f(x, y));
		this->shape.setSize(sf::Vector2f(width, height));
		this->font = font;
		
		this->text.setFont(*this->font);
		this->text.setString(text);
		this->text.setFillColor(sf::Color::White);
		this->text.setCharacterSize(24);

		this->text.setPosition(
			this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
			this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
			);

		this->idleColor = idleColor;
		this->hoverColor = hoverColor;
		this->pressedColor = pressedColor;

		this->shape.setFillColor(this->idleColor);
	}

	Ngine::Button::~Button()
	{

	}

#pragma endregion

#pragma region INITIALIZERS

	void Button::InitVariables()
	{
		this->buttonState = 0;
		this->font = nullptr;
		
	}

#pragma endregion


#pragma region FUNCTIONS



	void Button::Update(const sf::Vector2f mousePos)
	{
		// Idle by default
		this->buttonState = BTN_IDLE;

		// Update is hovering
		if (this->shape.getGlobalBounds().contains(mousePos))
		{
			this->buttonState = BTN_HOVER;

			// Update is pressed
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->buttonState = BTN_PRESSED;
			}
		}

		switch (this->buttonState)
		{
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;

		case BTN_PRESSED:
			this->shape.setFillColor(this->pressedColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Green);
			break;
		}
	}

	void Button::Render(sf::RenderTarget* target)
	{
		target->draw(this->shape);
		target->draw(this->text);
	}

	const bool Button::IsPressed() const
	{
		if (this->buttonState == BTN_PRESSED)
		{
			return true;
		}
		return false;
	}

#pragma endregion

}
