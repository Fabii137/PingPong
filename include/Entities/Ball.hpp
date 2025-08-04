#ifndef BALL_HPP
#define BALL_HPP

#define BALL_RADIUS 15.f

#include "Entities/Entity.hpp"

class Ball : public Entity {
public:
	Ball(sf::Shape& player1, sf::Shape& player2, sf::RenderWindow& window);
	virtual ~Ball();

	void start();
	void render(sf::RenderTarget* target) override;
	void update(const float& dt) override;
private:
	sf::Vector2f m_Velocity;

	sf::Shape& m_Player1;
	sf::Shape& m_Player2;
};

#endif /* BALL_HPP */