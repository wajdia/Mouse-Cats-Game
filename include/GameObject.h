#pragma once
#include "Textures.h"

class Mouse;
class Cat;
class Wall;
class Cheese;

class Door;
class Key;



class GameObject 
{
public:
    virtual ~GameObject() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;

    sf::FloatRect getBoundings() const;

    bool collidesWith(const GameObject& other) const;
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition() const;

    virtual void handleCollision(GameObject& gameObject) = 0;
    virtual void handleCollision(Mouse& mouse) = 0;
    virtual void handleCollision(Cat& cat) = 0;
    virtual void handleCollision(Cheese& cheese) = 0;
    virtual void handleCollision(Wall& wall) = 0;
    virtual void handleCollision(Door& door) = 0;
    virtual void handleCollision(Key& key) = 0;


protected:
    bool m_isDisposed = false;
    sf::Vector2f m_location;
    sf::Sprite m_sprite;

    
};
