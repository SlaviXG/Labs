#include <random>
#include <ctime>

#include "Point.h"


//Randomizing functions
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

//Constructors / Destructors
Point::Point()
{
    x = y = z = 0;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}


//Functions
void Point::getRandomValue()
{
    x = generate_random_double(-1000, 1000);
    y = generate_random_double(-1000, 1000);
    z = generate_random_double(-1000, 1000);
    this->sortCoordinates();
}

void Point::sortCoordinates()
{
    // x >= y >= z
    if(this->z < this->y) std::swap(this->z, this->y);
    if(this->y < this->x) std::swap(this->y, this->x);
    if(this->z < this->y) std::swap(this->z, this->y);
}

Point& Point::read(std::istream &cin)
{
    cin >> x >> y >> z;
    return *this;
}

Point& Point::write(std::ostream &cout)
{
    cout << "(" << x << ", " << y << ", " << z << ")";
    return *this;
}

//Input operator
std::istream& operator >> (std::istream &cin, Point &P)
{
    P.read(cin);
    return cin;
}

//Output operator
std::ostream& operator << (std::ostream &cout, Point P)
{
    P.write(cout);
    return cout;
}

//Comparison operators
bool operator >= (Point A, Point B)
{
    /**
        Checks if A >= B
        where x <= y <= z
    */

    if(A.x > B.x)return true;
    else if(A.x == B.x)
    {
        if(A.y > B.y) return true;
        else if(A.y == B.y)
        {
            if(A.z >= B.z) return true;
        }
    }
    return false;
}

bool operator <= (Point A, Point B)
{
    /**
        Checks if A <= B
        where x <= y <= z
    */

    if(A.x < B.x)return true;
    else if(A.x == B.x)
    {
        if(A.y < B.y) return true;
        else if(A.y == B.y)
        {
            if(A.z <= B.z) return true;
        }
    }
    return false;
}

bool operator > (Point A, Point B)
{
    if(A.x > B.x)return true;
    else if(A.x == B.x)
    {
        if(A.y > B.y) return true;
        else if(A.y == B.y)
        {
            if(A.z > B.z) return true;
        }
    }
    return false;
}

bool operator < (Point A, Point B)
{
    if(A.x < B.x)return true;
    else if(A.x == B.x)
    {
        if(A.y < B.y) return true;
        else if(A.y == B.y)
        {
            if(A.z < B.z) return true;
        }
    }
    return false;
}

bool operator == (Point A, Point B)
{
    if(A.x == B.x and A.y == B.y and A.z == B.z)
        return true;
    else
        return false;
}

bool operator != (Point A, Point B)
{
    if(A.x == B.x and A.y == B.y and A.z == B.z)
        return false;
    else
        return true;
}