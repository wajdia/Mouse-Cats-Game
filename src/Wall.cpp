#include "Wall.h"
#include "Mouse.h"
#include "Cat.h"

Wall::Wall(sf::Vector2f location, float size,sf::Texture& wallTx)
{
	m_sprite = sf::Sprite(wallTx);
	m_sprite.setPosition(location);
	m_sprite.setScale((float)size / ICON_SIZE,
		(float)size / ICON_SIZE);
	m_location = location;
}

void Wall::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


void Wall::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(Mouse& mouse)
{
	
	mouse.handleCollision(*this);
}

void Wall::handleCollision(Cat& cat)
{
	cat.handleCollision(*this);
}
