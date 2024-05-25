#include "simulation.h"
#include "lifeform.h"
#include "shape.h"
#include "constantes.h"
#include "message.h"
#include <iostream>

int main()
{
    S2d base = {0.0, 0.0};
    Segment seg(base, M_PI / 4, 10.0);

    std::cout << "Testing segment length..." << std::endl;
    test_segment_length_outside(seg);

    std::cout << "Testing segment angle..." << std::endl;
    test_segment_angle_outside(seg);

    Entity entity(5.0, 5.0);
    entity.age = 1;
    Entity::Entity_tab.push_back(entity);

    std::cout << "Testing lifeform age..." << std::endl;
    test_lifeform_age(entity);

    std::cout << "Testing lifeform center outside..." << std::endl;
    test_lifeform_center_outside(entity);

    std::cout << "Testing lifeform computed outside..." << std::endl;
    test_lifeform_computed_outside(entity);

    Scavenger scavenger(3.0, 3.0);
    scavenger.radius = 1.0;

    std::cout << "Testing scavenger radius..." << std::endl;
    test_scavenger_radius_outside(scavenger);
    Coral coral(2.0, 2.0, base, M_PI / 4, 5.0);
    coral.nbr_seg = 2;
    coral.segments.push_back(Segment(base, M_PI / 4, 5.0));
    coral.segments.push_back(Segment({5.0, 5.0}, M_PI / 2, 5.0));

    std::cout << "Testing segment superposition..." << std::endl;
    test_segment_superposition(coral);

    std::cout << "Testing lifeform ID uniqueness..." << std::endl;
    test_lifeform_id(entity);

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
