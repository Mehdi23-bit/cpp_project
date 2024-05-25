#define SIMULATION_H
#include <vector>
#include <string>
#include "shape.h"
#include "lifeform.h"

void test_lifeform_age(Entity ent);
void test_lifeform_center_outside(Entity ent);
void test_lifeform_computed_outside(Entity ent);
void test_segment_length_outside(Segment seg);
void test_segment_angle_outside(Segment seg);
void test_scavenger_radius_outside(Scavenger sca);
void test_lifeform_id(Entity ent);
void test_intersection(Coral &obj);
void test_segment_superposition(Coral &obj);
