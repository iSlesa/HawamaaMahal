#pragma once

#include <math.h>
#include "Matrix.h"

class Vector{
    public:
    float x,y,z;
    public:
    Vector(){}
    Vector(float xx,float yy, float zz):x(xx),y(yy),z(zz){}
    Vector(const Matrix& mat);
    Vector operator + (const Vector& vec) const {return Vector(x+vec.x,y+vec.y,z+vec.z);}
    Vector operator - (const Vector& vec) const {return Vector(x-vec.x,y-vec.y,z-vec.z);}
    Vector operator / (const float& d) const {return Vector(x/d,y/d,z/d);}
    Vector operator * (const float& d) const {return Vector(x*d,y*d,z*d);}
    Vector crossProduct(const Vector& v) const {return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);}
    float dotProduct (const Vector& v) const {return x * v.x + y * v.y + z * v.z;}
    float norm() const {return x*x + y*y + z*z ;}
    float magnitude() const {return sqrt(norm());}
    void normalize(){
            float l=sqrt(x*x+y*y+z*z);
            if(l!=0){
            x=x/l;
            y=y/l;
            z=z/l;
            }}
    float& operator [] (int i){return (&x)[i];}
};
class point{
    public: float x,y,z; //z for depth
    public: point(){}
            point(float xx,float yy):x(xx),y(yy){z=0;}
            point(float xx, float yy, float zz): x(xx),y(yy),z(zz){}
            point(const point& in):x(in.x),y(in.y),z(in.z){}
            void operator = (const point& in){
                x = in.x;
                y = in.y;
                z = in.z;
            }
};
