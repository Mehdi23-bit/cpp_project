#ifndef SHAPE_H
#define SHAPE_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <cmath>

const double EPSIL_ZERO = 1e-10;

struct S2d
{
    double x;
    double y;
};

class Segment
{
public:
    S2d base;
    double angle; 
    double length;
    S2d end;

    Segment(S2d base, double angle, double length);

    double angleDifference(const Segment &other) const;
    bool overlapsWith(const Segment &other) const;
    bool intersectsWith(const Segment &other) const;

private:
    void calculateEndPoint();
};

class Circle
{
public:
    S2d center;
    double radius;

    Circle(S2d center, double radius);
};

class Square
{
public:
    S2d center;
    double sideLength;

    Square(S2d center, double sideLength);
};

double normalizeAngle(double angle);

#endif 
