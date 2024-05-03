#include "Player.h"

//Private functions
void Player::initVariables()
{
    this->points = 0;
    this->playerLooksRight = true;
    this->movement_speed = 2.f;
}


//Constructors / Destructors
Player::Player(unsigned int health, NodeListDeque <std::pair<sf::RectangleShape, bool>>* bullets, sf::Vector2f size, sf::Vector2f position)
{
    this->initVariables();

    this->health = health;

    this->setFillColor(sf::Color::White);
    this->setSize(size);
    this->setPosition(position.x, position.y);

    this->bullets = bullets;
}

//Accessors
unsigned Player::getHealth() const
{
    return this->health;
}

unsigned Player::getPoints() const
{
    return this->points;
}

float Player::getVelocity()
{
    return this->movement_speed;
}

bool Player::isDirectedToRight()
{
    return this->playerLooksRight;
}

//Functions


void Player::shoot()
{
    sf::RectangleShape bullet;
    bullet.setSize(sf::Vector2f(15.f, 5.f));
    bullet.setPosition(this->getPosition().x + this->getSize().x * 0.5,
                       this->getPosition().y + this->getSize().y * 0.45);
    bullet.setFillColor(sf::Color::Blue);
    this->bullets->push_back(std::pair(bullet, this->playerLooksRight));
}

void Player::rotatePlayer()
{
    if(playerLooksRight)
        makeLookLeft();
    else
        makeLookRight();
}

void Player::makeLookRight()
{
    this->playerLooksRight = true;
    //std::cout << "RIGHT" << std::endl;
}

void Player::makeLookLeft()
{
    this->playerLooksRight = false;
    //std::cout << "LEFT" << std::endl;
}

void Player::minusHP()
{
    this->health--;
}

void Player::addPoints(unsigned pts)
{
    this->points+=pts;
}
