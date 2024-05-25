#include "shape.h"

Segment::Segment(S2d base, double angle, double longueur)
    : base(base), angle(angle), longueur(longueur)
{
    calculerPointFinal();
}

void Segment::calculerPointFinal()
{
    fin.x = base.x + longueur * std::cos(angle);
    fin.y = base.y + longueur * std::sin(angle);
}

double Segment::differenceAngle(const Segment &autre) const
{
    double diff = autre.angle - angle;
    return normaliserAngle(diff);
}

bool Segment::chevaucheAvec(const Segment &autre) const
{
    if ((base.x == autre.base.x && base.y == autre.base.y) ||
        (fin.x == autre.fin.x && fin.y == autre.fin.y))
    {
        double angleDiff = differenceAngle(autre);
        return fabs(angleDiff) < EPSIL_ZERO ? true : false;
    }
    return false;
}

double direction(S2d p, S2d q, S2d r)
{
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool sontColinéairesEtChevauchants(S2d a1, S2d b1, S2d a2, S2d b2)
{
    if (direction(a1, b1, a2) == 0)
    {
        if (a2.x <= std::max(a1.x, b1.x) && a2.x >= std::min(a1.x, b1.x) && a2.y <= std::max(a1.y, b1.y) && a2.y >= std::min(a1.y, b1.y))
        {
            return true;
        }
    }
    return false;
}

bool Segment::intersecteAvec(const Segment &autre) const
{
    double d1 = direction(this->base, this->fin, autre.base);
    double d2 = direction(this->base, this->fin, autre.fin);
    double d3 = direction(autre.base, autre.fin, this->base);
    double d4 = direction(autre.base, autre.fin, this->fin);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    {
        return true;
    }

    if (sontColinéairesEtChevauchants(this->base, this->fin, autre.base, autre.fin) ||
        sontColinéairesEtChevauchants(autre.base, autre.fin, this->base, this->fin))
    {
        return true;
    }

    return false;
}

double normaliserAngle(double angle)
{
    if (angle > M_PI)
    {
        angle -= 2.0 * M_PI;
    }
    else if (angle < -M_PI)
    {
        angle += 2.0 * M_PI;
    }

    return angle;
}
