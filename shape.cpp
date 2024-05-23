#include "shape.h"

Segment::Segment(S2d base, double angle, double length)
    : base(base), angle(angle), length(length)
{
    calculateEndPoint();
}

void Segment::calculateEndPoint()
{
    end.x = base.x + length * std::cos(angle);
    end.y = base.y + length * std::sin(angle);
}

double Segment::angleDifference(const Segment &other) const
{
    double diff = other.angle - angle;
    return normalizeAngle(diff);
}

bool Segment::overlapsWith(const Segment &other) const
{
    if ((base.x == other.base.x && base.y == other.base.y) ||
        (end.x == other.end.x && end.y == other.end.y))
    {
        double angleDiff = angleDifference(other);
        return std::fabs(angleDiff) < EPSIL_ZERO;
    }
    return false;
}

bool Segment::intersectsWith(const Segment &other) const
{
    // Implement intersection logic based on the orientation and onSegment functions described
    // Using placeholder logic for now
    return false;
}

double normalizeAngle(double angle)
{
    while (angle <= M_PI)
        angle += 2 * M_PI;
    while (angle > M_PI)
        angle -= 2 * M_PI;
    return angle;
}

Circle::Circle(S2d center, double radius)
    : center(center), radius(radius) {}

Square::Square(S2d center, double sideLength)
    : center(center), sideLength(sideLength) {}
