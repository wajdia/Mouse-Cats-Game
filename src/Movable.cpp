#include "Movable.h"
#include "Controller.h"


void Movable::handleCollision(Wall& wall)
{
	m_facingWall = true;
	float deltaD = 1.f;

	//move back the mouse/cat depending on collision direction
	if (m_direction.x == 0)
	{
		if (m_direction.y == 1)
		{
			setPosition(sf::Vector2f(m_location.x, m_location.y - deltaD));
		}
		else if (m_direction.y == -1)
		{
			setPosition(sf::Vector2f(m_location.x, m_location.y + deltaD));
		}
	}
	else if (m_direction.y == 0)
	{
		if (m_direction.x == 1)
		{
			setPosition(sf::Vector2f(m_location.x - deltaD, m_location.y));
		}
		else if (m_direction.x == -1)
		{
			setPosition(sf::Vector2f(m_location.x + deltaD, m_location.y));
		}
	}

	m_sprite.setScale(m_size * 0.85, m_size * 0.85);
	adjustPosition();
}

void Movable::adjustPosition()
{
	sf::Vector2f adjustLocation = m_location;
	float radius = m_sprite.getGlobalBounds().getSize().x / 2;

	if (m_location.x - radius < 0)
	{
		adjustLocation.x = radius;
	}
	if (m_location.y - radius < 0)
	{
		adjustLocation.y = radius;
	}

	m_location = adjustLocation;
	m_sprite.setPosition(adjustLocation);
}

void Movable::performUpdate(sf::Time deltaTime,Controller& con,float speed)
{
	adjustPosition();
	if (!m_facingWall)
	{
		const auto speedPerSecond = speed;
		sf::Vector2f newLoc = m_direction * speedPerSecond * deltaTime.asSeconds();
		float radius = m_sprite.getGlobalBounds().getSize().x / 2;

		if (newLoc.x + m_location.x <= con.getWidthBound() - radius &&
			newLoc.y + m_location.y <= con.getHeightBound() - radius)
		{
			if (newLoc.x >= 0 && newLoc.y >= 0)
			{
				m_sprite.move(newLoc);
				m_location = m_sprite.getPosition();

			}
			else if (m_location.x - std::abs(newLoc.x) >= 0 &&
				m_location.y - std::abs(newLoc.y) >= 0)
			{
				m_sprite.move(newLoc);
				m_location = m_sprite.getPosition();
			}
			adjustPosition();
		}
	}
}

void Movable::correctScale()
{
	m_sprite.setScale(m_size, m_size);
	adjustPosition();
}