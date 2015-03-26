
#pragma once
#include "Pipeline.h"
#include <math.h>
#include <vector>
#define ABS(a) ((a<0)? a*-1 : a)

Vector L(150,100,-12);
Vector cam;

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
//            Vector* normal;
//            normal = new Vector[8];
//            Vector* l;
//            l = new Vector[8];
//            normal[0] =
//            normal[0].normalize();
//            normal[1] = ((ver[0]-ver[1]).crossProduct(ver[5]-ver[1]) + (ver[2]-ver[1]).crossProduct(ver[0]-ver[1]) + (ver[5]-ver[1]).crossProduct(ver[2]-ver[1]) )/3;
//            normal[1].normalize();
//            normal[2] = ((ver[1]-ver[2]).crossProduct(ver[6]-ver[2]) + (ver[6]-ver[2]).crossProduct(ver[3]-ver[2]) + (ver[3]-ver[2]).crossProduct(ver[1]-ver[2]) )/3;
//            normal[2].normalize();
//            normal[3] = ((ver[7]-ver[3]).crossProduct(ver[0]-ver[3]) + (ver[0]-ver[3]).crossProduct(ver[2]-ver[3]) + (ver[2]-ver[3]).crossProduct(ver[7]-ver[3]) )/3;
//            normal[3].normalize();
//            normal[4] = ((ver[7]-ver[4]).crossProduct(ver[5]-ver[4]) + (ver[5]-ver[4]).crossProduct(ver[0]-ver[4]) + (ver[0]-ver[4]).crossProduct(ver[7]-ver[4]) )/3;
//            normal[4].normalize();
//            normal[5] = ((ver[4]-ver[5]).crossProduct(ver[6]-ver[5]) + (ver[6]-ver[5]).crossProduct(ver[1]-ver[5]) + (ver[1]-ver[5]).crossProduct(ver[4]-ver[5]) )/3;
//            normal[5].normalize();
//            normal[6] = ((ver[5]-ver[6]).crossProduct(ver[7]-ver[6]) + (ver[2]-ver[6]).crossProduct(ver[5]-ver[6]) + (ver[7]-ver[6]).crossProduct(ver[2]-ver[6]) )/3;
//            normal[6].normalize();
//            normal[7] = ((ver[6]-ver[7]).crossProduct(ver[4]-ver[7]) + (ver[3]-ver[7]).crossProduct(ver[6]-ver[7]) + (ver[4]-ver[7]).crossProduct(ver[3]-ver[7]) )/3;
//            normal[7].normalize();
//
//            for(int j=0;j<8;j++)
//            {
//                l[j] = L-ver[j];
//                l[j].normalize();
//            }
//            for(int j=0;j<8;j++){
//            ver[j].i =(0.5*1 + 0.75* 1 * normal[j].dotProduct(l[j]))/2;
//            //std::cout<<ver[j].i;
//            if (ver[j].i < 0)
//                 ver[j].i = 0;
//            if (ver[j].i > 1)
//                    ver[j].i=1;
//            }

                        for(int j=0;j<8;j++){
            ver[j].i =1; //(0.5*1 + 0.75* 1 * normal[j].dotProduct(l[j]))/2;
            //std::cout<<ver[j].i;
            if (ver[j].i < 0)
                 ver[j].i = 0;
            if (ver[j].i > 1)
                    ver[j].i=1;
            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {

//            CalculateNormalnAssignIntensity();
//            Vertex v[8];
//            for(int j=0;j<8;j++)
//            {
//                v[j] = WorldToPixel(ver[j],w2c,projection);
//                v[j].i = ver[j].i;
//            }
//
//            Triangle T(v[0],v[1],v[2]);
//
////            Line e0(v[0],v[1]);
////            Line e2(v[1],v[2]);
////            Line e3(v[2],v[3]);
////            Line e4(v[3],v[0]);
////            Line e5(v[4],v[5]);
////            Line e6(v[5],v[6]);
////            Line e7(v[6],v[7]);
////            Line e8(v[7],v[4]);
////            Line e9(v[0],v[4]);
////            Line e10(v[1],v[5]);
////            Line e11(v[2],v[6]);
////            Line e12(v[3],v[7]);
//
////            e0.DrawLine(16,0,31);
////            e2.DrawLine(161,0,131);
////            e3.DrawLine(16,0,31);
////            e4.DrawLine(16,0,31);
////            e5.DrawLine(16,0,31);
////            e6.DrawLine(126,0,31);
////            e7.DrawLine(16,0,31);
////            e8.DrawLine(1,0,31);
////            e9.DrawLine(16,110,31);
////            e10.DrawLine(16,0,31);
////            e11.DrawLine(16,140,31);
////            e12.DrawLine(16,1,31);
//
////            DrawTriangle(v[0],v[1],v[2],g_width,g_height,16,0,161);
//
//            Triangle T1(v[0],v[1],v[2]);
//            Triangle T2(v[0],v[3],v[2]);
//            Triangle T3(v[4],v[5],v[6]);
//            Triangle T4(v[4],v[7],v[6]);
//            Triangle T5(v[5],v[1],v[2]);
//            Triangle T6(v[5],v[6],v[2]);
//            Triangle T7(v[4],v[0],v[3]);
//            Triangle T8(v[4],v[7],v[3]);
//            Triangle T9(v[7],v[6],v[2]);
//            Triangle T10(v[7],v[3],v[2]);
//            Triangle T11(v[5],v[0],v[4]);
//            Triangle T12(v[5],v[0],v[1]);
//            T1.fDrawTriangle(r,g,b,L);
//            T2.fDrawTriangle(r,g,b,L);
//            T3.fDrawTriangle(r,g,b,L);
//            T4.fDrawTriangle(r,g,b,L);
//            T5.fDrawTriangle(r,g,b,L);
//            T6.fDrawTriangle(r,g,b,L);
//            T7.fDrawTriangle(r,g,b,L);
//            T8.fDrawTriangle(r,g,b,L);
//            T9.fDrawTriangle(r,g,b,L);
//            T10.fDrawTriangle(r,g,b,L);
//            T11.fDrawTriangle(r,g,b,L);
//            T12.fDrawTriangle(r,g,b,L);
//            fDrawTriangle(ver[0],ver[1],ver[2],ver[3],r,g,b,w2c,projection);
//           // fDrawTriangle(ver[0],ver[3],ver[2],r,g,b,w2c,projection);
//            fDrawTriangle(ver[4],ver[5],ver[6],ver[7],r,g,b,w2c,projection);
//           // fDrawTriangle(ver[4],ver[7],ver[6],r,g,b,w2c,projection);
//            fDrawTriangle(ver[5],ver[1],ver[2],ver[6],r,g,b,w2c,projection);
//            //fDrawTriangle(ver[5],ver[6],ver[2],r,g,b,w2c,projection);
//            fDrawTriangle(ver[4],ver[0],ver[3],ver[7],r,g,b,w2c,projection);
//            //fDrawTriangle(ver[4],ver[7],ver[3],r,g,b,w2c,projection);
//            fDrawTriangle(ver[7],ver[6],ver[2],ver[3],r,g,b,w2c,projection);
//            //fDrawTriangle(ver[7],ver[3],ver[2],r,g,b,w2c,projection);
//            fDrawTriangle(ver[5],ver[4],ver[0],ver[1],r,g,b,w2c,projection);
//           // fDrawTriangle(ver[5],ver[1],ver[0],r,g,b,w2c,projection);
//        }
//
//        void fDrawTriangle(Vector v1, Vector v2, Vector v3,Vector v4, int r,int g, int b,const Matrix w2c, const Matrix projection)
//        {
//            Vector normal;
//            normal = (v2-v3).crossProduct(v1-v3);
//            normal.normalize();
//            Vector centroid = ((v2 +v3)+v1)/3;
//            Vector l = L - centroid;
//            l.normalize();
//            float in = (1+1*normal.dotProduct(l))/2;
//            Vertex v11 = WorldToPixel(v1,w2c,projection);
//            Vertex v22 = WorldToPixel(v2,w2c,projection);
//            Vertex v33 = WorldToPixel(v3,w2c,projection);
//            Vertex v44 = WorldToPixel(v3,w2c,projection);
//            v11.i=in;
//            v22.i=in;
//            v33.i=in;
//            v44.i=in;
//            Triangle T1(v11,v22,v33);
//            Triangle T2(v11,v44,v33);
//            T2.DrawTriangle(r,g,b);
//            T1.DrawTriangle(r,g,b);
//        }
            fDrawTriangle(ver[2],ver[1],ver[0],r,g,b,w2c,projection);
            fDrawTriangle(ver[0],ver[3],ver[2],r,g,b,w2c,projection);
            fDrawTriangle(ver[4],ver[5],ver[6],r,g,b,w2c,projection);
            fDrawTriangle(ver[6],ver[7],ver[4],r,g,b,w2c,projection);
            fDrawTriangle(ver[5],ver[1],ver[2],r,g,b,w2c,projection);
            fDrawTriangle(ver[2],ver[6],ver[5],r,g,b,w2c,projection);
            fDrawTriangle(ver[3],ver[0],ver[4],r,g,b,w2c,projection);
            fDrawTriangle(ver[4],ver[7],ver[3],r,g,b,w2c,projection);
            fDrawTriangle(ver[7],ver[6],ver[2],r,g,b,w2c,projection);
            fDrawTriangle(ver[2],ver[3],ver[7],r,g,b,w2c,projection);
            fDrawTriangle(ver[5],ver[4],ver[0],r,g,b,w2c,projection);
            fDrawTriangle(ver[0],ver[1],ver[5],r,g,b,w2c,projection);
        }

        void fDrawTriangle(Vector v1, Vector v2, Vector v3, int r,int g, int b,const Matrix w2c, const Matrix projection)
        {
            Vector normal;
            normal = (v2-v3).crossProduct(v1-v3);
            normal.normalize();
            Vector centroid = ((v2 +v3)+v1)/3;
            Vector l = L - centroid;
            l.normalize();
            float in = (1+1*normal.dotProduct(l))/2;
            Vertex v11 = WorldToPixel(v1,w2c,projection);
            Vertex v22 = WorldToPixel(v2,w2c,projection);
            Vertex v33 = WorldToPixel(v3,w2c,projection);
            v11.i=in;
            v22.i=in;
            v33.i=in;
            Triangle T1(v11,v22,v33);
            T1.DrawTriangle(r,g,b);
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
            l.normalize();
            ver[2].i = ver[3].i = ver[4].i = (1+1*normal.dotProduct(l))/2;
        }

    void Draw(const Matrix w2c, const Matrix projection)
    {
        CalculateNormalsnAssignIntensity();
        Vertex v[5];
        for(int i=0;i<5;i++)
        {
            v[i] = WorldToPixel(ver[i],w2c, projection);
            v[i].i = ver[i].i;
            if(i==1 || i==5)
                v[i].i = 1;
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
        Vector center;
        int rings, sectors;
        float x,y,z;
      //  unsigned short* indices;
        std::vector<unsigned short> indices;
    public:

        sphere()
        {
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];
        }

        sphere(Vector c, float rad,  int r, int g,int b)
        {
            this->r=r;
            this->g=g;
            this->b=b;
            center=c;
            radius=rad;
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];

            float R = 1.0f / float(rings-1);
            float S = 1.0f / float(sectors-1);

            int i=0;
            for (int r=0; r<rings; ++r)
                for (int s=0; s<sectors; ++s)
                {
#define PI (3.14159265359f)
#define PI_2 (1.57079632679f)
                    float y = -sinf(-PI_2 + PI * r * R);
                    float x = cosf(2 * PI * s * S) * sinf(PI * r * R);
                    float z = sinf(2 * PI * s * S) * sinf(PI * r * R);

                    ver[i] = Vector(x*radius+ center.x,y*radius+ center.y,z*radius+center.z);
//
//                    m_vertices[i].normal.x = x;
//                    m_vertices[i].normal.y = y;
//                    m_vertices[i].normal.z = z;
                    ++i;
                }
            indices.resize((rings-1)*(sectors-1)*6);
            auto id = &indices[0];
            for (int r=0; r<rings-1; ++r)
            for (int s=0; s<sectors-1; ++s)
            {
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t(r*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s);
            }
        }

        //void calculateIntensity(Vector Camera)
        void calculateIntensity()
        {
            for(int j=0;j<rings*sectors;j++)
            {
                Vector   l = (L - ver[j]);
                Vector v = cam- ver[j];
                v.normalize();
               // Vector H;
               // H = (l + v);
               // float a = H.magnitude();
                //H = (l+v)/a;
                l.normalize();
                Vector n = (ver[j]-center);
                n.normalize();
                Vector r = n* 2* (n.dotProduct(l)) - l;
                ver[j].i = (1+1*l.dotProduct(n) + 1*1* pow(v.dotProduct(r),1) /*-n.dotProduct(H))/3;*/)/3;
                if (ver[j].i < 0)
                 ver[j].i = 0;
                if (ver[j].i > 1)
                    ver[j].i=1;
                ver[j].i+=0.5;

            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {
            //calculateIntensity(Vector(0,50,-100));
            calculateIntensity();
            Vertex v[rings*sectors];
            for(int j=0;j<rings*sectors;j++)
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
            for(unsigned int j=0; j<indices.size();j+=3)
            {
                Triangle T(v[indices[j]],v[indices[j+1]],v[indices[j+2]]);
                T.DrawTriangle(r,g,b);
            }
        }
        void _trans(Matrix m)
        {
            for(int i=0;i<rings*sectors;i++)
            {
                Transform(m,ver[i]);
            }
        }
        void operator=(const sphere& in)
        {
            r= in.r;
            g= in.g;
            b = in.b;
            rings = in.rings;
            rings = in.sectors;
            indices = in.indices;
            ver = new Vector[rings*sectors];
            for(int i=0;i<rings*sectors;i++)
            {
                ver[i] = in.ver[i];
            }
        }
        ~sphere()
        {
            delete ver;
            //delete indices;
        }


};

class Csphere: public shapes{
    private:
        float radius;
        Vector center;
        int rings, sectors;
        float x,y,z;
      //  unsigned short* indices;
        std::vector<unsigned short> indices;
    public:

        Csphere()
        {
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];
        }

        Csphere(Vector c, float rad,  int r, int g,int b)
        {
            this->r=r;
            this->g=g;
            this->b=b;
            center=c;
            radius=rad;
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];

            float R = 1.0f / float(rings-1);
            float S = 1.0f / float(sectors-1);

            int i=0;
            for (int r=0; r<rings; ++r)
                for (int s=0; s<sectors; ++s)
                {
#define PI (3.14159265359f)
#define PI_2 (1.57079632679f)
                    float y = -sinf(-PI_2 + PI * r * R);
                    float x = cosf(2 * PI * s * S) * sinf(PI * r * R);
                    float z = sinf(2 * PI * s * S) * sinf(PI * r * R);

                    ver[i] = Vector(x*radius+ center.x,y*radius+ center.y,z*radius+center.z);
//
//                    m_vertices[i].normal.x = x;
//                    m_vertices[i].normal.y = y;
//                    m_vertices[i].normal.z = z;
                    ++i;
                }
            indices.resize((rings-1)*(sectors-1)*6);
            auto id = &indices[0];
            for (int r=0; r<rings-1; ++r)
            for (int s=0; s<sectors-1; ++s)
            {
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t(r*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s);
            }
        }

        //void calculateIntensity(Vector Camera)
        void calculateIntensity()
        {
            for(int j=0;j<rings*sectors;j++)
            {
               ver[j].i = 0.95;

            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {
            //calculateIntensity(Vector(0,50,-100));
            calculateIntensity();
            Vertex v[rings*sectors];
            for(int j=0;j<rings*sectors;j++)
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
            for(unsigned int j=0; j<indices.size();j+=3)
            {
                Triangle T(v[indices[j]],v[indices[j+1]],v[indices[j+2]]);
                T.DrawTriangle(r,g,b);
            }
        }
        void _trans(Matrix m)
        {
            for(int i=0;i<rings*sectors;i++)
            {
                Transform(m,ver[i]);
            }
        }
        void operator=(const Csphere& in)
        {
            r= in.r;
            g= in.g;
            b = in.b;
            rings = in.rings;
            rings = in.sectors;
            indices = in.indices;
            ver = new Vector[rings*sectors];
            for(int i=0;i<rings*sectors;i++)
            {
                ver[i] = in.ver[i];
            }
        }
        ~Csphere()
        {
            delete ver;
            //delete indices;
        }


};

class hemisphere: public shapes{
    private:
        float radius;
        Vector center;
        int rings, sectors;
        float x,y,z;
      //  unsigned short* indices;
        std::vector<unsigned short> indices;
    public:

        hemisphere()
        {
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];
        }

        hemisphere(Vector c, float rad,  int r, int g,int b)
        {
            this->r=r;
            this->g=g;
            this->b=b;
            center=c;
            radius=rad;
            rings = 32;
            sectors = 32;
            ver = new Vector[rings*sectors];

            float R = 1.0f / float(rings-1);
            float S = 1.0f / float(sectors-1);

            int i=0;
            for (int r=0; r<rings/2; ++r)
                for (int s=0; s<sectors; ++s)
                {
#define PI (3.14159265359f)
#define PI_2 (1.57079632679f)
                    float y = -sinf(-PI_2 + PI * r * R);
                    float x = cosf(2 * PI * s * S) * sinf(PI * r * R);
                    float z = sinf(2 * PI * s * S) * sinf(PI * r * R);

                    ver[i] = Vector(x*radius+ center.x,y*radius+ center.y,z*radius+center.z);
//
//                    m_vertices[i].normal.x = x;
//                    m_vertices[i].normal.y = y;
//                    m_vertices[i].normal.z = z;
                    ++i;
                }
            indices.resize((rings-1)*(sectors-1)*6);
            auto id = &indices[0];
            for (int r=0; r<(rings-1)/2; ++r)
            for (int s=0; s<sectors-1; ++s)
            {
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t(r*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t(r*sectors + s);
                *id++ = uint16_t((r+1)*sectors + s+1);
                *id++ = uint16_t((r+1)*sectors + s);
            }
        }

        //void calculateIntensity(Vector Camera)
        void calculateIntensity()
        {
            for(int j=0;j<rings*sectors;j++)
            {
                Vector   l = (L - ver[j]);
                Vector v = cam- ver[j];
                v.normalize();
               // Vector H;
               // H = (l + v);
               // float a = H.magnitude();
                //H = (l+v)/a;
                l.normalize();
                Vector n = (ver[j]-center);
                n.normalize();
                Vector r = n* 2* (n.dotProduct(l)) - l;
                ver[j].i = (1+1*l.dotProduct(n) + 1*1* pow(v.dotProduct(r),1) /*-n.dotProduct(H))/3;*/)/3;
                if (ver[j].i < 0)
                 ver[j].i = 0;
                if (ver[j].i > 1)
                    ver[j].i=1;
                ver[j].i+=0.5;

            }
        }

        void Draw(const Matrix w2c, const Matrix projection)
        {
            //calculateIntensity(Vector(0,50,-100));
            calculateIntensity();
            Vertex v[rings*sectors];
            for(int j=0;j<rings*sectors;j++)
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
            for(unsigned int j=0; j<indices.size();j+=3)
            {
                Triangle T(v[indices[j]],v[indices[j+1]],v[indices[j+2]]);
                T.DrawTriangle(r,g,b);
            }
        }
        void _trans(Matrix m)
        {
            for(int i=0;i<rings*sectors;i++)
            {
                Transform(m,ver[i]);
            }
        }
        void operator=(const hemisphere& in)
        {
            r= in.r;
            g= in.g;
            b = in.b;
            rings = in.rings;
            rings = in.sectors;
            indices = in.indices;
            ver = new Vector[rings*sectors];
            for(int i=0;i<rings/2*sectors;i++)
            {
                ver[i] = in.ver[i];
            }
        }
        ~hemisphere()
        {
            delete ver;
            //delete indices;
        }


};

class clouds: public shapes{
public:
    Csphere cloud1,cloud2,cloud3;   //cloud = combination of three spheres

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

        cloud1 = Csphere(ver[0],10,r,g,b);                   //random values for center and radius
        cloud2 = Csphere(ver[0]+Vector(18,0,0),15,r,g,b);
        cloud3 = Csphere(ver[0]+Vector(38,0,0),10,r,g,b);
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
