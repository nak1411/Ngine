#pragma once

namespace gui {

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

		gui::Button* activeElement;
		sf::RectangleShape shape;
		sf::Text text;
		sf::Font* font;
		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color pressedColor;
	};

	class DropDownMenu
	{

	public:
		/*CONSTRUCTOR / DESTRUCTOR*/
		DropDownMenu(int xPos, int yPos, int xOff, int yOff, sf::Font& font, std::string list[], unsigned numOfElements);
		virtual ~DropDownMenu();

		/*FUNCTIONS*/
		void InitVariables();
		void Update(const sf::Vector2f mousePos);
		void Render(sf::RenderTarget* target = nullptr);

		/*GETTERS*/
		const bool IsPressed() const;


	private:

		/*VARS*/
		bool isShown;
		gui::Button* activeElement;
		std::vector<gui::Button*> dropdownButtons;
		sf::RectangleShape shape;
		sf::Font& font;
	};
}

