#pragma once

#include "GameObject.h"

class NonMovable : public GameObject
{
public:
    virtual ~NonMovable() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void handleCollision(Wall& wall) override;
    virtual void handleCollision(Cheese& cheese) override;
    virtual void handleCollision(Door& door) override;
    virtual void handleCollision(Key& key) override;
};