#include <iostream>
#include <vector>
#include "lifeform.h"

std::vector<Algae> algae_list;
std::vector<Coral> coral_list;
std::vector<Scavenger> scavenger_list;

void initialize()
{
    algae_list.emplace_back(10, 10);
    coral_list.emplace_back(20, 20);
    scavenger_list.emplace_back(30, 30);
}

void updateEntities()
{
    for (auto &algae : algae_list)
    {
        algae.update();
    }
    for (auto &coral : coral_list)
    {
        coral.update();
    }
    for (auto &scavenger : scavenger_list)
    {
        scavenger.update();
    }
}

void handleCollisions()
{
    // Implement collision detection and handling here
}