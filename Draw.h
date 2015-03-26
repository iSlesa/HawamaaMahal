#pragma once
//#include "Pipeline.h"
#include "Vector.h"
#include <algorithm>
#include <iostream>
#define ROUND(a) ((int) (a+0.5))

// framebuffer is array of pixels
unsigned int* g_framebuffer;
// size of window
int g_width, g_height;
float* zBuffer;
using namespace std;
// Here r,g,b values can range from 0-255 (00H-FFH)
class Vertex;
Vertex WorldToPixel(const Vector World, Matrix w2c , Matrix projection);


class Vertex{
    public:
        int x;
        int y;
        float z; //for depth value
        float i;  //for intensity 0<=i<=1
        Vertex():x(0),y(0),z(0),i(0){}
        //Vertex(Vec2& v):x(v.x),y(v.y){}
        Vertex(int xx,int yy):x(xx),y(yy){
            z=0;
            i=0;
        }
        Vertex(int xx,int yy,float zz):x(xx),y(yy),z(zz){
            i=0;
        }
        Vertex(int xx,int yy,float zz,float ii):x(xx),y(yy),z(zz){
            i=ii;
        }
        Vertex operator = (const Vertex& in){
                x = in.x;
                y = in.y;
                z = in.z;
                i = in.i;
                return Vertex(x,y,z,i);
            }

};

void PutPixel(Vertex v, unsigned char r, unsigned char g, unsigned char b)
{
    if (v.y > g_height || v.x > g_width || v.x < 0 || v.y < 0) return;
   // if (v.i ==0) return;      //Remove from comment
//    v.y=140+v.y;
//    v.x=250+v.x;
    // color plus intensity
    float red = (int)r *v.i ; float green= (int)g *v.i; float blue=(int)b *v.i;   //Remove from comment
   // std::cout<<red<<","<<green<<","<<blue<<endl;
    //std::cout<<v.i<<endl;

    unsigned char a = 255;
    r= red;
    g=green;
    b=blue;

    // Create the color for given rgb values: the format for integer in hex is aarrggbb
    // e.g. for white all r,g,b are FFH: FFFFFFFF
    //      for black, all are 00H:  FF000000
    unsigned int color = (a << 24) | (r << 16) | (g << 8) | b;
    // Fill at the required pixel
    g_framebuffer[v.y*g_width + v.x] = color;
}

class Line{
    public:
        Vertex v1;
        Vertex v2;
        Line():v1(),v2(){
            v1.x=0;
            v1.y=0;
            v2.x=0;
            v2.y=0;
        }
        Line(int x1,int y1,int x2,int y2):v1(),v2(){
            v1.x=x1;
            v1.y=y1;
            v2.x=x2;
            v2.y=y2;
        }
        Line(Vertex AA,Vertex BB):v1(AA),v2(BB){}

        void DrawLine(int r,int g,int b){

        int x1 = v1.x; int y1 = v1.y;
        int x2 = v2.x; int y2 = v2.y;
        float dStart = v1.z, dEnd = v2.z;// Starting depth value, and ending depth values
        float dVal = dStart, delta_d = dStart - dEnd; // The depth value of that point, and the difference delta_d
        int delta_x(x2 - x1);
        // if x1 == x2, then it does not matter what we set here
        signed char const ix((delta_x > 0) - (delta_x < 0));
        delta_x = abs(delta_x) << 1;

        int delta_y(y2 - y1);
        // if y1 == y2, then it does not matter what we set here
        signed char const iy((delta_y > 0) - (delta_y < 0));
        delta_y = abs(delta_y) << 1;
        Vertex P(x1,y1,dVal);
        PutPixel(P,r,g,b);

        if (delta_x >= delta_y)
        {
            // error may go below zero
            int error(delta_y - (delta_x >> 1));
            float id = delta_d / (float) delta_x;
            while (x1 != x2)
            {
                if ((error >= 0) && (error || (ix > 0)))
                {
                    error -= delta_x;
                    y1 += iy;
                }
                // else do nothing

                error += delta_y;
                x1 += ix;
                dVal += id;
                Vertex P(x1,y1,dVal);
                PutPixel(P,r,g,b);
            }
        }
        else
        {
            // error may go below zero
            int error(delta_x - (delta_y >> 1));
            float id = delta_d / (float) delta_y;
            while (y1 != y2)
            {
                if ((error >= 0) && (error || (iy > 0)))
                {
                    error -= delta_y;
                    x1 += ix;
                }
                // else do nothing

                error += delta_x;
                y1 += iy;
                dVal += id;
                Vertex P(x1,y1,dVal);
                PutPixel(P,r,g,b);
            }
        }
        }
};
class Triangle{
   public:
       Vertex v1;
       Vertex v2;
       Vertex v3;
       Triangle():v1(),v2(),v3(){
            v1.x=0;
            v1.y=0;
            v1.z=0;
            v2.x=0;
            v2.y=0;
            v2.z=0;
            v3.x=0;
            v3.y=0;
            v3.z=0;
            v1.i=0;
            v2.i=0;
            v3.i=0;
        }
        Triangle(int x1,int y1,int x2,int y2,int x3,int y3):v1(),v2(),v3(){
            v1.x=x1;
            v1.y=y1;
            v2.x=x2;
            v2.y=y2;
            v3.x=x3;
            v3.y=y3;
        }

