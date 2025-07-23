#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>


enum ButtonState {
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button {
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, int charSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

	virtual ~Button();

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);

	const bool& isPressed() const;
private:
	short unsigned m_ButtonState;

	sf::RectangleShape m_Shape;
	sf::Font* m_Font;
	sf::Text m_Text;

	sf::Color m_TextIdleColor;
	sf::Color m_TextHoverColor;
	sf::Color m_TextActiveColor;

	sf::Color m_IdleColor;
	sf::Color m_HoverColor;
	sf::Color m_ActiveColor;
};

#endif /* BUTTON_HPP */