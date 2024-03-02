#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "GameObject.h"
#include "Movable.h"
#include "Constants.h"
#include "Mouse.h"
#include <iostream>
#include "Board.h"
#include "Cat.h"

using std::vector;
using std::string;
using std::ifstream;

class Controller {
public:
    Controller();
    void run();
    std::vector<std::ifstream> 
            openPlaylistFiles(const std::string& filename);

    int getWidthBound() const;
    int getHeightBound() const;

private:
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<Cat>> m_cats; // cats
    std::vector<std::unique_ptr<GameObject>> m_nonMovableObjects;
    int m_windowWidth = WINDOW_WIDTH;
    int m_windowHeight = WINDOW_HEIGHT;
    Board m_board;
    std::unique_ptr<Mouse> m_mouse;

    void update(sf::Time deltaTime);
    void draw();
    void fillVector(Board& board);
    void optimizeDimensions(Board& board);
    void checkCollision(Movable& gameObject);

    void checkScalingAdjustment(Movable& movable);
};
