#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
//using namespace sf;

const double PI = 3.1415926;

float angle (float px, float py, float cx, float cy)
{
    float res = 0;
    float side = sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));

    float lx = cx + side;
    float ly = cy;

    float  dis = sqrt((px - lx)*(px - lx) + (py - ly)*(py - ly));

    res = 1 - dis*dis / (2*side*side);

    if(py > cy) return (2*PI - acos(res));

    else return acos(res);
}

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

    const float accel = 0.05;
    const float grav = 100;

    float velocity = 0;

    float temp_y = -1;
    bool rest_cl2 = 0;

    float RAD = 35.f;
    float d = -1;

    float fi = 0;
    float fi0 = 0;

    sf::CircleShape circle(RAD);
    circle.setFillColor(sf::Color::Green);

    bool line_ready = 0;
    bool c_ready = 0;

    float omega = 0;

    float xp, yp;

    float n_x = -1, n_y = -1;

    float center_x, center_y;

    float len;

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

                    dir.x = (line[1].position.x - line[0].position.x);
                    dir.y = (line[1].position.y - line[0].position.y);

                    norm = sf::Vector2f(dir.y/sqrt(dir.y*dir.y + dir.x*dir.x),- dir.x / sqrt(dir.x*dir.x + dir.y*dir.y));
                    if(norm.y > 0) {norm.x*=-1; norm.y*=-1;}

                    xp = line[0].position.x - RAD; yp = line[0].position.y - RAD;
                    xp += RAD * norm.x; yp += RAD * norm.y;

                    xp += (dir.x)/15; yp +=(dir.y)/15;

                    len = sqrt((line[0].position.x + (dir.x)/15 -  line[1].position.x) * (line[0].position.x + (dir.x)/15 -  line[1].position.x) + (line[0].position.y + (dir.y)/15 - line[1].position.y) * (line[0].position.y + (dir.y)/15 - line[1].position.y));

                    circle.setPosition(xp, yp);

                    line_ready = 1;

                    window.clear();
                    window.draw(line);
                    window.draw(circle);
                    window.display();

                }
                else if(n_x == -1 and n_y == -1)
                {

                    n_x = sf::Mouse::getPosition(window).x;
                    n_y = sf::Mouse::getPosition(window).y;

                    if((n_x - (xp+RAD))*(n_x - (xp+RAD)) + (n_y - (yp+RAD))*(n_y - (yp+RAD)) > RAD*RAD)
                    {
                        n_x = -1;
                        n_y = -1;
                        break;
                    }

                    move.x = dir.x/ sqrt(dir.x*dir.x + dir.y*dir.y);
                    move.y = dir.y/ sqrt(dir.x*dir.x + dir.y*dir.y);

                    //cout << "Move direction Vector : " << move.x << ' ' << move.y << endl;

                    center_x = xp + RAD;
                    center_y = yp + RAD;

                    d = sqrt((n_x - center_x) * (n_x - center_x) + (n_y - center_y) * (n_y - center_y));

                    fi0 = angle(n_x, -n_y, center_x, -center_y);

                    n_x = center_x + d*cos(fi);
                    n_y = center_y + d*sin(fi);

                    c_ready = 1;

                    window.clear();
                    window.draw(line);
                    window.draw(trajectory);
                    window.draw(circle);
                    window.display();
                    clock1.restart();
                }
            }
        }

        if(c_ready)
        {
            float cur_time1 = clock1.getElapsedTime().asSeconds();
            float cur_time2 = clock2.getElapsedTime().asSeconds();
            velocity+=accel * cur_time1;

            /// 0 -> 1

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

                center_x = xp + velocity*move.x + RAD;
                center_y = yp + velocity*move.y + grav*cur_time2*cur_time2 + RAD;

                omega = velocity/RAD;


                if(move.x > 0) {
                    fi =  fi0 + omega;
                }
                if(move.x < 0) {
                    fi = fi0 - omega;
                }

                n_x = center_x + d*cos(fi);
                n_y = center_y + d*sin(fi);
                trajectory.append(sf::Vector2f(n_x,n_y));

                circle.setPosition(xp + velocity*move.x, yp + velocity*move.y + grav*cur_time2*cur_time2);

            }
            else
            {
                center_x = xp + velocity*move.x + RAD;
                center_y = yp + velocity*move.y + RAD;

                //cout << len << ' ' << 2*PI*RAD << endl;
                //cout << len / (2 * PI * RAD) << endl;
                cout << velocity << endl;

                omega = velocity/RAD;

                if(move.x > 0) {
                    fi = fi0 + omega;
                }
                if(move.x < 0) {
                    fi =  fi0 - omega;
                }

                n_x = center_x + d*cos(fi);
                n_y = center_y + d*sin(fi);

                //cout << d*cos(fi) << ' ' << d*sin(fi) << endl;

                trajectory.append(sf::Vector2f(n_x,n_y));
                circle.setPosition(xp + velocity*move.x, yp + velocity*move.y);
            }

            window.clear();
            window.draw(line);
            window.draw(trajectory);
            window.draw(circle);
            window.display();

            if(temp_y > 600 + 2*RAD)
            {
                line[0].position = sf::Vector2f (-1,-1);
                line[1].position = sf::Vector2f (-1,-1);
                dir = sf::Vector2f (-1, -1);
                norm = sf::Vector2f (-1, -1);
                move = sf::Vector2f (-1, -1);
                velocity = 0;
                c_ready = 0;
                rest_cl2 = 0;
                line_ready = 0;
                temp_y = -1;
                d = -1;
                fi = 0;
                fi0 = 0;
                n_x = -1; n_y = -1;
                trajectory.clear();
                window.clear();
                window.display();
                continue;
            }
        }
        else
            if(line_ready) continue;
        else
        {
            window.clear();
            window.display();
        }

    }

    return 0;
}
