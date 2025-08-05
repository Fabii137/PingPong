#include "Entities/Player.hpp"

Player::Player(sf::RenderWindow& window): Entity(window) {
	m_Shape = std::make_unique<sf::RectangleShape>(PLAYER_SIZE);
	m_Shape->setFillColor(sf::Color::Black);
	m_Shape->setOutlineColor(sf::Color::Cyan);
	m_Shape->setOutlineThickness(3.f);
}

Player::~Player() {

}

void Player::render(sf::RenderTarget* target) {
	if (target) {
		target->draw(*m_Shape);
	}
}

void Player::update(const float& dt) {

}

void Player::move(const float& dt, const float& yDir) {
	sf::Vector2f targetPos = m_Shape->getPosition() + sf::Vector2f(0, yDir * dt * m_Speed);
	sf::FloatRect playerBounds = m_Shape->getGlobalBounds();

	if ((targetPos.y + playerBounds.size.y) > m_Window.getSize().y) {
		targetPos.y = m_Window.getSize().y - playerBounds.size.y;
	}
	if (targetPos.y < 0) {
		targetPos.y = 0;
	}

	setPosition(targetPos);
}
