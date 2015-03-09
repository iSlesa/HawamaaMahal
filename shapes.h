
#pragma once
#include<math.h>

class shapes{
    protected:
        Vector* ver;
        int r,g,b;
    public:
        void Draw()
        {

        }
};
class cube: public shapes{
    public:
        cube(Vector v, int l, int b, int h, int r, int g,int blue)
        {
            this->r=r;
            this->g=g;
            this->b=blue;
            ver = new Vector[8];
            ver[0]=v;
            ver[1]=Vector(v.x+l,v.y,v.z);
            ver[2]=Vector(v.x+l,v.y-h,v.z);
            ver[3]=Vector(v.x,v.y-h,v.z);
            ver[4]=Vector(v.x,v.y,v.z-b);
            ver[5]=Vector(v.x+l,v.y,v.z-b);
            ver[6]=Vector(v.x+l,v.y-h,v.z-b);
            ver[7]=Vector(v.x,v.y-h,v.z-b);
        }
        void Draw(Vector Camera, Vector LookTo,float near, float far, float width, float height)
        {
            point _2d[8];
            for(int i=0;i<8;i++)
            {
                _2d[i] = WorldToPixel(ver[i],Camera,LookTo,near,far,width,height);
            }
            Vertex v[8];
            for(int i=0;i<8;i++)
            {
                v[i] = Vertex(_2d[i].x,_2d[i].y,_2d[i].z);
            }

            Triangle T(v[0],v[1],v[2]);

            Line e0(v[0],v[1]);
            Line e2(v[1],v[2]);
            Line e3(v[2],v[3]);
            Line e4(v[3],v[0]);
            Line e5(v[4],v[5]);
            Line e6(v[5],v[6]);
            Line e7(v[6],v[7]);
            Line e8(v[7],v[4]);
            Line e9(v[0],v[4]);
            Line e10(v[1],v[5]);
            Line e11(v[2],v[6]);
            Line e12(v[3],v[7]);

//            e0.DrawLine(16,0,31);
//            e2.DrawLine(161,0,131);
//            e3.DrawLine(16,0,31);
//            e4.DrawLine(16,0,31);
//            e5.DrawLine(16,0,31);
//            e6.DrawLine(126,0,31);
//            e7.DrawLine(16,0,31);
//            e8.DrawLine(1,0,31);
//            e9.DrawLine(16,110,31);
//            e10.DrawLine(16,0,31);
//            e11.DrawLine(16,140,31);
//            e12.DrawLine(16,1,31);

//            DrawTriangle(v[0],v[1],v[2],g_width,g_height,16,0,161);

            Triangle T1(v[0],v[1],v[2]);
            Triangle T2(v[0],v[3],v[2]);
            Triangle T3(v[4],v[5],v[6]);
            Triangle T4(v[4],v[7],v[6]);
            Triangle T5(v[5],v[1],v[2]);
            Triangle T6(v[5],v[6],v[2]);
            Triangle T7(v[4],v[0],v[3]);
            Triangle T8(v[4],v[7],v[3]);
            Triangle T9(v[7],v[6],v[2]);
            Triangle T10(v[7],v[3],v[2]);
            Triangle T11(v[5],v[0],v[4]);
            Triangle T12(v[5],v[0],v[1]);
            T1.DrawTriangle(r,g,b);
            T2.DrawTriangle(r,g,b);
            T3.DrawTriangle(r,g,b);
            T4.DrawTriangle(r,g,b);
            T5.DrawTriangle(r,g,b);
            T6.DrawTriangle(r,g,b);
            T7.DrawTriangle(r,g,b);
            T8.DrawTriangle(r,g,b);
            T9.DrawTriangle(r,g,b);
            T10.DrawTriangle(r,g,b);
            T11.DrawTriangle(r,g,b);
            T12.DrawTriangle(r,g,b);
        }
        ~cube()
        {
            delete ver;
        }
};

class pyramid : public shapes{
    public:
        pyramid(Vector v, int h, int w, int r, int g,int b)
        {
            this->r=r;
            this->g=g;
            this->b=b;
            ver = new Vector[5];
            ver[0]=v;
            ver[1]=Vector(v.x-w/2,v.y-h,v.z+w/2);
            ver[2]=Vector(v.x+w/2,v.y-h,v.z+w/2);
            ver[3]=Vector(v.x+w/2,v.y-h,v.z-w/2);
            ver[4]=Vector(v.x-w/2,v.y-h,v.z-w/2);
        }
        void Draw(Vector Camera, Vector LookTo,float near, float far, float width, float height)
        {
            point _2d[5];
            for(int i=0;i<5;i++)
            {
                _2d[i] = WorldToPixel(ver[i],Camera,LookTo,near,far,width,height);
            }
            Vertex v[5];
            for(int i=0;i<5;i++)
            {
                v[i] = Vertex(_2d[i].x,_2d[i].y,_2d[i].z);
            }
            Line e0(v[1],v[2]);
            Line e1(v[2],v[3]);
            Line e2(v[3],v[4]);
            Line e3(v[4],v[1]);
            Line e4(v[0],v[1]);
            Line e5(v[0],v[2]);
            Line e6(v[0],v[3]);
            Line e7(v[0],v[4]);

//            e0.DrawLine(16,0,31);
//            e1.DrawLine(161,0,131);
//            e2.DrawLine(16,0,31);
//            e3.DrawLine(16,0,31);
//            e4.DrawLine(16,0,31);
//            e5.DrawLine(126,0,31);
//            e6.DrawLine(16,0,31);
//            e7.DrawLine(1,0,31);

            Triangle T1(v[0],v[2],v[3]);
            Triangle T2(v[0],v[4],v[3]);
            Triangle T3(v[0],v[1],v[4]);
            Triangle T4(v[0],v[1],v[2]);
//            Triangle T5(v[1],v[2],v[3]);
//            Triangle T6(v[1],v[4],v[3]);
//            Triangle T7(v[4],v[0],v[3]);
//            Triangle T8(v[4],v[7],v[3]);
            T1.DrawTriangle(r,g,b);
            T2.DrawTriangle(r,g,b);
            T3.DrawTriangle(r,g,b);
            T4.DrawTriangle(r,g,b);
//            T5.DrawTriangle(18,232,123);
//            T6.DrawTriangle(18,232,123);
//            T7.DrawTriangle(18,232,123);
//            T8.DrawTriangle(18,232,123);


        }
        ~pyramid()
        {
            delete ver;
        }
};

