#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "Draw.h"

//world to pixel transformation function
Vertex WorldToPixel(const Vector World, Matrix w2c , Matrix projection)
{
//world matrix
    Matrix S(4,1);
    S(0) = World.x;
    S(1) = World.y;
    S(2) = World.z;
    S(3) = 1;
// world to camera transformation
    S = w2c*S;
//depth value for zbuffering
    float temp = S(2)/S(3);
// project to screen
    S = projection*S;
// normalize
    Vertex pix;
    pix.x = (S(0)/S(3)*0.5f+0.5f)*g_width;
    pix.y = (S(1)/S(3)*0.5f+0.5f)*g_height;
    pix.z = temp;
    pix.i = 0.0f; //default intensity value
    return pix;
}

