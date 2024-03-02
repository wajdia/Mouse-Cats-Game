#include "Textures.h"


Textures::Textures() {}

void Textures::loadTextures()
{
	m_mouseTexture.loadFromFile("Mouse.png");
	m_catTexture.loadFromFile("Cat.png");
	m_wallTexture.loadFromFile("Wall.png");
	m_cheeseTexture.loadFromFile("Cheese.png");
	m_doorTexture.loadFromFile("Door.png");
	m_keyTexture.loadFromFile("Key.png");
}