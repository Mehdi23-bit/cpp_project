#include "simulation.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "lifeform.h"
#include "shape.h"

Simulation::Simulation() {}

bool Simulation::readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (!parseLine(line))
        {
            return false;
        }
    }

    file.close();
    return true;
}

bool Simulation::parseLine(const std::string &line)
{
    std::istringstream iss(line);
    char type;
    iss >> type;

    if (type == 'S')
    {
        double x, y, angle, length;
        iss >> x >> y >> angle >> length;
        segments.emplace_back(S2d{x, y}, angle, length);
    }
    else if (type == 'C')
    {
        double x, y, radius;
        iss >> x >> y >> radius;
        circles.emplace_back(S2d{x, y}, radius);
    }
    else if (type == 'Q')
    {
        double x, y, side;
        iss >> x >> y >> side;
        squares.emplace_back(S2d{x, y}, side);
    }
    else
    {
        std::cerr << "Unknown shape type in line: " << line << std::endl;
        return false;
    }

    return true;
}
