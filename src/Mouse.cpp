#include "Mouse.h"
#include "Controller.h"
#include  <cmath>
#include "Wall.h"

Mouse::Mouse(sf::Vector2f loc,float size,sf::Texture& mouseTx)
{
	loc.x += size/2;
	loc.y += size/2;
	m_initialLocation = m_location = loc;
	m_lives  = 3;

	m_sprite = sf::Sprite(mouseTx);
	m_direction = sf::Vector2f(1, 0);

	m_size = (float)0.85 * size / ICON_SIZE;

	m_sprite.setPosition(m_location);
	m_sprite.setScale(m_size,m_size);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2);
	adjustPosition();
	
}

void Mouse::update(sf::Time deltaTime,Controller& con) 
{
	performUpdate(deltaTime, con, 200.f);
}

void Mouse::draw(sf::RenderWindow& win)  const
{
	win.draw(m_sprite);
}

void Mouse::setDirection(sf::Keyboard::Key key)
{
	sf::Vector2f previousDirection = m_direction;

	float rotation=0;
	switch (key)
	{
	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0);
		rotation = 180;
		break;
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0);
		rotation = 0;
		break;
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1);
		rotation = -90;
		break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1);
		rotation = 90;
		break;
	default:
		break;
	}
	if (previousDirection != m_direction && m_facingWall)
	{
		m_facingWall = false;
	}
	
	m_sprite.setRotation(rotation);
}

void Mouse::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Mouse::handleCollision(Mouse& mouse)
{

}

void Mouse::handleCollision(Cat& cat)
{
	m_lives--;
	if (m_lives == 0)
	{
		m_isDisposed = true;
	}
	m_location = m_initialLocation;

}

void Mouse::handleCollision(Cheese& cheese)
{
	m_cheeseCount++;
}


void Mouse::handleCollision(Door& door)
{
	if (m_keysCount == 0)
	{
		//no keys, so the door behaves as wall
		auto wall = Wall();
		this->handleCollision(wall);
	}

	else
	{
		m_isDisposed = true;
		m_keysCount--;
	}
}

void Mouse::handleCollision(Key& key)
{
	m_keysCount++;
}

int Mouse::getCheeseCount() const
{
	return m_cheeseCount;
}

int Mouse::getKeysCount() const
{
	return m_keysCount;
}
