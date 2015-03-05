
#pragma once

class shapes{
    protected:
        Vector* ver;
    public:
        void Draw()
        {

        }
};
class cube: public shapes{
    public:
        cube(Vector v, int l, int b, int h)
        {
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
            T1.DrawTriangle(1,2,3);
            T2.DrawTriangle(1,2,3);
            T3.DrawTriangle(205,	193,	197);
            T4.DrawTriangle(205,	193,	197);
            T5.DrawTriangle(43,132,123);
            T6.DrawTriangle(43,132,123);
//            T7.DrawTriangle(18,232,123);
//            T8.DrawTriangle(18,232,123);
            T9.DrawTriangle(43,132,123);
            T10.DrawTriangle(43,132,123);
            T11.DrawTriangle(18,232,123);
            T12.DrawTriangle(18,232,123);
        }
        ~cube()
        {
            delete ver;
        }
};

class pyramid : public shapes{
    public:
        pyramid(Vector v, int h, int w)
        {
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
            T1.DrawTriangle(232,223,1);
            T2.DrawTriangle(232,223,1);
            T3.DrawTriangle(18,232,123);
            T4.DrawTriangle(18,232,123);
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
    flag(Vector v1,Vector v2,Vector v3,Vector v4,Vector v5)
    {
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

        e0.DrawLine(16,0,31);
        e1.DrawLine(161,0,131);
        e2.DrawLine(16,0,31);
//
//      DrawTriangle(v[0],v[1],v[2],g_width,g_height,16,0,161,zBuffer);
    }
    ~flag()
        {
            delete ver;
        }

};

