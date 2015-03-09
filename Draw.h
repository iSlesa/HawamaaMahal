#pragma once
#include "Pipeline.h"
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

class Vertex{
    public:
        int x;
        int y;
        float z; //for depth value
        Vertex():x(0),y(0),z(0){}
        //Vertex(Vec2& v):x(v.x),y(v.y){}
        Vertex(int xx,int yy):x(xx),y(yy){
            z=0;
        }
        Vertex(int xx,int yy,int zz):x(xx),y(yy),z(zz){
        }
        void increase_x(int x_inc){
            x=x+x_inc;
        }
        void increase_y(int y_inc){
            y=y+y_inc;
        }
        void set_x(int a){
            x=a;
        }
        void set_y(int b){
            y=b;
        }
        void operator = (const Vertex& in){
                x = in.x;
                y = in.y;
                z = in.z;
            }

};

void PutPixel(Vertex v, unsigned char r, unsigned char g, unsigned char b)
{
    if (v.y > g_height || v.x > g_width || v.x<0 || v.y<0) return;
    //v.y=140+v.y;
    //v.x=250+v.x;
    unsigned char a = 255;
    // Create the color for given rgb values: the format for integer in hex is aarrggbb
    // e.g. for white all r,g,b are FFH: FFFFFFFF
    //      for balck, all are 00H:  FF000000
    unsigned int color = (a << 24) | (r << 16) | (g << 8) | b;
    // Fill at the required pixel
//    if (v.z > zBuffer[g_height*v.x + v.y])
//        return;
//    else
//        zBuffer[g_height*v.x + v.y] = v.z;
    g_framebuffer[v.y*g_width + v.x] = color;
}

//void zBufferRst()
//    {
//            delete[] zBuffer;
//            zBuffer = new float [g_width*g_height];
//    }

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
//            int x1=v1.x;
//            int x2=v2.x;
//            int y1=v1.y;
//            int y2=v2.y;
//            int dx=abs(x2-x1);
//   	        int dy=abs(y2-y1);
//   	        int x_inc=1;
//   	        int y_inc=1;
//   	        if((x2-x1)!=0){
//   	    	    x_inc=(x2-x1)/dx;
//   	        }
//   	        if((y2-y1)!=0){
//   		        y_inc=(y2-y1)/dy;
//   	        }
//   	        Vertex P(x1,y1);
//   	        PutPixel(P,r,g,b);
//   	        if(dx<dy){
//   		        int p=2*dx-dy;
//   		        int k=0;
//   		        while(k!=dy){
//   			        if(p<0){
//   				        P.increase_y(y_inc);
//   				        p=p+2*dx;
//   			        }
//   			        else{
//   				        P.increase_x(x_inc);
//                        P.increase_y(y_inc);
//   				        p=p+2*dx-2*dy;
//   			        }
//   			        k++;
//   			        PutPixel(P,r,g,b);
//   		        }
//   	        }
//   	        else{
//   		        int p=2*dy-dx;
//   		        int k=0;
//   		        while(k!=dx){
//   			        if(p<0){
//   				        P.increase_x(x_inc);
//   				        p=p+2*dy;
//   			        }
//   			        else{
//   				        P.increase_x(x_inc);
//   				        P.increase_y(y_inc);
//   				        p=p+2*dy-2*dx;
//   			        }
//   			        k++;
//   			        PutPixel(P,r,g,b);
//   		        }
//   	        }
    int x1 = v1.x; int y1 = v1.y;
    int x2 = v2.x; int y2 = v2.y;
    float dStart = v1.z, dEnd = v2.z;// Starting depth value, and ending depth values
    float dVal = dStart, delta_d = dStart - dEnd; // The depth value of that point, and the difference delta_d

