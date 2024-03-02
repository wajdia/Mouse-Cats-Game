#pragma once

#include "Movable.h"
#include "Constants.h"

class Wall;

class Mouse : public Movable
{
public:
	using Movable::handleCollision;
	~Mouse() = default;

	Mouse(sf::Vector2f loc, float size, sf::Texture& t);
	virtual void update(sf::Time deltaTime, Controller& con) override;
	virtual void draw(sf::RenderWindow& window) const override;


	void setDirection(sf::Keyboard::Key key);
	int getCheeseCount() const;
	int getKeysCount() const;

	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Mouse& mouse) override;
	virtual void handleCollision(Cat& cat) override;
	virtual void handleCollision(Cheese& cheese) override;
	virtual void handleCollision(Door& door) override;
	virtual void handleCollision(Key& key) override;

private:
	int m_lives;
	int m_cheeseCount = 0;
	int m_keysCount = 0;
	sf::Vector2f m_initialLocation;
};