#include <random>
#include <ctime>

#include "Point.h"


int generate_random_int(int max_value, int min_value = 1)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_value, max_value);
    return dist(gen);
}

double generate_random_double(double lower_bound, double upper_bound)
{
    static std::default_random_engine generator(unsigned(time(nullptr)));
    std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);

    return distribution(generator);
}

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::getRandomValue()
{
    x = generate_random_double(-1000, 1000);
    y = generate_random_double(-1000, 1000);
    z = generate_random_double(-1000, 1000);
}

Point& Point::read(std::istream &cin)
{
    cin >> x >> y >> z;
    return *this;
}


Point& Point::write(std::ostream &cout)
{
    cout << "X: " << x << "\tY: " << y << "\tZ: " << z << std::endl;
    return *this;
}

std::istream& operator >> (std::istream &cin, Point &P)
{
    P.read(cin);
    return cin;
}


std::ostream& operator << (std::ostream &cout, Point P)
{
    P.write(cout);
    return cout;
}