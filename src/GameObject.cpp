#include "GameObject.h"

void GameObject::setPosition(sf::Vector2f newPosition)
{
	m_location = newPosition;
}

sf::Vector2f GameObject::getPosition() const
{
	return m_location;
}

bool GameObject::collidesWith(const GameObject& other) const	 
{
	return getBoundings().intersects(other.getBoundings());
}

sf::FloatRect GameObject::getBoundings() const
{
	return m_sprite.getGlobalBounds();
}