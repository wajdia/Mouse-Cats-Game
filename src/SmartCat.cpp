#include "SmartCat.h"
#include "Controller.h"

SmartCat::SmartCat(sf::Vector2f loc, float size,sf::Texture& catTx)
{
	loc.x += size / 2;
	loc.y += size / 2;

	m_location = loc;

	m_sprite = sf::Sprite(catTx);
	m_direction = sf::Vector2f(1, 0);
	
	m_size = (float)0.85 * size / ICON_SIZE;
	
	m_sprite.setPosition(m_location);

	m_sprite.setScale(m_size, m_size);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2);
	adjustPosition();
	m_sprite.setColor(sf::Color::Red);

}


void SmartCat::move(sf::Vector2f mouseLocation)
{
	sf::Vector2f previousDirection = m_direction;

	sf::Vector2f direction = mouseLocation - m_location;

	float absX = std::abs(direction.x);
	float absY = std::abs(direction.y);

	//static var needed, not to change for every func call
	static sf::Clock directionChangeTimer;
	const float directionChangeInterval = 0.8f;

	//Check if to change direction
	if (directionChangeTimer.getElapsedTime().asSeconds() >= directionChangeInterval)
	{
		if (absX == absY)
		{
			m_direction.y = 0.0f;
		}
		if (absX > absY)
		{
			m_direction.x = (direction.x > 0) ? 1.0f : -1.0f;
			m_direction.y = 0.0f;
		}
		else if (absY > absX)
		{

			m_direction.x = 0.0f;
			m_direction.y = (direction.y > 0) ? 1.0f : -1.0f;
		}
		//Reset the timer
		directionChangeTimer.restart();
	}


	float rotation;
	catDirection_t d ;

	if (m_direction == sf::Vector2f(-1, 0))
		d = LEFT;
	if (m_direction == sf::Vector2f(1, 0))
		d = RIGHT;
	if (m_direction == sf::Vector2f(0, -1))
		d = UP;
	if (m_direction == sf::Vector2f(0, 1))
		d = DOWN;

	if (previousDirection != m_direction && m_facingWall)
	{
		m_facingWall = false;
	}

	switch (d)
	{
	case LEFT:
		rotation = 180;
		break;
	case RIGHT:
		rotation = 0;
		break;
	case UP:
		rotation = -90;
		break;
	case DOWN:
		rotation = 90;
		break;
	default:
		break;
	}
	m_sprite.setRotation(rotation);
}
