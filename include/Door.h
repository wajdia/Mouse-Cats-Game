#pragma once

#include "NonMovable.h"
#include "Constants.h"

class Door : public NonMovable
{
public:
	Door(sf::Vector2f location, float size, sf::Texture& t);

	virtual void draw(sf::RenderWindow& window) const override;

	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Mouse& mouse) override;
	virtual void handleCollision(Cat& cat) override;

};