//
//    if (x1 <= 0) x1 = 1;
//    if (x1 >= screen->w) x1 = screen->w -1;
//    if (y1 <= 0) y1 = 1;
//    if (y1 >= screen->h) y1 = screen->h -1;
//
//    if (x2 <= 0) x2 = 1;
//    if (x2 >= screen->w) x2 = screen->w -1 ;
//    if (y2 <= 0) y2 = 1;
//    if (y2 >= screen->h) y2 = screen->h -1;


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
        }
        Triangle(int x1,int y1,int x2,int y2,int x3,int y3):v1(),v2(),v3(){
            v1.x=x1;
            v1.y=y1;
            v2.x=x2;
            v2.y=y2;
            v3.x=x3;
            v3.y=y3;
        }
        Triangle(Vertex AA,Vertex BB,Vertex CC):v1(AA),v2(BB),v3(CC){}

        void Interpolate(Vertex* e1, Vertex* e2, int r,int g ,int b)
		{

			// function receives flat top or flat bottom triangle
			// make sure that e1 is left edge
			if(e1[0].x > e2[0].x or e1[1].x > e2[1].x) // if e1 is on right, swap the edges
            {
                int temp1x= e1[0].x;
                int temp1y= e1[0].y;
                float temp1z= e1[0].z;
                int temp2x= e1[1].x;
                int temp2y= e1[1].y;
                float temp2z= e1[1].z;

              e1[0].x  = e2[0].x;
              e1[0].y  = e2[0].y;
              e1[0].z  = e2[0].z;
              e1[1].x  = e2[1].x;
              e1[1].y  = e2[1].y;
              e1[1].z  = e2[1].z;

            e2[0].x=temp1x;
            e2[0].y=temp1y;
            e2[0].z=temp1z;
            e2[1].x=temp2x;
            e2[1].y=temp2y;
            e2[1].z=temp2z;





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
//			// attributes
//			Vec3 attr1, attr2, attr, dAttr1, dAttr2;
//			attr1 = e1[0].attributes[0];
//			attr2 = e2[0].attributes[0];
//
//			// values of attribute to be increased at each scan line
//			dAttr1 = (e1[0].attributes[0] - e1[1].attributes[0])/dy;
//			dAttr2 = (e2[0].attributes[0] - e2[1].attributes[0])/dy;

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

					//attr = attr1;
					depth = depth1;

					if (clippedx1 != ROUND(x1)) // means x-clipping has occured and thus attribute at clipped value is different than attr1
					{
						//attr = attr1+(attr2-attr1)*(clippedx1-ROUND(x1))/dx;
						depth = depth1+(depth2-depth1)*(clippedx1-ROUND(x1))/dx;
					}
					// plot the first Vertex
					if( depth < zBuffer[y*g_width + clippedx1] and depth > -1)
						{
							Vertex p(clippedx1, y);
							//p.attributes[0] = attr;
							zBuffer[y*g_width + clippedx1] = depth;
							PutPixel(p,r,g,b);

						}
					// plot other Vertexs
					for(int x=clippedx1+1;x<=clippedx2;x++)
					{

						//attr+= (attr2-attr1)/dx;
						depth+= (depth2-depth1)/dx;
						if( depth < zBuffer[y*g_width + x] and depth >= -1)
						{
							Vertex p(x, y);
							//p.attributes[0] = attr;
							zBuffer[y*g_width+x] = depth;
							PutPixel(p,r,g,b);

						}

				}

			}
			//attr1 -= dAttr1;
			//attr2 -= dAttr2;
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
				//int x = p1.x + (p2.y-p1.y)*inv_m;
				//std::cout << "x : " << x<<std::endl;
				// interpolated values
				float depth = p1.z + (p3.z-p1.z)*(p2.y-p1.y)/dy;
				//Vector attribute = p1.attributes[0] + (p3.attributes[0]-p1.attributes[0])*(p2.y-p1.y)/dy;
				//Vector attrNormal = p1.attributes[1] + (p3.attributes[1]-p1.attributes[1]) * (p2.y-p1.y)/dy;
				//attrNormal.NormalizeToUnit();
				// new Vertex
				Vertex p(x, p2.y,depth);
				// assign attributes and depth
				//p.depth = depth;
				//p.attributes[0] = attribute;
				//p.attributes[1] = attrNormal;

				// now form two pairs of edges and send to interpolate each
				Vertex e1[] = {p1,p2};
				Vertex e2[] = {p1, p};
				Interpolate(e1, e2,r,g,b);
				// reassign other Vertexs to the edges
				e1[0] = p; e1[1] = p3;
				e2[0] = p2; e2[1] = p3;

				Interpolate(e1, e2,r,g,b);
			}

}

 //       void DrawTriangle(int r,int g,int b){
