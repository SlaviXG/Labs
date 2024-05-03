#ifndef INC_1D_SHOOTER_GAME_H
#define INC_1D_SHOOTER_GAME_H

#include <iostream>
#include "NodeListDeque.h"
#include "Player.h"
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

/*
    Class that acts as the game engine.
    Wrapper class.
*/

class Game
{
private:
    //Variables
    //Window parameters
    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 600;
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    //Mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Game logic
    bool gameIsOver;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned maxEnemies;

    //Game objects
    sf::VertexArray line;
    Player* player;
    NodeListDeque <std::pair<sf::RectangleShape, bool>> bullets;
    NodeListDeque <sf::RectangleShape> enemies;
    sf::RectangleShape enemy;


    //Private functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initLine();
    void initEnemies();
public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;
    const bool getEndGame() const;

    //Functions
    void spawnEnemy();

    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void updatePlayer();
    void updateBullets();
    void update();

    void renderLine();
    void renderBullets();
    void renderPlayer();
    void renderEnemies();
    void render();
};


#endif //INC_1D_SHOOTER_GAME_H
