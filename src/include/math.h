/* date = August 8th 2021 7:47 pm */

#ifndef MATH_H
#define MATH_H

#include <math.h>

struct Vector2f 
{
    Vector2f()
        : x(0.0f), y(0.0f)
    {}
    Vector2f(float p_x, float p_y)
        : x(p_x), y(p_y)
    {}
    
    float x, y;
};

float get_distance(Vector2f pos1, Vector2f pos2);


#endif //MATH_H
