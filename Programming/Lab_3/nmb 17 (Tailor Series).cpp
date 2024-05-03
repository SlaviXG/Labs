#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace  std;

const double E = 2.7182818284;
const double PI = 3.14159265359;

const double INF = 1.7E+300;
const double DELTA = 1e-4;

static const int VIEW_WIDTH = 750.0f;
static const int VIEW_HEIGHT = 750.0f;

const float default_zoom = 0.008f;

vector <double> derivatives_x0;

double Function_from_user (double x)
{
    //return x*sin(x) - 3*x;
    //return x*sin(x);
    //return 3;
    return sin(x);
    //return exp(x);
}

double nth_derivative (double (*F) (double x), double x0, int n)
{
    if(n==0)
        return derivatives_x0[0] = F(x0);
    else
        return  derivatives_x0[n] = (nth_derivative(F, x0 + DELTA, n-1) - nth_derivative(F, x0 - DELTA, n-1)) / (2 * DELTA);
}

double binpow (double a, int n)
{
    if(n == 0) return  1;

    if(n % 2 == 1) return a * binpow(a, n-1);

    else
    {
        double b = binpow(a, n/2);
        return  b * b;
    }
}

double Tailor_X(double x, double &x0)
{
    double res = 0.0f;

    int degree = derivatives_x0.size() - 1;

    for(int k = 0; k <= degree; k++)
    {
        double addition = derivatives_x0[k] * binpow(x - x0, k);

        int div = k;
        while(div>0)
        {
            addition/= double(div);
            div--;
        }

        res += addition;
    }

    return res;
}

void input_values (int &n, double &x0, double &a, double &b)
{
    cout << "Please, Enter the degree of approximation : ";
    cin >> n;
    cout << "Enter X0 coordinate of the point : ";
    cin >> x0;
    cout <<"Please, enter left and right integration boundaries : " << endl;
    cin >> a >> b;
    if(a > b) swap (a, b);
}

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
    float aspect_ratio = float(window.getSize().x) / float(window.getSize().y);

    view.setSize(VIEW_WIDTH * aspect_ratio, VIEW_HEIGHT);

    view.zoom(default_zoom);
}

void Zoom_view_with_wheel(int &mouse_delta, sf::View &view)
{
    if(mouse_delta >= 1)
        view.zoom(0.5f * mouse_delta);
    if(mouse_delta <= -1 and view.getSize().x < VIEW_WIDTH)
        view.zoom(2.0f * abs(mouse_delta));

    if(view.getSize().x > VIEW_WIDTH)
        view.setSize(sf::Vector2f(VIEW_WIDTH,VIEW_HEIGHT));
}

void build_axis(sf::VertexArray &axis_x, sf::VertexArray &axis_y, sf::View &view)
{
    axis_x[0].position = sf::Vector2f(view.getCenter().x - VIEW_WIDTH/2.0f, view.getCenter().y);
    axis_x[1].position = sf::Vector2f(view.getCenter().x + VIEW_WIDTH/2.0f, view.getCenter().y);
    axis_y[0].position = sf::Vector2f(view.getCenter().x, view.getCenter().y - VIEW_HEIGHT/2.0f);
    axis_y[1].position = sf::Vector2f(view.getCenter().x, view.getCenter().y + VIEW_HEIGHT/2.0f);
    axis_x[0].color = sf::Color::Black;
    axis_x[1].color = sf::Color::Black;
    axis_y[0].color = sf::Color::Black;
    axis_y[1].color = sf::Color::Black;
}

void build_function (sf::VertexArray &vis_function, sf::View &view, double &left_boundary, double &right_boundary, double &square)
{
    unsigned long long *iter = new unsigned long long (0);

    for(double i = -VIEW_WIDTH/2.0f; i <= VIEW_WIDTH/2.0f; i+=DELTA)
    {
        double func_x = Function_from_user(i);
        vis_function.append(sf::Vector2f(view.getCenter().x + i, view.getCenter().y - func_x));
        vis_function[*iter].color = sf::Color::Blue;
        *iter+=1;

        if(i >= left_boundary and i <=right_boundary)
            square+=func_x*DELTA;
    }

    delete iter;

    cout << "Function Built" << endl;
}

void build_Tailor (sf::VertexArray &vis_tailor, sf::View &view, double &left_boundary, double &right_boundary, double &x0, double &square)
{
    unsigned long long *iter = new unsigned long long (0);

    for(double i = -VIEW_WIDTH/2.0f; i <= VIEW_WIDTH/2.0f; i+=DELTA)
    {
        double Tailor = Tailor_X(i, x0);
        vis_tailor.append(sf::Vector2f(view.getCenter().x + i, view.getCenter().y - Tailor));
        vis_tailor[*iter].color = sf::Color::Red;
        *iter+=1;

        if(i >= left_boundary and i <=right_boundary)
            square+=Tailor*DELTA;
    }

    delete iter;

    cout << "Tailor Built" << endl;
}

void Visualize (sf::RenderWindow &window, double &left_boundary, double &right_boundary, double &x0)
{
    sf::View view(sf::Vector2f(VIEW_WIDTH/2.0f, VIEW_HEIGHT/2.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

    double Square_F = 0.0f;
    double Square_T = 0.0f;

    window.setView(view);

    sf::VertexArray vis_function(sf::Points);
    sf::VertexArray vis_tailor(sf::Points);
    sf::VertexArray axis_x(sf::Lines, 2);
    sf::VertexArray axis_y(sf::Lines, 2);

    sf::Text lbnd, rbnd;

    build_axis(axis_x, axis_y, view);

    build_function(vis_function, view, left_boundary, right_boundary, Square_F);
    build_Tailor(vis_tailor, view, left_boundary, right_boundary, x0, Square_T);

    cout << "Integral error : " << abs(Square_F - Square_T) << endl;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed :
                {
                    int xmp = sf::Mouse::getPosition(window).x;
                    int ymp = sf::Mouse::getPosition(window).y;
                    cout << "Mouse position in the window : " << xmp << ' ' << ymp << endl;
                    break;
                }

                case sf::Event::Resized :
                {
                    ResizeView(window, view);
                    window.setView(view);
                    break;
                }

                case sf::Event::MouseWheelMoved :
                {
                    int mouse_delta = event.mouseWheel.delta;
                    Zoom_view_with_wheel(mouse_delta, view);
                    window.setView(view);
                    break;
                }


                case sf::Event::Closed :
                    window.close();
                    break;

            }

        }

        window.clear(sf::Color::White);
        window.draw(axis_x);
        window.draw(axis_y);
        window.draw(lbnd);
        window.draw(rbnd);
        window.draw(vis_function);
        window.draw(vis_tailor);
        window.display();
    }
}

void inf_derivatives (vector <double> &derivatives_x0, int &degree)
{
    for(int i = 0; i <=degree; i++)
        derivatives_x0.push_back(INF);
}

int main()
{
    int n;
    double x0, left_boundary, right_boundary;

    input_values(n, x0, left_boundary, right_boundary);

    inf_derivatives(derivatives_x0, n);

    nth_derivative(Function_from_user, x0, n);

    /*
    for(int i = int(left_boundary); i <=int(right_boundary); i++)
        cout << i << " : " << Function_from_user(double(i)) << "   " << Tailor_X(double(i),x0) << endl;
    */

    sf::RenderWindow window (sf :: VideoMode (VIEW_WIDTH, VIEW_HEIGHT), "Taylor series");

    Visualize(window, left_boundary, right_boundary, x0);

    return 0;
}
