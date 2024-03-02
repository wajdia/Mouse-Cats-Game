#include "NormalCat.h"

NormalCat::NormalCat(sf::Vector2f loc, float size, sf::Texture& catTx)
{
    loc.x += size / 2;
    loc.y += size / 2;

    m_location = loc;
    m_direction = sf::Vector2f(1, 0);

    m_sprite = sf::Sprite(catTx);
    m_sprite.setPosition(loc);
    m_size = (float)0.85 * size / ICON_SIZE;

    m_sprite.setScale(m_size, m_size);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
        m_sprite.getLocalBounds().height / 2);

    m_sprite.setColor(sf::Color::Green);
}

void NormalCat::move(sf::Vector2f mouseLoc)
{
    sf::Vector2f previousDirection = m_direction;

    //static var needed, not to change for every func call
    static sf::Clock directionChangeTimer; 
    const float directionChangeInterval = 0.2f; 

    //Check if to change direction
    if (directionChangeTimer.getElapsedTime().asSeconds() >= directionChangeInterval)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 3); //4 directions

        int randomDirection = distr(gen);

        sf::Vector2f newDirection;
        switch (randomDirection)
        {
        case 0: // Left
            newDirection = sf::Vector2f(-1, 0);
            break;
        case 1: // Right
            newDirection = sf::Vector2f(1, 0);
            break;
        case 2: // Up
            newDirection = sf::Vector2f(0, -1);
            break;
        case 3: // Down
            newDirection = sf::Vector2f(0, 1);
            break;
        }

        m_direction = newDirection;

        //Reset the timer
        directionChangeTimer.restart();
    }

    float rotation;
    catDirection_t d = RIGHT;

    if (m_direction == sf::Vector2f(-1, 0))
        d = LEFT;
    if (m_direction == sf::Vector2f(1, 0))
        d = RIGHT;
    if (m_direction == sf::Vector2f(0, -1))
        d = UP;
    if (m_direction == sf::Vector2f(0, 1))
        d = DOWN;

    if (previousDirection != m_direction && m_facingWall)
    {
        m_facingWall = false;
    }

    switch (d)
    {
    case LEFT:
        rotation = 180;
        break;
    case RIGHT:
        rotation = 0;
        break;
    case UP:
        rotation = -90;
        break;
    case DOWN:
        rotation = 90;
        break;
    default:
        break;
    }
    m_sprite.setRotation(rotation);
}
