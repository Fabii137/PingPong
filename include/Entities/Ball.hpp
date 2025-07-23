#ifndef BALL_HPP
#define BALL_HPP

#define BALL_RADIUS 15.f

#include "Entities/Entity.hpp"

class Ball : public Entity {
public:
	Ball();
	virtual ~Ball();

	void render(sf::RenderTarget* target) override;
	void update(const float& dt) override;
private:

};

#endif /* BALL_HPP */