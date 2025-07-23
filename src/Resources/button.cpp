#include "Resources/Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, int charSize, 
	sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor, 
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	: m_Font(font), m_Text(*m_Font, text, charSize) {

	m_ButtonState = BTN_IDLE;

	m_Shape.setPosition(sf::Vector2f(x, y));
	m_Shape.setSize(sf::Vector2f(width, height));
	m_Shape.setFillColor(idleColor);

	m_Text.setFillColor(textIdleColor);
	m_Text.setPosition(sf::Vector2f(
		m_Shape.getPosition().x + (m_Shape.getGlobalBounds().size.x / 2.f) - m_Text.getGlobalBounds().size.x / 2.f,
		m_Shape.getPosition().y + (m_Shape.getGlobalBounds().size.y / 2.f) - m_Text.getGlobalBounds().size.y / 2.f
	));

	m_TextIdleColor = textIdleColor;
	m_TextHoverColor = textHoverColor;
	m_TextActiveColor = textActiveColor;

	m_IdleColor = idleColor;
	m_HoverColor = hoverColor;
	m_ActiveColor = activeColor;
}

Button::~Button() {
	
}

void Button::update(const sf::Vector2f& mousePos) {
	m_ButtonState = BTN_IDLE;

	//hover
	if (m_Shape.getGlobalBounds().contains(mousePos)) {
		m_ButtonState = BTN_HOVER;

		//active
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			m_ButtonState = BTN_ACTIVE;
		}
	}

	switch (m_ButtonState) {
		case BTN_IDLE: {
			m_Shape.setFillColor(m_IdleColor);
			m_Text.setFillColor(m_TextIdleColor);
			break;
		}
		case BTN_HOVER: {
			m_Shape.setFillColor(m_HoverColor);
			m_Text.setFillColor(m_TextHoverColor);
			break;
		}
		case BTN_ACTIVE: {
			m_Shape.setFillColor(m_ActiveColor);
			m_Text.setFillColor(m_TextActiveColor);
			break;
		}
		default: {
			m_Shape.setFillColor(sf::Color::Red);
			m_Text.setFillColor(sf::Color::Blue);
			break;
		}
	}
}

void Button::render(sf::RenderTarget* target) {
	target->draw(m_Shape);
	target->draw(m_Text);
}

const bool& Button::isPressed() const {
	return m_ButtonState == BTN_ACTIVE;
}




