#include <iostream>
#include <vector>
#include <cassert>
#include "lifeform.h"
#include "message.h"
#include "constantes.h"
#include "shape.h"
#include "shape.cpp"

using namespace std;
void test_lifeform_age(Entity ent)
{
    Entity lifeform = ent;
    if (lifeform.age <= 0)
    {
        std::cerr << message::lifeform_age(lifeform.age) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for lifeform center outside boundaries
void test_lifeform_center_outside(Entity ent)
{
    Entity lifeform = ent;
    if (lifeform.position.x < 1 || lifeform.position.x > dmax - 1 ||
        lifeform.position.y < 1 || lifeform.position.y > dmax - 1)
    {
        std::cerr << message::lifeform_center_outside(lifeform.position.x, lifeform.position.y) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for lifeform computed outside boundaries
void test_lifeform_computed_outside(Entity ent)
{
    Entity lifeform = ent;

    if (lifeform.position.x <= 0 || lifeform.position.x >= dmax ||
        lifeform.position.y <= 0 || lifeform.position.y >= dmax)
    {
        std::cerr << message::lifeform_computed_outside(lifeform.id, lifeform.position.x, lifeform.position.y) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for segment length outside allowed range
void test_segment_length_outside(Segment seg)
{
    Segment segment = seg;
    segment.id = 1;

    if (segment.longueur < l_repro - l_seg_interne || segment.longueur >= l_repro)
    {
        std::cerr << message::segment_length_outside(segment.id, segment.longueur) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for segment angle outside allowed range
void test_segment_angle_outside(Segment seg)
{
    Segment segment = seg;
    if (segment.angle < -M_PI || segment.angle > M_PI)
    {
        std::cerr << message::segment_angle_outside(segment.id, segment.angle) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for scavenger radius outside allowed range
void test_scavenger_radius_outside(Scavenger sca)
{
    Scavenger scavenger = sca;

    if (scavenger.radius < r_sca || scavenger.radius >= r_sca_repro)
    {
        std::cerr << message::scavenger_radius_outside(scavenger.radius) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Test for unique and valid lifeform IDs
void test_lifeform_id()
{
    int size = Entity::Entity_tab.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Entity::Entity_tab[i].id == Entity::Entity_tab[j].id)
            {
                std::cerr << message::lifeform_duplicated_id(Entity::Entity_tab[j].id) << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
    }
}
// Test for segment superposition
void test_segment_superposition(Coral &obj)
{
    for (int i = 0; i < obj.nbr_seg - 1; i++)
    {
        for (int j = 0; j < obj.nbr_seg - 1; j++)
        {
            Segment seg1 = obj.segments[i];
            Segment seg2 = obj.segments[j];
            if (direction(seg1.base, seg1.fin, seg2.base) == 0)
            {
                if (seg2.base.x <= std::max(seg1.base.x, seg1.fin.x) && seg2.base.x >= std::min(seg1.base.x, seg1.fin.x) && seg2.base.y <= std::max(seg1.base.y, seg1.fin.y) && seg2.base.y >= std::min(seg1.base.y, seg1.fin.y))
                {
                    std::cerr << message::segment_superposition(seg1.id, i, i + 1) << std::endl;
                    std::exit(EXIT_FAILURE);
                }
            }
        }
    }
}
