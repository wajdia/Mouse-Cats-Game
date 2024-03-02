#pragma once

#include <SFML/Graphics.hpp>

class Textures {
public:
	Textures();
	sf::Texture m_mouseTexture;
	sf::Texture m_catTexture;
	sf::Texture m_wallTexture;
	sf::Texture m_cheeseTexture;
	sf::Texture m_keyTexture;
	sf::Texture m_doorTexture;
	sf::Texture m_freezeGiftTexture;
	sf::Texture m_extraTimeTexture;
	sf::Texture m_terminateCatTexture;
	sf::Texture m_lifeUpTexture;

	void loadTextures();

};
