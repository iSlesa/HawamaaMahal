#pragma once

#include <math.h>
#include "Matrix.h"

class Vertex;  //forward declaration of class Vertex
const float pi = 3.1415926535897;

class Vector{
    public:
    float x,y,z;
    float i;
    public:
    Vector(){}
    Vector(float xx,float yy, float zz):x(xx),y(yy),z(zz){}
    Vector(const Matrix& mat);
    Vector operator + (const Vector& vec) const {return Vector(x+vec.x,y+vec.y,z+vec.z);}
    Vector operator - (const Vector& vec) const {return Vector(x-vec.x,y-vec.y,z-vec.z);}
    Vector operator / (const float& d) const {return Vector(x/d,y/d,z/d);}
    Vector operator * (const float& d) const {return Vector(x*d,y*d,z*d);}
    void operator = (const Vector& in) {
                x=in.x;
                y=in.y;
                z=in.z;
            }
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

//transformation functions defined in transformation.cpp

Matrix rotX(float theta);
Matrix rotY(float theta);
Matrix rotZ(float theta);
Matrix trans(float x, float y, float z);
Matrix scal(float sx, float sy, float sz);
void Transform(Matrix m, Vector& v);

Matrix Cam(Vector& Camera, Vector& LookTo);

Matrix proj(float near, float far, float width, float height);

void RotateY(Vector& Point,float theta);
