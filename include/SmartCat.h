#pragma once
#include <cmath>
#include "Constants.h"
#include "Cat.h"
#include <algorithm>

class SmartCat : public Cat

{
public:
	virtual ~SmartCat() = default;
	SmartCat(sf::Vector2f loc, float size, sf::Texture& catTx);
	void move(sf::Vector2f mouseLoc) override;

};