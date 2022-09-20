#ifndef DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_POINT_H
#define DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_POINT_H

#include <fstream>

double generate_random_double(double lower_bound, double upper_bound);

struct Point
{
    double x;
    double y;
    double z;

    Point();
    Point(double, double, double);
    void getRandomValue();
    Point& read(std::istream &);
    Point& write(std::ostream &);

};

std::istream& operator >> (std::istream&, Point&);
std::ostream& operator << (std::ostream&, Point);



#endif //DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_POINT_H
