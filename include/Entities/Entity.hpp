#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
public:
	Entity();
	virtual ~Entity();

	virtual void render(sf::RenderTarget* target) = 0;
	virtual void update(const float& dt) = 0;
	void setPosition(const sf::Vector2f& position);
	void setSpeed(float speed);

protected:
	std::unique_ptr<sf::Shape> m_Shape;
	float m_Speed = 300.f;
};

#endif /* ENTITY_HPP */