#include "Entities/Player.hpp"

Player::Player() {
	m_Shape = std::make_unique<sf::RectangleShape>(PLAYER_SIZE);
	m_Shape->setFillColor(sf::Color::Green);
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
	setPosition(m_Shape->getPosition() + sf::Vector2f(0, yDir * dt * m_Speed));
}