        //yo wala funtion matra use vachha
        Triangle(Vertex AA,Vertex BB,Vertex CC):v1(AA),v2(BB),v3(CC){}


// interpolation function for interpolation of depth and intensity
        void Interpolate(Vertex* e1, Vertex* e2, int r,int g ,int b)
		{

			// function receives flat top or flat bottom triangle
			// make sure that e1 is left edge
			if(e1[0].x > e2[0].x or e1[1].x > e2[1].x) // if e1 is on right, swap the edges
            {

            //swap gareko
                int temp1x= e1[0].x;
                int temp1y= e1[0].y;
                float temp1z= e1[0].z;
                float temp1i= e1[0].i;
                int temp2x= e1[1].x;
                int temp2y= e1[1].y;
                float temp2z= e1[1].z;
                float temp2i= e1[1].i;

              e1[0].x  = e2[0].x;
              e1[0].y  = e2[0].y;
              e1[0].z  = e2[0].z;
              e1[0].i  = e2[0].i;
              e1[1].x  = e2[1].x;
              e1[1].y  = e2[1].y;
              e1[1].z  = e2[1].z;
              e1[1].i  = e2[1].i;

            e2[0].x=temp1x;
            e2[0].y=temp1y;
            e2[0].z=temp1z;
            e2[0].i=temp1i;
            e2[1].x=temp2x;
            e2[1].y=temp2y;
            e2[1].z=temp2z;
            e2[1].i=temp2i;
            }

			int l1x0 = e1[0].x, l1x1 = e1[1].x;
			int l2x0 = e2[0].x, l2x1 = e2[1].x;
			int l1y0 = e1[0].y, l1y1 = e1[1].y;
//			int l2y0 = e2[0].y, l2y1 = e2[1].y;

			int dx1 = l1x0 - l1x1;
			int dx2 = l2x0 - l2x1;

			int dy = l1y0 - l1y1; // dy is same for both lines

			// inverse slopes
			float inv_m1 = float(dx1)/dy;
			float inv_m2 = float(dx2)/dy;
//
//			// attributes i.e. intensity
            float attr1, attr2, attr, dAttr1, dAttr2;
            attr1 = e1[0].i;
            attr2 = e2[0].i;
//
//			// values of attribute to be increased at each scan line
			dAttr1 = (e1[0].i - e1[1].i)/dy;
			dAttr2 = (e2[0].i - e2[1].i)/dy;

			// depths and values to be increased at each scan line
			float depth1, depth2, depth, dDepth1, dDepth2;
			dDepth1 = (e1[0].z - e1[1].z)/dy;
			dDepth2 = (e2[0].z - e2[1].z)/dy;
			depth1 = e1[0].z;
			depth2 = e2[0].z;

			int y = l1y0;
			float x1 = l1x0, x2 = l2x0;

			int clippedx1, clippedx2;
			// begin loop
			while( y >= l1y1) // both edges have lower y value same, so no matter we take l1y1 or l2y1
			{
				if(y < 0) break; // as we move from top to bottom

				if(!(x2 < 0 or x1 > g_width or y > g_height)) // scan line is not outside the screen
				{

					clippedx1 = max(ROUND(x1), 0); // clipped x1 value
					clippedx2 = min(ROUND(x2), g_width); // clipped x2 value

					int dx = ROUND(x2)-ROUND(x1);

					attr = attr1;
					depth = depth1;

					if (clippedx1 != ROUND(x1)) // means x-clipping has occured and thus attribute at clipped value is different than attr1
					{
						attr = attr1+(attr2-attr1)*(clippedx1-ROUND(x1))/dx;
						depth = depth1+(depth2-depth1)*(clippedx1-ROUND(x1))/dx;
					}
					// plot the first Vertex
					if( depth < zBuffer[y*g_width + clippedx1] and depth > -1)
						{
							Vertex p(clippedx1, y);
							p.i = attr;
							zBuffer[y*g_width + clippedx1] = depth;
							PutPixel(p,r,g,b);

						}
					// plot other Vertices
					for(int x=clippedx1+1;x<=clippedx2;x++)
					{

						attr+= (attr2-attr1)/dx;
						depth+= (depth2-depth1)/dx;
						if( depth < zBuffer[y*g_width + x] and depth >= -1)
						{
							Vertex p(x, y);
							p.i = attr;
							zBuffer[y*g_width+x] = depth;
							PutPixel(p,r,g,b);

						}

				}

			}
			attr1 -= dAttr1;
			attr2 -= dAttr2;
			depth1 -= dDepth1;
			depth2 -= dDepth2;

			x1-=inv_m1;
			x2-=inv_m2;

			y--;
		}
	}
void DrawTriangle(int r,int g,int b)
{
    Vertex p1=v1, p2=v2, p3=v3;
    Vertex one, two, three;
    // sorted from top to bottom
    if(max(max(p1.y,p2.y),p3.y) == p1.y){
        one = p1;
        if(max(p2.y,p3.y) == p2.y){
            two = p2;
            three = p3;
        }
        else if(max(p2.y,p3.y) == p3.y){
            two = p3;
            three = p2;
        }
        }
    else if(max(max(p1.y,p2.y),p3.y) == p2.y){
        one = p2;
        if(max(p1.y,p3.y) == p1.y){
            two = p1;
            three = p3;
        }
        else if(max(p1.y,p3.y) == p3.y){
            two = p3;
            three = p1;
        }
        }
    else if(max(max(p1.y,p2.y),p3.y) == p3.y){
        one = p3;
        if(max(p1.y,p2.y) == p1.y){
            two = p1;
            three = p2;
        }
        else if(max(p1.y,p2.y) == p2.y){
            two = p2;
            three = p1;
        }
        }
    p1 = one, p2=two, p3=three;

    if(p1.y == p2.y)  // the two upper Vertexs are at same y level
			{
				//std::cout << "upper base";
				// make two edges, (p1,p3) and (p2,p3)
				Vertex e1[] = {p1,p3};
				Vertex e2[] = {p2,p3};
				Interpolate(e1,e2,r,g,b);
			}
    else if (p2.y == p3.y) // the two lower Vertexs are at same y level
			{

				//std::cout << "lower base";
				Vertex e1[] = {p1, p2};
				Vertex e2[] = {p1, p3};
				Interpolate(e1,e2,r,g,b);
			}
			else // all the vertices are at different y level
			{
				// find a Vertex with interpolated depth and attributes in edge (p1, p3)
				int dy = p3.y - p1.y;
				float inv_m = (p3.x-p1.x)/float(dy);
				int x = p1.x + inv_m*(p2.y-p1.y)+0.5;
				// interpolated values
				float depth = p1.z + (p3.z-p1.z)*(p2.y-p1.y)/dy;
				float attribute = p1.i + (p3.i-p1.i)*(p2.y-p1.y)/dy;
				Vertex p(x, p2.y,depth);
				// assign attribute
				p.i = attribute;
				// now form two pairs of edges and send to interpolate each
				Vertex e1[] = {p1,p2};
				Vertex e2[] = {p1, p};
				Interpolate(e1, e2,r,g,b);
				// reassign other Vertices to the edges
				e1[0] = p; e1[1] = p3;
				e2[0] = p2; e2[1] = p3;

				Interpolate(e1, e2,r,g,b);
			}

}

};

// Clear all pixels with skyblue color (for background) and reset the zbuffer
void Clear(){
    delete[] zBuffer;
    zBuffer = new float [g_width*g_height];
    for (int i = 0; i < g_width; ++i){
        for (int j = 0; j < g_height; ++j){
            if (j > g_height || i > g_width || i<0 || j<0) return;

    unsigned char c = 255;
    //int r=255, g=255, b=255;
     int r=176, g=226,	b=255;  //for blue color
    unsigned int color = (c << 24) | (r << 16) | (g << 8) | b;

    g_framebuffer[j*g_width + i] = color;
    zBuffer[g_height*i +j] =999999;
        }
    }
}