//            int x1=v1.x;
//            int x2=v2.x;
//            int x3=v3.x;
//            int y1=v1.y;
//            int y2=v2.y;
//            int y3=v3.y;
//            int y[]={y1,y2,y3};
//            int x[]={x1,x2,x3};
//            for(int j=0;j<2;j++){
//                for(int k=j+1;k<3;k++)
//                    if(y[j]>y[k]){
//                        int temp=y[j];
//                        y[j]=y[k];
//                        y[k]=temp;
//                        temp=x[j];
//                        x[j]=x[k];
//                        x[k]=temp;
//                    }
//            }
//            int y_top=y[2];
//            int y_mid=y[1];
//            int y_bottom=y[0];
//
//            //From Top to Mid
//
//            Vertex start(x[2],y_top);
//            Vertex end(x[2],y_top);
//
//            //For Start Edge
//            int dxs=abs(x[1]-x[2]);
//            int dys=abs(y[1]-y[2]);
//            int xs_inc=1;
//            if((x[1]-x[2]!=0)){
//                xs_inc=(x[1]-x[2])/dxs;
//            }
//
//            int ps1=2*dxs-dys;
//            int ps2=2*dys-dxs;
//
//            //For End Edge
//            int dxe=abs(x[0]-x[2]);
//            int dye=abs(y[0]-y[2]);
//            int xe_inc=1;
//            if((x[0]-x[2]!=0)){
//                xe_inc=(x[0]-x[2])/dxe;
//            }
//
//            int pe1=2*dxe-dye;
//            int pe2=2*dye-dxe;
//
//            int ks=0;
//            int ke=0;
//
//            Line ScanLine(start,end);
//
//            if(y_top!=y_mid){
//            for(int y=y_top;y>=y_mid;y--){
//                ScanLine.v1.set_y(y);
//                ScanLine.v2.set_y(y);
//                ScanLine.DrawLine(r,g,b);
//                //for Start Edge
//                {
//                    if(dxs<dys){
//                        if(ps1<0){
//                            ps1=ps1+2*dxs;
//                        }
//                        else{
//                            ScanLine.v1.increase_x(xs_inc);
//                            ps1=ps1+2*dxs-2*dys;
//                        }
//                }
//                    else{
//                        while(ks!=dxs){
//                            if(ps2<0){
//                                ScanLine.v1.increase_x(xs_inc);
//                                ps2=ps2+2*dys;
//                            }
//                            else{
//                                ps2+=2*dys-2*dxs;
//                                ScanLine.v1.increase_x(xs_inc);
//                                break;
//                            }
//                        }
//                    }
//                }
//                //for End Edge
//                {
//                    if(dxe<dye){
//                        if(pe1<0){
//                            pe1=pe1+2*dxe;
//                        }
//                        else{
//                            ScanLine.v2.increase_x(xe_inc);
//                            pe1=pe1+2*dxe-2*dye;
//                        }
//                    }
//                    else{
//                        while(ke!=dxe){
//                            if(pe2<0){
//                                ScanLine.v2.increase_x(xe_inc);
//                                pe2=pe2+2*dye;
//                            }
//                            else{
//                                pe2+=2*dye-2*dxe;
//                                ScanLine.v2.increase_x(xe_inc);
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//            }
//        ///////////////////////////////////
//            //From Bottom to Mid
//
//            start.set_x(x[0]);
//            end.set_x(x[0]);
//
//            Line Scanline2(start,end);
//
//            //For Start Edge
//            dxs=abs(x[1]-x[0]);
//            dys=abs(y[1]-y[0]);
//            xs_inc=1;
//            if((x[1]-x[0]!=0)){
//                xs_inc=(x[1]-x[0])/dxs;
//            }
//
//            ps1=2*dxs-dys;
//            ps2=2*dys-dxs;
//
//            //For End Edge
//            dxe=abs(x[2]-x[0]);
//            dye=abs(y[2]-y[0]);
//            xe_inc=1;
//            if((x[2]-x[0]!=0)){
//                xe_inc=(x[2]-x[0])/dxe;
//            }
//
//            pe1=2*dxe-dye;
//            pe2=2*dye-dxe;
//
//            ks=0;
//            ke=0;
//            if(y_bottom!=y_mid){
//            for(int y=y_bottom;y<=y_mid;y++){
//                Scanline2.v1.set_y(y);
//                Scanline2.v2.set_y(y);
//                Scanline2.DrawLine(r,g,b);
//                //for Start Edge
//                {
//                    if(dxs<dys){
//                        if(ps1<0){
//                            ps1=ps1+2*dxs;
//                        }
//                        else{
//                            Scanline2.v1.increase_x(xs_inc);
//                            ps1=ps1+2*dxs-2*dys;
//                        }
//                    }
//                    else{
//                        while(ks!=dxs){
//                            if(ps2<0){
//                                Scanline2.v1.increase_x(xs_inc);
//                                ps2=ps2+2*dys;
//                            }
//                            else{
//                                ps2+=2*dys-2*dxs;
//                                Scanline2.v1.increase_x(xs_inc);
//                                break;
//                            }
//                        }
//                    }
//                }
//                //for End Edge
//                {
//                    if(dxe<dye){
//                        if(pe1<0){
//                            pe1=pe1+2*dxe;
//                        }
//                        else{
//                            Scanline2.v2.increase_x(xe_inc);
//                            pe1=pe1+2*dxe-2*dye;
//                        }
//                    }
//                    else{
//                        while(ke!=dxe){
//                            if(pe2<0){
//                                Scanline2.v2.increase_x(xe_inc);
//                                pe2=pe2+2*dye;
//                            }
//                            else{
//                                pe2+=2*dye-2*dxe;
//                                Scanline2.v2.increase_x(xe_inc);
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//            }
        ///////////////////////////////////



};

