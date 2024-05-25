#include "shape.h"

Segment::Segment(S2dS2d base, double angle, double length)
    : base(base), angle(angle), length(length)
{
    calculateEndS2dS2d();
}

void Segment::calculateEndS2dS2d()
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

double direction(S2d p,S2d q,S2d r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool areCollinearAndOverlapping(S2d a1,S2d b1,S2d a2,S2d b2) {
    if (direction(a1, b1, a2) == 0) {
        if (a2.x <= max(a1.x, b1.x) && a2.x >= min(a1.x, b1.x) && a2.y <= max(a1.y, b1.y) && a2.y >= min(a1.y, b1.y)) {
            return true;
        }
    }
    return false;
}

bool Segment::intersectsWith(const Segment &other) const
{
    double d1 = direction(this->base,this->end,other.base);
    double d2 = direction(this->base,this->end,other.end);
    double d3 = direction(other.base,other.end,this->base);
    double d4 = direction(other.base,other.end,this->end);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    }

    if (areCollinearAndOverlapping(this->base,this->end,other.base,other.end) || areCollinearAndOverlapping(other.base,other.end,this->base,this->end)) {
        return true;
    }

    return false;
}

double normalizeAngle(double angle)
{
   if (angle > PI) {
        angle -= 2.0 * PI;
    } else if (angle < -PI) {
        angle += 2.0 * PI;
    }

    return angle;
}

