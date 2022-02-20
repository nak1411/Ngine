#pragma once

namespace Ngine {

	enum button_states{BTN_IDLE, BTN_HOVER, BTN_PRESSED};

	class Button
	{

	public:

		/*CONSTRUCTOR / DESTRUCTOR*/
		Button(float x, float y, float width, float height, sf::Font* font, std::string text,
			sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);
		virtual ~Button();

		/*FUNCTIONS*/
		void InitVariables();
		void Update(const sf::Vector2f mousePos);
		void Render(sf::RenderTarget* target = nullptr);

		/*GETTERS*/
		const bool IsPressed() const;

	private:

		/*VARS*/
		short unsigned buttonState;

		sf::RectangleShape shape;
		sf::Text text;
		sf::Font* font;
		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color pressedColor;

	};
}

