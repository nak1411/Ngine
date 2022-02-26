#include "nepch.h"
#include "Gui.h"

namespace gui
{

#pragma region BUTTON C/D

	gui::Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
	{
		this->InitVariables();

		this->buttonState = BTN_IDLE;

		this->shape.setPosition(sf::Vector2f(x, y));
		this->shape.setSize(sf::Vector2f(width, height));
		this->font = font;
		
		this->text.setFont(*this->font);


		this->text.setString(text);		//RELEASE WTF


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

	gui::Button::~Button()
	{

	}

#pragma endregion

#pragma region DropDownMenu C/D
	gui::DropDownMenu::DropDownMenu(int xPos, int yPos, int xOff, int yOff, sf::Font& font, std::string list[], unsigned numOfElements)
		: font(font), isShown(false)
	{
		this->InitVariables();
		

		for (size_t i = 0; i < numOfElements; i++) {
			this->dropdownButtons.push_back(new gui::Button(xPos + (xOff * i), yPos + yOff, 200, 50,
				&this->font, list[i],
				sf::Color(70, 70, 70, 200),
				sf::Color(150, 150, 150, 255),
				sf::Color(20, 20, 20, 200)));
		}

		this->activeElement = new gui::Button(*this->dropdownButtons[0]);
		
	}

	gui::DropDownMenu::~DropDownMenu()
	{
		delete this->activeElement;
		for (auto & i : dropdownButtons)
		{
			delete i;
		}
	}

#pragma endregion

#pragma region BUTTON INIT

	void Button::InitVariables()
	{
		this->buttonState = 0;
		this->font = nullptr;
	}

#pragma endregion

#pragma region DROPDOWNMENU INIT

	void DropDownMenu::InitVariables()
	{

	}

#pragma endregion

#pragma region BUTTON FUNCTIONS

	void Button::Update(const sf::Vector2f mousePos)
	{

		// Idle by default
		this->buttonState = BTN_IDLE;
		

		// Update is hovering
		if (this->shape.getGlobalBounds().contains(mousePos))
		{
			this->buttonState = BTN_HOVER;

			// Update is pressed while preventing multiple click events
			static bool lockClick = false;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && lockClick != true)
			{
				lockClick = true;
				this->buttonState = BTN_PRESSED;
			}
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				lockClick = false;
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

#pragma region DROPDOWNMENU FUNCTIONS

	void DropDownMenu::Update(const sf::Vector2f mousePos)
	{
		this->activeElement->Update(mousePos);

		if (this->activeElement->IsPressed())
		{
			if (this->isShown)
			{
				this->isShown = false;
			}
			else 
			{
				this->isShown = true;
			}
			
		}

		if (this->isShown)
		{
			for (auto& i : this->dropdownButtons)
			{
				i->Update(mousePos);
			}
		}	
	}

	void DropDownMenu::Render(sf::RenderTarget* target)
	{
		this->activeElement->Render(target);

		if (this->isShown)
		{
			for (auto& i : this->dropdownButtons)
			{
				i->Render(target);
			}
		}
	}

	const bool DropDownMenu::IsPressed() const
	{
		return false;
	}

#pragma endregion

}
