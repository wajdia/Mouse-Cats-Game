#include "Controller.h"

Controller::Controller() 
{}

void Controller::run() 
{
    sf::Clock clock;

    vector<ifstream> allLevels = openPlaylistFiles("Playlist.txt");
    m_board = Board(allLevels[0]);
    
    optimizeDimensions(m_board);

    fillVector(m_board);

    m_window.create(sf::VideoMode(m_windowWidth,m_windowHeight),"Mouse & Cats");
    m_window.setFramerateLimit(60);
    m_window.clear(MAIN_BACKGROUND_COLOR);
    
    draw();
    m_window.display();

    while (m_window.isOpen()) {
        auto deltaTime = clock.restart();
        
        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                return;
                break;

            case sf::Event::KeyPressed:
                m_mouse->setDirection(event.key.code);
                m_mouse->update(deltaTime,*this);
                checkCollision(*m_mouse);
                checkScalingAdjustment(*m_mouse);

                break;
            default:
                break;
            }
        }

        
        update(deltaTime);
        for (auto& cat : m_cats)
        {
            cat->move(m_mouse->getPosition());
            checkCollision(*cat);
            checkScalingAdjustment(*m_mouse);
        }

        draw();
        m_window.display();
    }
}

int Controller::getHeightBound() const
{
    return (int)m_board.getRows()*m_board.getTileSize();
}

int Controller::getWidthBound() const
{
    return (int)m_board.getCols()*m_board.getTileSize();
}

void Controller::update(sf::Time deltaTime) 
{
    for (auto& cat : m_cats) 
    {
        cat->update(deltaTime,*this);
    }
}

void Controller::draw()
{
    m_window.clear(MAIN_BACKGROUND_COLOR);
    for (auto& obj : m_nonMovableObjects) 
    {
        obj->draw(m_window);
    }

    m_mouse->draw(m_window);

    for (auto& obj : m_cats) 
    {
        obj->draw(m_window);
    }
    
}

vector<ifstream> Controller::openPlaylistFiles(const string& filename)
{
    std::vector<std::ifstream> fileVector;
    ifstream file(filename);

    //checkif the file is open successfully
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return fileVector;
    }

    string line;
    while (getline(file, line))
    {
        ifstream individualFile(line);
        fileVector.push_back(move(individualFile));
    }

    return fileVector;
}

void Controller::fillVector(Board& board)
{
    vector<string> primitiveBoard = board.getBoard();

    for (int i = 0; i < primitiveBoard.size(); ++i)
    {
        const std::string& str = primitiveBoard[i];

        for (int j = 0; j < str.size(); ++j)
        {
            char c = str[j];
            if (c == MOUSE)
            {
                m_mouse = board.getMousePtr(i, j);
            }
            else if (c == SMART_CAT || c == NORMAL_CAT)
            {
                m_cats.push_back(board.getCatsPtrs(i, j,c));
            }
            else
            {
                std::unique_ptr<GameObject> obj = board.charToGameObject(c, i, j);
                if(obj!=nullptr)
                    m_nonMovableObjects.push_back(std::move(obj));
            }
        }      
    }
}

void Controller::optimizeDimensions(Board& board)
{
    int newCols = board.getCols();
    int newRows = board.getRows();

    int suggestedWidth = newCols * MINIMAL_TILE_SIZE  +
        BOARD_2WINDOW_FACTOR * PADDING;
    int suggestedHeight = newRows * MINIMAL_TILE_SIZE +
        BOARD_2WINDOW_FACTOR * PADDING;

    int maximalWidth = sf::VideoMode::getDesktopMode().width -
        WIDTH_FACTOR * PADDING;
    int maximalHeight = sf::VideoMode::getDesktopMode().height -
        HEIGHT_FACTOR * PADDING;

    m_windowWidth = std::max(std::min(suggestedWidth, maximalWidth),
        WINDOW_WIDTH);
    m_windowHeight = std::max(std::min(suggestedHeight, maximalHeight),
        WINDOW_HEIGHT);

    board.calculateTileSize(m_windowWidth, m_windowHeight);
}

void Controller::checkCollision(Movable& gameObject)
{
    for (auto& cat : m_cats)
    {
        if (gameObject.collidesWith(*cat))
        {
            gameObject.handleCollision(*cat);
        }
    }

    for (auto& staticObj : m_nonMovableObjects)
    {
        if (gameObject.collidesWith(*staticObj))
        {
            gameObject.handleCollision(*staticObj);
        }
    }
}

void Controller::checkScalingAdjustment(Movable& movable)
{
    //static var needed, not to change for every func call
    static sf::Clock scaleAdjustTimer;
    const float scaleAdjustInterval = 10.f;

    if (scaleAdjustTimer.getElapsedTime().asSeconds() >= scaleAdjustInterval)
    {
        movable.correctScale();
        scaleAdjustTimer.restart();
    }
    
}