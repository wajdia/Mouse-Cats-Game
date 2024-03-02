#pragma once
#include <cmath>
#include "Constants.h"
#include "Cat.h"
#include <random>


class NormalCat : public Cat

{
public:
	virtual ~NormalCat() = default;
	NormalCat(sf::Vector2f loc, float size, sf::Texture& catTx);
	void move(sf::Vector2f mouseLoc) override;
	
};