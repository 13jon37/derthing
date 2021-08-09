#include "include/math.h"

#include <iostream>

float get_distance(Vector2f pos1, Vector2f pos2)
{
    int operation = ((pos2.x - pos1.x) * (pos2.x - pos1.x)) + ((pos2.y - pos1.y) * (pos2.y - pos1.y));
    return sqrt(operation);
}