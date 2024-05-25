#ifndef SHAPE_H
#define SHAPE_H
#include <algorithm>
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
    double longueur;
    S2d fin;
    unsigned id;
    Segment(S2d base, double angle, double longueur);

    double differenceAngle(const Segment &autre) const;
    bool chevaucheAvec(const Segment &autre) const;
    bool intersecteAvec(const Segment &autre) const;

private:
    void calculerPointFinal();
};

class Cercle
{
public:
    S2d centre;
    double rayon;

    Cercle(S2d centre, double rayon);
};

class Carre
{
public:
    S2d centre;
    double cote;

    Carre(S2d centre, double cote);
};

double normaliserAngle(double angle);

#endif
