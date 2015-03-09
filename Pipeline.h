#pragma once
#include "Matrix.h"
#include "Vector.h"

Vector WorldToView(const Vector World,const Vector& Camera,const Vector& LookTo,float near, float far, float width, float height){
    Matrix WtoC(4,4);

//    float ar = width/height;
//
//    float d = 1.0f/(far - near);

//    Matrix CToS(4,4);
//    CToS(0,0) = 1/ar;    CToS(0,1) = 0;      CToS(0,2) = 0;    CToS(0,3) = 0;
//    CToS(1,0) = 0;    CToS(1,1) = 1;      CToS(1,2) = 0;    CToS(1,3) = 0;
//    CToS(2,0) = 0;    CToS(2,1) = 0;      CToS(2,2) = -(far+near)*d;    CToS(2,3) = -(2*far*near)*d;
//    CToS(3,0) = 0;    CToS(3,1) = 0;      CToS(3,2) = -1;    CToS(3,3) = 0;


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

    Matrix S(4,1);
    S(0) = World.x;
    S(1) = World.y;
    S(2) = World.z;
    S(3) = 1;

    S = WtoC*S;
    Vector view(S);
    return view;
//    S = CToS * S;
//    Vector r(S);
//    point SS;
//    SS.x = (r.x*0.5f+0.5f)*width;
//    SS.y = (r.y*0.5f+0.5f)*height;
//    SS.z = r.z;
//    return SS;

}
point ViewToPixel(const Vector World,const Vector& Camera,const Vector& LookTo,float near, float far, float width, float height)
{
    float ar = width/height;
    float d = 1.0f/(far - near);
    Matrix CToS(4,4);
    CToS(0,0) = 1/ar;    CToS(0,1) = 0;      CToS(0,2) = 0;    CToS(0,3) = 0;
    CToS(1,0) = 0;    CToS(1,1) = 1;      CToS(1,2) = 0;    CToS(1,3) = 0;
    CToS(2,0) = 0;    CToS(2,1) = 0;      CToS(2,2) = -(far+near)*d;    CToS(2,3) = -(2*far*near)*d;
    CToS(3,0) = 0;    CToS(3,1) = 0;      CToS(3,2) = -1;    CToS(3,3) = 0;
    Matrix S(4,1);
    S = S.retMat(World);
    S = CToS * S;
    Vector r(S);
    point SS;
    SS.x = (r.x*0.5f+0.5f)*width;
    SS.y = (r.y*0.5f+0.5f)*height;
    SS.z = World.z;
   // std::cout<<SS.z<<std::endl;
    return SS;

}
point WorldToPixel(const Vector World,const Vector& Camera,const Vector& LookTo,float near, float far, float width, float height)
{
    Vector x;
    x = WorldToView(World,Camera,LookTo,near,far,width,height);
    return ViewToPixel(x,Camera,LookTo,near,far,width,height);
}