class flag: public shapes{
    public:
    flag(Vector v1,Vector v2,Vector v3,Vector v4,Vector v5, int r, int g,int b)
    {
        this->r=r;
            this->g=g;
            this->b=b;
        ver = new Vector[5];
        ver[0]=v1;
        ver[1]=v2;
        ver[2]=v3;
        ver[3]=v4;
        ver[4]=v5;
    }
    void Draw(Vector Camera, Vector LookTo,float near, float far, float width, float height)
    {
        point _2d[5];
        for(int i=0;i<5;i++)
        {
            _2d[i] = WorldToPixel(ver[i],Camera,LookTo,near,far,width,height);
        }
        Vertex v[5];
        for(int i=0;i<5;i++)
        {
            v[i] = Vertex(_2d[i].x,_2d[i].y,_2d[i].z);
        }
        Line e0(v[0],v[1]);
        Line e1(v[3],v[4]);
        Line e2(v[4],v[2]);

        e0.DrawLine(r,g,b);
//        e1.DrawLine(161,0,131);
//        e2.DrawLine(16,0,31);

        Triangle f(v[2],v[3],v[4]);
        f.DrawTriangle(r,g,b);
//
//      DrawTriangle(v[0],v[1],v[2],g_width,g_height,16,0,161,zBuffer);
    }
    ~flag()
        {
            delete ver;
        }

};

class sphere: public shapes{
    private:
        float radius;
        int bPower,bPoints, bMask;
        int sections_in_b;
        int total_p;
        float section_arc;
        float x_angle, y_angle;
        float x,y,z;
        Vector center;
    public:

        sphere()
        {
        }

        sphere(Vector c, float rad,  int r, int g,int b)
        {
            this->r=r;
            this->g=g;
            this->b=b;
            center=c;
            radius=rad;
            bPower= 8; bPoints=256; bMask=bPoints-2;
            sections_in_b=((bPoints/2)-1);
            total_p= sections_in_b*bPoints;
            section_arc = 6.28/(float)sections_in_b;
            ver = new Vector[total_p];
        }

        void Draw(Vector Camera, Vector LookTo,float near, float far, float width, float height)
        {
            for(int i=0; i<total_p;i++)
            {
                x_angle = (float)(i&1)+(i>>bPower);
                y_angle = (float)((i&bMask)>>1)+((i>>bPower)*sections_in_b);
                x_angle*=(float)section_arc/2.0f; // remember - 180° x rot not 360
                y_angle*=(float)section_arc;
                x= radius*sin(x_angle)*sin(y_angle);
                y= radius*cos(x_angle);
                z= radius*sin(x_angle)*cos(y_angle);
                ver[i] = Vector(x,y,z);
                ver[i] = Vector(x+center.x,y+center.y,z+center.z);
            }
            point _2d[total_p];
            for(int i=0;i<total_p;i++)
            {
            _2d[i] = WorldToPixel(ver[i],Camera,LookTo,near,far,width,height);
            }
            Vertex v[total_p];
            for(int i=0;i<total_p;i++)
            {
            v[i] = Vertex(_2d[i].x,_2d[i].y,_2d[i].z);
            }
//            for(int j=0; j<total_p-2;j++)
//            {
//                Line l1(v[j],v[j+1]);
//                Line l2(v[j],v[j+2]);
//                Line l3(v[j+2],v[j+1]);
//                l1.DrawLine(0,0,0);
//                l2.DrawLine(0,0,0);
//                l3.DrawLine(0,0,0);
//            }
            for(int j=0; j<total_p-2;j++)
            {
                Triangle T(v[j],v[j+1],v[j+2]);
                T.DrawTriangle(r,g,b);
            }
        }
        ~sphere()
        {
            delete ver;
        }


};

class clouds: public shapes{
    public:
    clouds()
    {
    }
    clouds(Vector v,int r,int g,int b)
    {
        ver = new Vector[1];
        ver[0] =v;
        this->r=r;
        this->g=g;
        this->b=b;
    }
    void Draw(Vector Camera, Vector LookTo,float near, float far, float width, float height)
    {
        sphere cloud1(ver[0],10,r,g,b);
        sphere cloud2(ver[0]+Vector(18,0,0),15,r,g,b);
        sphere cloud3(ver[0]+Vector(38,0,0),10,r,g,b);

        cloud1.Draw(Camera, LookTo, near, far,  width,  height);
        cloud2.Draw(Camera, LookTo, near, far,  width,  height);
        cloud3.Draw(Camera, LookTo, near, far,  width,  height);
    }
    ~clouds()
    {
        delete ver;
    }

};
