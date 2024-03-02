#include "Board.h"

Board::Board()
{}
Board::Board(ifstream& file)
{
	processLevel(file);
    m_tileSize = 50.f;
    m_textures.loadTextures();
}

void Board::processLevel(ifstream& level)
{
	level >> m_rows >> m_cols;
	for (auto line = string(); getline(level, line);)
	{
		if (line.size() != 0)
		{
			m_board.push_back(line);
		}
	}

}

std::unique_ptr<GameObject> Board::charToGameObject(char c,int row,int col) {
    switch (c) {
    case '#':
        return std::make_unique<Wall>
            (getObjLocation(row, col), m_tileSize,m_textures.m_wallTexture);
    case ' ':
        return nullptr;
    case '*':
        return std::make_unique<Cheese>
            (getObjLocation(row, col), m_tileSize,m_textures.m_cheeseTexture);
    /*case '$':
        return std::make_unique<Gift>();*/
    case 'D':
        return std::make_unique<Door>
            (getObjLocation(row, col), m_tileSize, m_textures.m_doorTexture);
        
    case 'F':
        return std::make_unique<Key>
            (getObjLocation(row, col), m_tileSize, m_textures.m_keyTexture);
    //default:
    //    // Handle unknown characters or errors
    //    std::cerr << "Unknown character encountered: " << c << std::endl;
    //    // Returning an empty object
    //    return std::make_unique<Empty>();
   /* default:
        return nullptr;*/
    }
}




sf::Vector2f Board::getObjLocation(int row, int col) const
{
    float xCoor = m_tileSize * col;
    float yCoor = m_tileSize * row;

    return sf::Vector2f(xCoor, yCoor);
}



vector<string> Board::getBoard() const
{
    return m_board;
}

int Board::getCols() const
{
    return m_cols;
}

int Board::getRows() const
{
    return m_rows;
}

void Board::calculateTileSize(int wWidth, int wHeight)
{
    int maximalShrink = (m_cols > m_rows) ? m_cols : m_rows;
    m_tileSize = std::min((wWidth - MENU_WIDTH - PADDING) / maximalShrink,
        (int)(wHeight - PADDING) / m_rows);
}

std::unique_ptr<Mouse> Board::getMousePtr(int row,int col)
{
    return std::make_unique<Mouse>
        (getObjLocation(row, col), m_tileSize,m_textures.m_mouseTexture);
}

std::unique_ptr<Cat> Board::getCatsPtrs(int row, int col,char type)
{
    if (type == SMART_CAT)
    {
        return std::make_unique<SmartCat>
            (getObjLocation(row, col), m_tileSize, m_textures.m_catTexture);
    }
    else if (type == NORMAL_CAT)
    {
        return std::make_unique<NormalCat>
            (getObjLocation(row, col), m_tileSize, m_textures.m_catTexture);
    }
}

float Board::getTileSize() const
{
    return m_tileSize;
}