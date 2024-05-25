#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include "shape.h"

class Simulation
{
public:
    Simulation();

    bool readFile(const std::string &filename);

private:
    std::vector<Segment> segments;
    std::vector<Circle> circles;
    std::vector<Square> squares;

    bool parseLine(const std::string &line);
};

#endif
