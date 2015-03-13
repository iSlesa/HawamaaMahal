#include "Vector.h"

//returns world coordinate system to viewing coordinates system transformation matrix
Matrix Cam(Vector& Camera, Vector& LookTo)
{
    Matrix WtoC(4,4);
    Vector u,n,v(0,1,0);

    n=LookTo-Camera;

    n.normalize();
    u=v.crossProduct(n);

    u.normalize();

    v=n.crossProduct(u);

    Matrix Translate(4,4);
    Translate(0,0) = 1;    Translate(0,1) = 0;      Translate(0,2) = 0;    Translate(0,3) = -Camera.x;
    Translate(1,0) = 0;    Translate(1,1) = 1;      Translate(1,2) = 0;    Translate(1,3) = -Camera.y;
    Translate(2,0) = 0;    Translate(2,1) = 0;      Translate(2,2) = 1;    Translate(2,3) = -Camera.z;
    Translate(3,0) = 0;    Translate(3,1) = 0;      Translate(3,2) = 0;    Translate(3,3) = 1;

    Matrix Rotate(4,4);
    Rotate(0,0) = u.x;    Rotate(0,1) = u.y;      Rotate(0,2) = u.z;    Rotate(0,3) = 0;
    Rotate(1,0) = v.x;    Rotate(1,1) = v.y;      Rotate(1,2) = v.z;    Rotate(1,3) = 0;
    Rotate(2,0) = n.x;    Rotate(2,1) = n.y;      Rotate(2,2) = n.z;    Rotate(2,3) = 0;
    Rotate(3,0) = 0;    Rotate(3,1) = 0;      Rotate(3,2) = 0;    Rotate(3,3) = 1;

    WtoC=Rotate*Translate;
    return WtoC;
}
//returns projection matrix
Matrix proj(float near, float far, float width, float height)
{
    float ar = width/height;
    float d = 1.0f/(far - near);
    Matrix CToS(4,4);
    CToS(0,0) = 1/ar;    CToS(0,1) = 0;      CToS(0,2) = 0;    CToS(0,3) = 0;
    CToS(1,0) = 0;    CToS(1,1) = 1;      CToS(1,2) = 0;    CToS(1,3) = 0;
    CToS(2,0) = 0;    CToS(2,1) = 0;      CToS(2,2) = -(far+near)*d;    CToS(2,3) = -(2*far*near)*d;
    CToS(3,0) = 0;    CToS(3,1) = 0;      CToS(3,2) = -1;    CToS(3,3) = 0;
    return CToS;
}
// returns matrix for x-axis rotation
Matrix rotX(float theta)
{
    Matrix T(4,4); //Transformation matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = 1;     T(0,1) = 0;         T(0,2) = 0;             T(0,3) = 0;
    T(1,0) = 0;     T(1,1) = cos(angle);T(1,2) = -sin(angle);   T(1,3) = 0;
    T(2,0) = 0;     T(2,1) = sin(angle);T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;     T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    return T;
}
//testai aru matrices return garchha
Matrix rotY(float theta)
{
    Matrix T(4,4); //Transformation matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = 0;         T(0,2) = sin(angle);    T(0,3) = 0;
    T(1,0) = 0;             T(1,1) = 1;         T(1,2) = 0;             T(1,3) = 0;
    T(2,0) = -sin(angle);   T(2,1) = 0;         T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    return T;
}

Matrix rotZ(float theta)
{
    Matrix T(4,4); //Transformation matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = -sin(theta);       T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = sin(angle);    T(1,1) = cos(theta);        T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;             T(2,1) = 0;                 T(2,2) = 1;    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;                 T(3,2) = 0;    T(3,3) = 1;
    return T;
}

Matrix trans(float x, float y, float z)
{
    Matrix T(4,4);
    T(0,0) = 1;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = x;
    T(1,0) = 0;    T(1,1) = 1;      T(1,2) = 0;    T(1,3) = y;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = z;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    return T;
}

Matrix scal(float sx, float sy, float sz)
{
    Matrix T(4,4);
    T(0,0) = sx;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = 0;    T(1,1) = sy;      T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = sz;    T(2,3) = 0;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    return T;
}
// function that transforms a/c to the matrix provided
void Transform(Matrix m, Vector& v)
{
    Matrix vec(4,1);
    vec = vec.retMat(v);
    vec = m*vec;
    v = Vector(vec);
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

