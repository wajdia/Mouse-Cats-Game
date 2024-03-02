#include "Cat.h"
#include "Mouse.h"
#include "Controller.h"
void Cat::update(sf::Time deltaTime, Controller& con)
{
	performUpdate(deltaTime, con, 80.f);
}

void Cat::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


void Cat::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Cat::handleCollision(Mouse& mouse)
{
	mouse.handleCollision(*this);
}

void Cat::handleCollision(Cat& cat)
{

}

void Cat::handleCollision(Cheese& cheese)
{

}
void Cat::handleCollision(Door& door)
{
	auto wall = Wall();
	this->handleCollision(wall);
}

void Cat::handleCollision(Key& key)
{
}