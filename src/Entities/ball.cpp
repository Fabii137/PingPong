#include "Entities/Ball.hpp"

Ball::Ball(sf::Shape& player1, sf::Shape& player2, sf::RenderWindow& window)
    : Entity(window), m_Player1(player1), m_Player2(player2) {
    m_Shape = std::make_unique<sf::CircleShape>(BALL_RADIUS);
    m_Shape->setFillColor(sf::Color::Black);
    m_Shape->setOutlineColor(sf::Color(57, 255, 20));
    m_Shape->setOutlineThickness(3.f);
    
    srand(time(NULL));
}

Ball::~Ball() {

}

void Ball::start() {
    m_Speed = 300.f;
	int rndX = rand() % 2;
	int rndY = rand() % 2;
	bool startLeft = rndX == 0;
	bool startUp = rndY == 0;


    m_Velocity = sf::Vector2f(startUp ? -1.f : 1.f, startLeft ? -0.5f : 0.5f);
}

void Ball::stop() {
    m_Velocity = sf::Vector2f(0, 0);
}

void Ball::render(sf::RenderTarget* target) {
	if (target) {
		target->draw(*m_Shape);
	}
}

void Ball::update(const float& dt) {
    sf::FloatRect ballBounds = m_Shape->getGlobalBounds();
    sf::FloatRect p1Bounds = m_Player1.getGlobalBounds();
    sf::FloatRect p2Bounds = m_Player2.getGlobalBounds();
    sf::Vector2u windowSize = m_Window.getSize();

    sf::Vector2f targetPos = m_Shape->getPosition() + m_Velocity * m_Speed * dt;

    if (targetPos.y <= 0 || (targetPos.y + ballBounds.size.y) >= windowSize.y) {
        m_Velocity.y *= -1.f;
        m_Speed += 50.f;
    }

    sf::FloatRect futureBallBounds(targetPos, ballBounds.size);

    if (futureBallBounds.findIntersection(p1Bounds) || futureBallBounds.findIntersection(p2Bounds)) {
        m_Velocity.x *= -1.f;
        m_Speed += 50.f;
    }

    m_Shape->move(m_Velocity * m_Speed * dt);
}

