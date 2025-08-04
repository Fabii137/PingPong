#ifndef PLAYER_HPP
#define PLAYER_HPP

#define PLAYER_SIZE sf::Vector2f(30.f, 300.f)

#include "Entities/Entity.hpp"


class Player : public Entity {
public:
	Player(sf::RenderWindow& window);
	virtual ~Player();

	void render(sf::RenderTarget* target) override;
	void update(const float& dt) override;

	void move(const float& dt, const float& yDir);
private:

};

#endif /* PLAYER_HPP */