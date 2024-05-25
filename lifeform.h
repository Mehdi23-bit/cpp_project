#ifndef ENTITIES_H
#define ENTITIES_H

#include <vector>
#include <cmath>
#include "constantes.h"
#include "shape.h"

struct Coordinate
{
    double x;
    double y;
};

class Entity
{
public:
    Coordinate position;
    int age;
    unsigned id;
    static std::vector<Entity> Entity_tab;
    Entity(double x, double y) : position({x, y}), age(1)
    {
        Entity_tab.push_back(*this);
    }
    void update()
    {
        age++;
    }
};

class Algae : public Entity
{
public:
    Algae(double x, double y) : Entity(x, y) {}
    void update()
    {
        age++;
    }
};

class Coral : public Entity
{
public:
    Status_cor status;
    Dir_rot_cor status_dir;
    std::vector<Segment>
        segments;
    double angle;
    Coordinate position;
    int nbr_seg;
    Coral(double x, double y, S2d base, double angle, double longueur) : Entity(x, y), status(ALIVE), angle(0.0f), status_dir(TRIGO)
    {
        Segment Seg(base, angle, longueur);
        segments.push_back(Seg);
        position.x = x;
        position.y = y;
    }
};

class Scavenger : public Entity
{
public:
    Status_sca status;
    double radius;
    Scavenger(double x, double y) : Entity(x, y), status(FREE), radius(1.0f) {}
    void moveTowards(const Coordinate &target);
    void consume();
};

#endif
