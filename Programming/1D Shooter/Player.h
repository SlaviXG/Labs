#ifndef INC_1D_SHOOTER_PLAYER_H
#define INC_1D_SHOOTER_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "NodeListDeque.h"

class Player : public sf::RectangleShape
{

    //Player logic
    unsigned points;
    unsigned health;
    bool playerLooksRight;
    float movement_speed;

    //Player objects
    NodeListDeque <std::pair<sf::RectangleShape, bool>>* bullets; // pair <object, direction>

    //Private functions
    void initVariables();

public :
    //Constructors / Destructors
    Player(unsigned health, NodeListDeque <std::pair<sf::RectangleShape, bool>>* bullets, sf::Vector2f size, sf::Vector2f position);

    //Accessors
    unsigned getHealth() const;
    unsigned getPoints() const;
    float getVelocity();
    bool isDirectedToRight();

    //Functions
    void rotatePlayer();
    void shoot();
    void makeLookRight();
    void makeLookLeft();
    void minusHP();
    void addPoints(unsigned);
};


#endif //INC_1D_SHOOTER_PLAYER_H
