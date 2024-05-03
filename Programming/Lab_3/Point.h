#ifndef A__POINT_H
#define A__POINT_H

#include <fstream>

//Randomizing functions
double generate_random_double(double lower_bound, double upper_bound);

struct Point
{
    //Coordinates
    double x;
    double y;
    double z;

    //Constructors / Destructors
    Point();
    Point(double, double, double);

    //Functions
    void getRandomValue();
    void sortCoordinates();
    Point& read(std::istream &);
    Point& write(std::ostream &);

};

//Input operator
std::istream& operator >> (std::istream&, Point&);
//Output operator
std::ostream& operator << (std::ostream&, Point);

//Comparison operators
bool operator >= (Point, Point);
bool operator <= (Point, Point);
bool operator > (Point, Point);
bool operator < (Point, Point);
bool operator == (Point, Point);
bool operator != (Point, Point);

#endif
