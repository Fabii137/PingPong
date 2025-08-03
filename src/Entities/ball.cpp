#include "Entities/Ball.hpp"

Ball::Ball() {
	m_Shape = std::make_unique<sf::CircleShape>(BALL_RADIUS);
	m_Shape->setFillColor(sf::Color::White);
	srand(time(NULL));
}

Ball::~Ball() {

}

void Ball::start() {
	int rndX = rand() % 2;
	int rndY = rand() % 2;
	bool startLeft = rndX == 0;
	bool startUp = rndY == 0;

	m_Velocity.x = startLeft ? -m_Speed : m_Speed;
	m_Velocity.y = (startUp ? -1.f : 1.f) * m_Speed * .5f;
}

void Ball::render(sf::RenderTarget* target) {
	if (target) {
		target->draw(*m_Shape);
	}
}

void Ball::updateWithCollision(const float& dt, sf::Shape& player1, sf::Shape& player2, sf::RenderWindow& window) {
    sf::FloatRect ballBounds = m_Shape->getGlobalBounds();
    sf::FloatRect p1Bounds = player1.getGlobalBounds();
    sf::FloatRect p2Bounds = player2.getGlobalBounds();
    sf::Vector2u windowSize = window.getSize();

    sf::Vector2f targetPos = m_Shape->getPosition() + m_Velocity * dt;

    if (targetPos.y <= 0 || (targetPos.y + ballBounds.size.y) >= windowSize.y) {
        m_Velocity.y *= -1.f;
    }

    sf::FloatRect futureBallBounds;
    futureBallBounds.position = targetPos;
    futureBallBounds.size = ballBounds.size;

    if (futureBallBounds.findIntersection(p1Bounds) || futureBallBounds.findIntersection(p2Bounds)) {
        m_Velocity.x *= -1.f;
    }

    m_Shape->move(m_Velocity * dt);
}


void Ball::update(const float& dt) {
	
}

