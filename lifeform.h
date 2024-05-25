#ifndef ENTITIES_H
#define ENTITIES_H

#include <vector>
#include <cmath>

// Constants
const int MAX_X = 100;
const int MAX_Y = 100;
const int ALG_LIFE_MAX = 100;
const int ALG_BIRTH_RATE = 10;
const int COR_LIFE_MAX = 200;
const int L_REPRO = 10;
const double DELTA_ROT = 0.1f;
const double DELTA_L = 1.0f;
const int SCA_LIFE_MAX = 150;
const double DELTA_R_SCA = 0.5f;
const double R_SCA_REPRO = 5.0f;
const double R_SCA = 10.0f;

struct Coordinate {
    double x;
    double y;
};

class Entity {
public:
    Coordinate position;
    int age;

    Entity(double x, double y) : position({x, y}), age(1) {}
    virtual void update() = 0;
};

class Algae : public Entity {
public:
    Algae(double x, double y) : Entity(x, y) {}
    void update() override {
        age++;
    }
};

class Coral : public Entity {
public:
    enum Status { ALIVE, DEAD };
    Status status;
    std::vector<Coordinate> segments;
    double angle;

    Coral(double x, double y) : Entity(x, y), status(ALIVE), angle(0.0f) {
        segments.push_back({x, y});
    }

    void update() override {
        age++;
        if (age >= COR_LIFE_MAX) {
            status = DEAD;
        } else if (status == ALIVE) {
            // Growth and reproduction logic here
        }
    }

    void grow() {
        // Grow coral logic here
    }

    void rotate(double delta) {
        angle += delta;
    }
};

class Scavenger : public Entity {
public:
    enum Status { LIBRE, MANGE };
    Status status;
    double radius;

    Scavenger(double x, double y) : Entity(x, y), status(LIBRE), radius(1.0f) {}

    void update() override {
        age++;
        // Move and consume logic here
    }

    void moveTowards(const Coordinate& target) {
        // Move towards target logic here
    }

    void consume() {
        // Consume coral logic here
    }
};

#endif 