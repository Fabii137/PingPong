#include "Entities/Entity.hpp"

Entity::Entity() {
	
}

Entity::~Entity() {

}

sf::Shape* Entity::getShape()
{
	return m_Shape.get();
}

void Entity::setPosition(const sf::Vector2f& position) {
	m_Shape->setPosition(position);
}

void Entity::setSpeed(float speed) {
	m_Speed = speed;
}
