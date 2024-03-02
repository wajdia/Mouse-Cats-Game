#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Constants.h"
#include "Mouse.h"
#include "Wall.h"
#include <memory>
#include "GameObject.h"
#include "Movable.h"
#include "NonMovable.h"
#include "Cheese.h"
#include "SmartCat.h"
#include "NormalCat.h"
#include "Textures.h"
#include "Door.h"
#include "Key.h"


using std::vector;
using std::string;
using std::ifstream;
using std::cout;


enum direction_t { D_UP, D_DOWN, D_LEFT, D_RIGHT };

class Board {
public:
	Board();
	Board(ifstream& file);

	
	std::unique_ptr<GameObject> charToGameObject(char c, int row, int col);
	sf::Vector2f getObjLocation(int row, int col) const;
	vector<string> getBoard() const;
	int getCols() const;
	int getRows() const;
	void calculateTileSize(int width,int height);

	std::unique_ptr<Mouse> getMousePtr(int,int);
	std::unique_ptr<Cat> getCatsPtrs(int, int,char);
	float getTileSize() const;
private:

	vector<string> m_board;
	int m_cols;
	int m_rows;
	float m_tileSize;
	Textures m_textures;


	void processLevel(ifstream& file);
	
};