#pragma once
#include "Movable.h"
#include "Constants.h"

enum catDirection_t { LEFT, RIGHT, UP, DOWN };

class Cat : public Movable

{
public:
	using Movable::handleCollision;

	virtual ~Cat() = default;

	virtual void move(sf::Vector2f loc) = 0;	//still ABC

	virtual void update(sf::Time deltaTime,Controller& con) override;
	virtual void draw(sf::RenderWindow& window) const override;
	
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Mouse& mouse) override;
	virtual void handleCollision(Cat& cat) override;
	virtual void handleCollision(Cheese& cheese) override;
	virtual void handleCollision(Door& door) override;
	virtual void handleCollision(Key& key) override;

};