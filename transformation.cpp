#include "Vector.h"

void RotateX(Vector& Point,float theta){
    Matrix T(4,4); //Transformation matrix
    Matrix P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = 1;     T(0,1) = 0;         T(0,2) = 0;             T(0,3) = 0;
    T(1,0) = 0;     T(1,1) = cos(angle);T(1,2) = -sin(angle);   T(1,3) = 0;
    T(2,0) = 0;     T(2,1) = sin(angle);T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;     T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

}

void RotateY(Vector& Point,float theta){
    Matrix T(4,4); //Transformation matrix
    Matrix P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = 0;         T(0,2) = sin(angle);    T(0,3) = 0;
    T(1,0) = 0;             T(1,1) = 1;         T(1,2) = 0;             T(1,3) = 0;
    T(2,0) = -sin(angle);   T(2,1) = 0;         T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

}


void RotateZ(Vector& Point,float theta){
    Matrix T(4,4); //Transformation matrix
    Matrix P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = -sin(theta);       T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = sin(angle);    T(1,1) = cos(theta);        T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;             T(2,1) = 0;                 T(2,2) = 1;    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;                 T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

}

void Translate(Vector& Point,float x,float y,float z){
    Matrix T(4,4); //Transformation matrix
    Matrix P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = 1;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = x;
    T(1,0) = 0;    T(1,1) = 1;      T(1,2) = 0;    T(1,3) = y;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = z;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

}

void Scale(Vector& Point, float sx, float sy, float sz){
    Matrix T(4,4);
    Matrix P(4,1);
    //Transformation matrix
    T(0,0) = sx;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = 0;    T(1,1) = sy;      T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = sz;    T(2,3) = 0;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);
}

