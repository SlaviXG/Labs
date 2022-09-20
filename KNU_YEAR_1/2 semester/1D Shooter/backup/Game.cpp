#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;

    //Game logic
    this->gameIsOver = false;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;
}

void Game::initWindow()
{
    this->videoMode.height = WIN_HEIGHT;
    this->videoMode.width = WIN_WIDTH;

    this->window = new sf::RenderWindow(videoMode, "1D Shooter", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
//    this->enemy.setOutlineColor(sf::Color::Green);
//    this->enemy.setOutlineThickness(1.f);
}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->gameIsOver;
}

//Functions
void Game::spawnEnemy()
{
    /**
        @return void

        Spawns enemies and sets their colors and positions.
        -Sets a random position
        -Sets a random color
        -Adds enemy to the vector.
     */

    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
        );

    this->enemy.setFillColor(sf::Color::Green);

    //Spawn the enemy
    this->enemies.push_back(this->enemy);


}

void Game::pollEvents()
{
    //Event poling
    while(this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
            {
                this->window->close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            }
        }
    }
}

void Game::updateMousePositions()
{
    /**
        @return void

        Updates the mouse positions:
        -Mouse positions relative to window (Vector2i)
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
    /**
        @return void

        Updates the enemy spawn timer and spawns enemies
        when the total amount of enemies is smaller than maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen.
     */

    //Updating the timer for enemy spawning
    if(this->enemies.size() < this->maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and resets the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    //Moving and updating enemies
    for(size_t i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        enemies[i].move(0.f, 3.f);

        //Delete if the enemy reaches the bottom of the screen
        if(this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i); /// IS better to have pointer-structures
            this->health -= 1;
            std::cout << "Health: " << this->health << std::endl;
        }

    }

    //Check if clicked upon
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(this->mouseHeld == false)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for(size_t i = 0; i < this->enemies.size() and deleted == false; i++)
            {
                if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {
                    //Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    //Gain points
                    this->points += 1;
                    std::cout << "Points: " << this->points << std::endl;
                }
            }
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}

void Game::update()
{
    this->pollEvents();

    if(this->gameIsOver == false)
    {
        //Update mouse position
        this->updateMousePositions();

        this->updateEnemies();
    }

    //End game condition
    if(this->health == 0)
        this->gameIsOver = true;
}

void Game::renderEnemies()
{
    //Rendering all the enemies
    for(auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}

void Game::render()
{
    /**
        @return void

        - clear old frame
        - render new objects
        - display frame in window

        Renders the game objects.
    */

    this->window->clear();

    //Draw game content
    this->renderEnemies();

    this->window->display();
}