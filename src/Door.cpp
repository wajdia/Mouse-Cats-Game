#include "Door.h"
#include "Mouse.h"
#include "Cat.h"

Door::Door(sf::Vector2f location, float size, sf::Texture& doorTx)
{
	m_sprite = sf::Sprite(doorTx);
	m_sprite.setPosition(location);
	m_sprite.setScale((float)size / ICON_SIZE,
		(float)size / ICON_SIZE);
	m_location = location;
}

void Door::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


void Door::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Door::handleCollision(Mouse& mouse)
{

	mouse.handleCollision(*this);
}

void Door::handleCollision(Cat& cat)
{
	cat.handleCollision(*this);
}
