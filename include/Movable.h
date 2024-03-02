#pragma once
#include "GameObject.h"
class Controller;

class Movable : public GameObject
{
public:
	virtual ~Movable() = default;
	virtual void update(sf::Time deltaTime, Controller& con) = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;


	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Mouse& mouse) = 0;
	virtual void handleCollision(Cat& cat) = 0;
	virtual void handleCollision(Cheese& cheese) = 0;
	virtual void handleCollision(Door& door) = 0;
	virtual void handleCollision(Key& key) = 0;

	void handleCollision(Wall& wall) override;
	void correctScale();
	
	

protected:
	sf::Vector2f m_direction;
	bool m_facingWall = false;
	float m_size;

	void adjustPosition();
	void performUpdate(sf::Time deltaTime,Controller& con,float speed);
	
};