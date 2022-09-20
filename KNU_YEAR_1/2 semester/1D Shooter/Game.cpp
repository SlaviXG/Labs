#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;

    //Game logic
    this->gameIsOver = false;

    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::initWindow()
{
    this->videoMode.height = WIN_HEIGHT;
    this->videoMode.width = WIN_WIDTH;

    this->window = new sf::RenderWindow(videoMode, "1D Shooter", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
    this->player = new Player(10, &this->bullets, sf::Vector2f(50.f, 75.f),
                              sf::Vector2f(
                                      this->window->getSize().x/2 - 25.f,
                                      this->window->getSize().y/2 - 75.f));
}

void::Game::initLine()
{
    this->line = sf::VertexArray (sf::Lines, 2);
    this->line[0].position = sf::Vector2f(0, this->window->getSize().y/2);
    this->line[1].position = sf::Vector2f(this->window->getSize().x, this->window->getSize().y/2);
    this->line[1].color = sf::Color::White;
    this->line[0].color = sf::Color::White;
    this->line[1].color = sf::Color::White;
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(50.f, 50.f));
    //this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Red);
}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initLine();
    this->initEnemies();
}

Game::~Game()
{
    delete this->player;
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
        -Adds enemy to the vector.
     */

    this->enemy.setPosition(0,this->window->getSize().y/2 - this->enemy.getSize().y);

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
    for(auto en_ptr = enemies.head; en_ptr!=nullptr; en_ptr=en_ptr->next)
    {

        en_ptr->value->move(2.f, 0.f);

        //Delete if the enemy reaches the side of the screen
        if(en_ptr->value->getPosition().x > this->window->getSize().x)
        {
            this->enemies.erase(en_ptr);
            break;
        }
    }
}

void Game::updatePlayer()
{
    /**
        @return void

        - Rotates player
        - Updates shooting
        - Updates collision with enemies
        - Updates end game condition
     */

    if(this->event.type == 4) // if the button is pressed
    {
        //std::cout << this->event.key.code << std::endl;
        //std::cout << this->event.type << std::endl;

        //Rotate on R
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            this->player->rotatePlayer();

        //Move left on A
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            this->player->makeLookLeft();
            this->player->move(sf::Vector2f(- this->player->getVelocity(), 0));
        }

        //Move right on D
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->player->makeLookRight();
            this->player->move(sf::Vector2f(this->player->getVelocity(), 0));
        }

        //Shooting on space
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(bullets.tail!= nullptr)
            {
                if(std::abs(bullets.tail->value->first.getPosition().x - player->getPosition().x) > 4*bullets.tail->value->first.getSize().x)
                {
                    this->player->shoot();
                    this->event = sf::Event();
                }
            }
            else
            {
                this->player->shoot();
                this->event = sf::Event();
            }
        }
    }

    for(auto enemy_ptr = enemies.head; enemy_ptr!=nullptr; enemy_ptr=enemy_ptr->next)
    {
        if (enemy_ptr->value->getGlobalBounds().intersects(this->player->getGlobalBounds()))
        {
            this->enemies.erase(enemy_ptr);
            this->player->minusHP();
            std::cout << "Health: " << this->player->getHealth() << std::endl;
            break;
        }
    }

    //End game condition
    if(this->player->getHealth() == 0)
        this->gameIsOver = true;
}

void Game::updateBullets()
{
    //For loop that controls the bullet's location
    for(auto bullet_ptr = bullets.head; bullet_ptr!=nullptr; bullet_ptr=bullet_ptr->next)
    {
        if(bullet_ptr->value->second) // bullet moves right
        {
            bullet_ptr->value->first.move(5.f, 0.f);

            //Delete if the bullet reaches the side of the screen
            if(bullet_ptr->value->first.getPosition().x > this->window->getSize().x)
            {
                this->bullets.erase(bullet_ptr);
                break;
            }
        }
        else // bullet moves left
        {
            bullet_ptr->value->first.move(-5.f, 0.f);

            //Delete if the bullet reaches the side of the screen
            if(bullet_ptr->value->first.getPosition().x < 0)
            {
                this->bullets.erase(bullet_ptr);
                break;
            }
        }
    }

    //Control of collisions
    for(auto bullet_ptr = bullets.head; bullet_ptr!=nullptr; bullet_ptr=bullet_ptr->next)
    {
        for(auto enemy_ptr = enemies.head; enemy_ptr!=nullptr; enemy_ptr=enemy_ptr->next)
        {
            if (enemy_ptr->value->getGlobalBounds().intersects(bullet_ptr->value->first.getGlobalBounds()))
            {
                this->bullets.erase(bullet_ptr);
                this->enemies.erase(enemy_ptr);
                this->player->addPoints(1);
                std::cout << "Points: " << this->player->getPoints() << std::endl;
                break;
            }
        }
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

    this->updatePlayer();

    this->updateBullets();
}

void Game::renderLine()
{
    this->window->draw(this->line);
}

void Game::renderBullets()
{
    for(auto bullet_ptr = bullets.head; bullet_ptr!=nullptr; bullet_ptr=bullet_ptr->next)
    {
        this->window->draw(bullet_ptr->value->first);
    }
}

void::Game::renderPlayer()
{
    this->window->draw(*this->player);
}

void Game::renderEnemies()
{
    //Rendering all the enemies
    for(auto en_ptr = enemies.head; en_ptr!=nullptr; en_ptr=en_ptr->next)
    {
        this->window->draw(*en_ptr->value);
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
    this->renderLine();
    this->renderBullets();
    this->renderPlayer();
    this->renderEnemies();

    this->window->display();
}