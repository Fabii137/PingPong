#ifndef BALL_HPP
#define BALL_HPP

#define BALL_RADIUS 15.f

#include "Entities/Entity.hpp"

class Ball : public Entity {
public:
	Ball();
	virtual ~Ball();

	void start();
	void render(sf::RenderTarget* target) override;
	void updateWithCollision(const float& dt, sf::Shape& player1, sf::Shape& player2, sf::RenderWindow& window);
	void update(const float& dt) override;
private:
	sf::Vector2f m_Velocity;
};

#endif /* BALL_HPP */