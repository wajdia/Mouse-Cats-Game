#include "Cheese.h"
#include "Mouse.h"
Cheese::Cheese(sf::Vector2f location, float size,sf::Texture& cheeseTx)
{

	location.x += size / 2;
	location.y += size / 2;

	m_location = location;

	m_sprite = sf::Sprite(cheeseTx);
	
	m_sprite.setPosition(location);
	
	m_sprite.setScale((float)0.7*size / ICON_SIZE,
		(float)0.7*size / ICON_SIZE);

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2);
}

void Cheese::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


void Cheese::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Cheese::handleCollision(Mouse& mouse)
{
	mouse.handleCollision(*this);
}

void Cheese::handleCollision(Cat& cat)
{
	
}
