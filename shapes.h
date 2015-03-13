
#pragma once
#include "Pipeline.h"
#include<math.h>
#define ABS(a) ((a<0)? a*-1 : a)

Vector L(150,190,150);

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
            ver[0]=v;                       //defining the vertices
            ver[1]=Vector(v.x+l,v.y,v.z);
            ver[2]=Vector(v.x+l,v.y-h,v.z);
            ver[3]=Vector(v.x,v.y-h,v.z);
            ver[4]=Vector(v.x,v.y,v.z-b);
            ver[5]=Vector(v.x+l,v.y,v.z-b);
            ver[6]=Vector(v.x+l,v.y-h,v.z-b);
            ver[7]=Vector(v.x,v.y-h,v.z-b);
        }

        void CalculateNormalnAssignIntensity()  //something's wrong with this function code :S
        {
            Vector* normal;
            normal = new Vector[8];
            Vector* l;
            l = new Vector[8];
            normal[0] = ((ver[4]-ver[0]).crossProduct(ver[1]-ver[0]) + (ver[3]-ver[0]).crossProduct(ver[4]-ver[0]) + (ver[3]-ver[0]).crossProduct(ver[1]-ver[0]) )/3;
            normal[0].normalize();
            normal[1] = ((ver[0]-ver[1]).crossProduct(ver[5]-ver[1]) + (ver[2]-ver[1]).crossProduct(ver[0]-ver[1]) + (ver[5]-ver[1]).crossProduct(ver[2]-ver[1]) )/3;
            normal[1].normalize();
            normal[2] = ((ver[1]-ver[2]).crossProduct(ver[6]-ver[2]) + (ver[6]-ver[2]).crossProduct(ver[3]-ver[2]) + (ver[3]-ver[2]).crossProduct(ver[1]-ver[2]) )/3;
            normal[2].normalize();
            normal[3] = ((ver[7]-ver[3]).crossProduct(ver[0]-ver[3]) + (ver[0]-ver[3]).crossProduct(ver[2]-ver[3]) + (ver[2]-ver[3]).crossProduct(ver[7]-ver[3]) )/3;
            normal[3].normalize();
            normal[4] = ((ver[7]-ver[4]).crossProduct(ver[5]-ver[4]) + (ver[5]-ver[4]).crossProduct(ver[0]-ver[4]) + (ver[0]-ver[4]).crossProduct(ver[7]-ver[4]) )/3;
            normal[4].normalize();
            normal[5] = ((ver[4]-ver[5]).crossProduct(ver[6]-ver[5]) + (ver[6]-ver[5]).crossProduct(ver[1]-ver[5]) + (ver[1]-ver[5]).crossProduct(ver[4]-ver[5]) )/3;
            normal[5].normalize();
            normal[6] = ((ver[5]-ver[6]).crossProduct(ver[7]-ver[6]) + (ver[2]-ver[6]).crossProduct(ver[5]-ver[6]) + (ver[7]-ver[6]).crossProduct(ver[2]-ver[6]) )/3;
            normal[6].normalize();
            normal[7] = ((ver[6]-ver[7]).crossProduct(ver[4]-ver[7]) + (ver[3]-ver[7]).crossProduct(ver[6]-ver[7]) + (ver[4]-ver[7]).crossProduct(ver[3]-ver[7]) )/3;
            normal[7].normalize();

            for(int j=0;j<8;j++)
            {
                l[j] = L-ver[j];
                l[j].normalize();
            }
            for(int j=0;j<8;j++){
            ver[j].i =(1*1 + 1* 1 * normal[j].dotProduct(l[j]))/2;
            //std::cout<<ver[j].i;
            if (ver[j].i < 0)
                 ver[j].i = 0;
            if (ver[j].i > 1)
                    ver[j].i=1;
            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {
            CalculateNormalnAssignIntensity();
            Vertex v[8];
            for(int j=0;j<8;j++)
            {
                v[j] = WorldToPixel(ver[j],w2c,projection);
                v[j].i = ver[j].i;
            }

            Triangle T(v[0],v[1],v[2]);

//            Line e0(v[0],v[1]);
//            Line e2(v[1],v[2]);
//            Line e3(v[2],v[3]);
//            Line e4(v[3],v[0]);
//            Line e5(v[4],v[5]);
//            Line e6(v[5],v[6]);
//            Line e7(v[6],v[7]);
//            Line e8(v[7],v[4]);
//            Line e9(v[0],v[4]);
//            Line e10(v[1],v[5]);
//            Line e11(v[2],v[6]);
//            Line e12(v[3],v[7]);

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
        void _trans(Matrix m)
        {
            for(int i=0;i<8;i++)
            {
                Transform(m,ver[i]);
            }
        }
        ~cube()
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

    void CalculateNormalsnAssignIntensity()  //something's wrong here too
        {
            Vector normal;
            normal = (ver[2]-ver[3]).crossProduct(ver[4]-ver[3]);
            normal.normalize();
            Vector l = L-Vector((ver[2].x+ver[3].x+ver[4].x)/3,(ver[2].y+ver[3].y+ver[4].y)/3,(ver[2].z+ver[3].z+ver[4].z)/3);
            ver[2].i = ver[3].i = ver[4].i = (1+1*normal.dotProduct(l))/2;
        }

    void Draw(const Matrix w2c, const Matrix projection)
    {
        CalculateNormalsnAssignIntensity();
        Vertex v[5];
        for(int i=0;i<5;i++)
        {
            v[i] = WorldToPixel(ver[i],w2c, projection);
        }
        Line e0(v[0],v[1]);
//        Line e1(v[3],v[4]);
//        Line e2(v[4],v[2]);

        e0.DrawLine(r,g,b);
//        e1.DrawLine(161,0,131);
//        e2.DrawLine(16,0,31);

        Triangle f(v[2],v[3],v[4]);
        f.DrawTriangle(r,g,b);
        }
//      DrawTriangle(v[0],v[1],v[2],g_width,g_height,16,0,161,zBuffer);
        void _trans(Matrix m)
        {
            for(int i=0;i<5;i++)
            {
                Transform(m,ver[i]);
            }
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
            bPower= 4; bPoints=16; bMask=bPoints-2;
            sections_in_b=((bPoints/2)-1);
            total_p= sections_in_b*bPoints;
            section_arc = 6.28/(float)sections_in_b;
            ver = new Vector[total_p];
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
        }

        //void calculateIntensity(Vector Camera)
        void calculateIntensity()
        {
            for(int j=0;j<total_p;j++)
            {
                Vector  /*l(1,-1,1);/*/ l = (L - ver[j]);
             //   Vector v = Camera- ver[j];
               // Vector H;
               // H = (l + v);
               // float a = H.magnitude();
                //H = (l+v)/a;
                l.normalize();
                Vector n = ver[j];//-center;
                n.normalize();
                ver[j].i = (1+1*l.dotProduct(n)/*-n.dotProduct(H))/3;*/)/2;
                if (ver[j].i < 0)
                 ver[j].i = 0;
                if (ver[j].i > 1)
                    ver[j].i=1;

            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {
            //calculateIntensity(Vector(0,50,-100));
            calculateIntensity();
            Vertex v[total_p];
            for(int j=0;j<total_p;j++)
            {
            v[j] = WorldToPixel(ver[j],w2c,projection);
            v[j].i = ver[j].i;
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
        void _trans(Matrix m)
        {
            for(int i=0;i<total_p;i++)
            {
                Transform(m,ver[i]);
            }
        }
        void operator=(const sphere& in)
        {
            r= in.r;
            g= in.g;
            b = in.b;
//            radius = in.radius;
//            bPower = in.bPower;
//            bPoints = in.bPoints;
//            bMask = in.bMask;
//            sections_in_b = in.sections_in_b;
            total_p = in.total_p;
//            section_arc = in.section_arc;
//            x_angle= in.x_angle;
//            y_angle = in.y_angle;
//            x = in.x; y=in.y; z=in.z;
//            center = in.center;
            ver = new Vector[total_p];
            for(int i=0;i<total_p;i++)
            {
                ver[i] = in.ver[i];
            }
        }
        ~sphere()
        {
            delete ver;
        }


};

class clouds: public shapes{
public:
    sphere cloud1,cloud2,cloud3;   //cloud = combination of three spheres

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

        cloud1 = sphere(ver[0],10,r,g,b);                   //random values for center and radius
        cloud2 = sphere(ver[0]+Vector(18,0,0),15,r,g,b);
        cloud3 = sphere(ver[0]+Vector(38,0,0),10,r,g,b);
    }
    void Draw(const Matrix w2c, const Matrix projection)
    {
        cloud1.Draw(w2c,projection);
        cloud2.Draw(w2c,projection);
        cloud3.Draw(w2c,projection);
    }

        void _trans(Matrix m)
        {
            cloud1._trans(m);
            cloud2._trans(m);
            cloud3._trans(m);
        }
    ~clouds()
    {
        delete ver;
    }

};
