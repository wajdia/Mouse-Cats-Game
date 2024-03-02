#include "Key.h"
#include "Mouse.h"
Key::Key(sf::Vector2f location, float size, sf::Texture& keyTx)
{

	location.x += size / 2;
	location.y += size / 2;

	m_location = location;

	m_sprite = sf::Sprite(keyTx);

	m_sprite.setPosition(location);

	m_sprite.setScale((float)0.7 * size / ICON_SIZE,
		(float)0.7 * size / ICON_SIZE);

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2);
}

void Key::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


void Key::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Key::handleCollision(Mouse& mouse)
{
	m_isDisposed = true;
	mouse.handleCollision(*this);
}

void Key::handleCollision(Cat& cat)
{

}
