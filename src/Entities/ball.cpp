#include "Entities/Ball.hpp"

Ball::Ball() {
	m_Shape = std::make_unique<sf::CircleShape>(BALL_RADIUS);
	m_Shape->setFillColor(sf::Color::White);
}

Ball::~Ball() {

}

void Ball::render(sf::RenderTarget* target) {
	if (target) {
		target->draw(*m_Shape);
	}
}

void Ball::update(const float& dt) {
	
}