// Clear all pixels with white color
void Clear(){
    delete[] zBuffer;
    zBuffer = new float [g_width*g_height];
    for (int i = 0; i < g_width; ++i){
        for (int j = 0; j < g_height; ++j){
            if (j > g_height || i > g_width || i<0 || j<0) return;

    unsigned char c = 255;
    //int r=255, g=255, b=255;
     int r=176, g=226,	b=255;
    unsigned int color = (c << 24) | (r << 16) | (g << 8) | b;

    g_framebuffer[j*g_width + i] = color;
    zBuffer[g_height*i +j] =999999;
  //  zBuffer[i +j*g_width] =1.0f;
        }
    }
}

//bool pointInsideTriangle(const Vector & p, const Vector & a, const Vector & b, const Vector & c) {
//  float x = (p - a).crossProduct(b - a).z;
//  float y = (p - b).crossProduct(c - b).z;
//  float z = (p - c).crossProduct(a - c).z;
//  return (x >= 0 && y >= 0 && z >= 0) || (x < 0 && y < 0 && z < 0);
//}
////z buffering implemented here
//void triangleFill(const Vector & a, const Vector & b, const Vector & c, unsigned char r,unsigned char g, unsigned char b,const Vector& Camera,const Vector& LookTo,float near, float far, float width, float height) {
//
//  Vector vca = WorldToView(a,Camera,LookTo,near,far,width,height);
//  Vector vcb = WorldToView(b,Camera,LookTo,near,far,width,height);
//  Vector vcc = WorldToView(c,Camera,LookTo,near,far,width,height);
//  Vector normal = (vcb - vca).crossProduct(vcc - vca); //obtain the triangle normal, i.e. a, b, c components of the plane
//  double d = -(normal.x * vca.x + normal.y * vca.y + normal.z * vca.z); // ax + by + cz + d = 0, d = -(ax + by + cz), put Vector vca
//  point pa = ViewToPixel(vca,Camera,LookTo,near,far,width,height);
//  point pb = ViewToPixel(vcb,Camera,LookTo,near,far,width,height);
//  point pc = ViewToPixel(vcc,Camera,LookTo,near,far,width,height);
//  double minx = min(pa.x, min(pb.x, pc.x)), miny = min(pa.y, min(pb.y, pc.y));
//  double maxx = max(pa.x, max(pb.x, pc.x)), maxy = max(pa.y, max(pb.y, pc.y));
//
//  for (int i = miny; i <= maxy; ++i) {
//    if (i < 0) continue;
//    if (i >= g_height) break;
//    bool inside = 0;
//    for (int j = max(minx, 0.0); j <= maxx; ++j) {
//      if (j >= g_width) break;
//      if (pointInsideTriangle(Vector(j, i, 0), pa, pb, pc)) {
//	inside = 1;
////	double D = cam.ze - cam.zv;
////	double xp = j - SCREEN_WIDTH / 2, yp = i - SCREEN_HEIGHT / 2;
////	double F = normal.x * xp + normal.y * yp - normal.z * D;  //????
////	double Vector_z = ((normal.x * xp + normal.y * yp) * cam.ze + d * D) / F;
//    float xp= (j/width-0.5f)*2, yp = (i/height-0.5f)*2;
//
//	if (Vector_z < zBuffer[i*g_width+j]) {
//	  zBuffer[i*g_width+j] = Vector_z;
////	  setpixel(screen, j, i, color);
//	  PutPixel(Vertex(j,i,Vector_z),r,g,b);
//	}
//      } else if (inside) break;
//    }
//  }
//}



