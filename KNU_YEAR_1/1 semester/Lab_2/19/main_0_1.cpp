#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
//using namespace sf;

signed main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "The path of the point", sf::Style::Close);

    sf::VertexArray line (sf::Lines, 2);

    sf::VertexArray trajectory(sf::Points);

    line[0].position = sf::Vector2f (-1,-1);
    line[1].position = sf::Vector2f (-1,-1);
    line[0].color = sf::Color::Blue;
    line[1].color = sf::Color::Cyan;

    sf::Vector2f dir (-1, -1);
    sf::Vector2f norm (-1, -1);
    sf::Vector2f move (-1, -1);
    float temp_y = -1;
    bool rest_cl2 = 0;

    float RAD = 35.f;

    sf::CircleShape circle(RAD);
    circle.setFillColor(sf::Color::Green);

    bool line_ready = 0;

    float xp, yp;

    const float accel = 0.03;
    const float grav = 100;
    float velocity = 0;

    sf::Clock clock1, clock2;

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(line[0].position == sf::Vector2f (-1,-1))
                {
                    xp = sf::Mouse::getPosition(window).x;
                    yp = sf::Mouse::getPosition(window).y;

                    line[0].position = sf::Vector2f (xp,yp);
                }
                else if(line[1].position == sf::Vector2f (-1,-1))
                {
                    xp = sf::Mouse::getPosition(window).x;
                    yp = sf::Mouse::getPosition(window).y;

                    line[1].position = sf::Vector2f (xp,yp);
                    if(line[0].position.y > line[1].position.y) swap(line[0].position, line[1].position);
                    line_ready = 1;

                    dir.x = (line[1].position.x - line[0].position.x);
                    dir.y = (line[1].position.y - line[0].position.y);

                    norm = sf::Vector2f(dir.y/sqrt(dir.y*dir.y + dir.x*dir.x),- dir.x / sqrt(dir.x*dir.x + dir.y*dir.y));
                    if(norm.y > 0) {norm.x*=-1; norm.y*=-1;}

                    //cout << "Normal Vector : " << norm.x << ' ' << norm.y << endl;

                    xp = line[0].position.x - RAD; yp = line[0].position.y - RAD;
                    xp += RAD * norm.x; yp += RAD * norm.y;

                    xp += (dir.x)/15; yp +=(dir.y)/15;

                    circle.setPosition(xp, yp);

                    trajectory.append(sf::Vector2f(xp+RAD,yp+RAD));

                    move.x = dir.x/ sqrt(dir.x*dir.x + dir.y*dir.y);
                    move.y = dir.y/ sqrt(dir.x*dir.x + dir.y*dir.y);

                    //cout << "Move direction Vector : " << move.x << ' ' << move.y << endl;

                    sf::sleep(sf::microseconds(400));

                    window.clear();
                    window.draw(line);
                    window.draw(trajectory);
                    window.draw(circle);
                    window.display();

                    clock1.restart();

                }
            }
        }

        if(line_ready)
        {
            //cout << clock.getElapsedTime().asSeconds() << endl;

            float cur_time1 = clock1.getElapsedTime().asSeconds();
            float cur_time2 = clock2.getElapsedTime().asSeconds();
            velocity+=accel * cur_time1;

            /// 0 -> 1

            //cout << xp + velocity*move.x << ' ' << yp + velocity*move.y << endl;
            if((yp + velocity*move.y - RAD * norm.y + RAD > line[1].position.y) or
            (move.x == 1 and xp + velocity*move.x + RAD > line[1].position.x) or
            (move.x == -1 and xp + velocity*move.x + RAD < line[1].position.x))
            {

                if(!rest_cl2)
                {
                    clock2.restart();
                    rest_cl2 = 1;
                    continue;
                }

                temp_y = yp + velocity*move.y + grav*cur_time2*cur_time2;
                //cout << temp_y << endl;
                trajectory.append(sf::Vector2f(xp + velocity*move.x + RAD,yp + velocity*move.y + grav*cur_time2*cur_time2 + RAD));
                circle.setPosition(xp + velocity*move.x, yp + velocity*move.y + grav*cur_time2*cur_time2);

            }
            else
            {
                trajectory.append(sf::Vector2f(xp + velocity*move.x + RAD,yp + velocity*move.y + RAD));
                circle.setPosition(xp + velocity*move.x, yp + velocity*move.y);
            }

            window.clear();
            window.draw(line);
            window.draw(trajectory);
            window.draw(circle);
            window.display();

            if((temp_y > 600 + 2*RAD) or dir.x ==0)
            {
                line[0].position = sf::Vector2f (-1,-1);
                line[1].position = sf::Vector2f (-1,-1);
                dir = sf::Vector2f (-1, -1);
                norm = sf::Vector2f (-1, -1);
                move = sf::Vector2f (-1, -1);
                velocity = 0;
                line_ready = 0;
                rest_cl2 = 0;
                temp_y = -1;
                trajectory.clear();
                window.clear();
                window.display();
                continue;
            }
        }
        else
        {
            window.clear();
            window.display();
        }

    }

    return 0;
}
