#pragma once
//#include </home/aditya/Graphics/Vector.h>
// framebuffer is array of pixels
unsigned int* g_framebuffer;
// size of window
int g_width, g_height;
float* zBuffer;

// Here r,g,b values can range from 0-255 (00H-FFH)

class Vertex{
    public:
        int x;
        int y;
        int z; //for depth value
        Vertex():x(0),y(0),z(0){}
        //Vertex(Vec2& v):x(v.x),y(v.y){}
        Vertex(int xx,int yy):x(xx),y(yy){
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
    if (v.z > zBuffer[g_height*v.x + v.y])
        return;
    else
        zBuffer[g_height*v.x + v.y] = v.z;
    g_framebuffer[v.y*g_width + v.x] = color;
}

void zBufferRst()
    {
            delete[] zBuffer;
            zBuffer = new float [g_width*g_height]();
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
            int x1=v1.x;
            int x2=v2.x;
            int y1=v1.y;
            int y2=v2.y;
            int dx=abs(x2-x1);
   	        int dy=abs(y2-y1);
   	        int x_inc=1;
   	        int y_inc=1;
   	        if((x2-x1)!=0){
   	    	    x_inc=(x2-x1)/dx;
   	        }
   	        if((y2-y1)!=0){
   		        y_inc=(y2-y1)/dy;
   	        }
   	        Vertex P(x1,y1);
   	        PutPixel(P,r,g,b);
   	        if(dx<dy){
   		        int p=2*dx-dy;
   		        int k=0;
   		        while(k!=dy){
   			        if(p<0){
   				        P.increase_y(y_inc);
   				        p=p+2*dx;
   			        }
   			        else{
   				        P.increase_x(x_inc);
                        P.increase_y(y_inc);
   				        p=p+2*dx-2*dy;
   			        }
   			        k++;
   			        PutPixel(P,r,g,b);
   		        }
   	        }
   	        else{
   		        int p=2*dy-dx;
   		        int k=0;
   		        while(k!=dx){
   			        if(p<0){
   				        P.increase_x(x_inc);
   				        p=p+2*dy;
   			        }
   			        else{
   				        P.increase_x(x_inc);
   				        P.increase_y(y_inc);
   				        p=p+2*dy-2*dx;
   			        }
   			        k++;
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
            v2.x=0;
            v2.y=0;
            v3.x=0;
            v3.y=0;
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

        void DrawTriangle(int r,int g,int b){
            int x1=v1.x;
            int x2=v2.x;
            int x3=v3.x;
            int y1=v1.y;
            int y2=v2.y;
            int y3=v3.y;
            int y[]={y1,y2,y3};
            int x[]={x1,x2,x3};
            for(int j=0;j<2;j++){
                for(int k=j+1;k<3;k++)
                    if(y[j]>y[k]){
                        int temp=y[j];
                        y[j]=y[k];
                        y[k]=temp;
                        temp=x[j];
                        x[j]=x[k];
                        x[k]=temp;
                    }
            }
            int y_top=y[2];
            int y_mid=y[1];
            int y_bottom=y[0];

            //From Top to Mid

            Vertex start(x[2],y_top);
            Vertex end(x[2],y_top);

            //For Start Edge
            int dxs=abs(x[1]-x[2]);
            int dys=abs(y[1]-y[2]);
            int xs_inc=1;
            if((x[1]-x[2]!=0)){
                xs_inc=(x[1]-x[2])/dxs;
            }

            int ps1=2*dxs-dys;
            int ps2=2*dys-dxs;

            //For End Edge
            int dxe=abs(x[0]-x[2]);
            int dye=abs(y[0]-y[2]);
            int xe_inc=1;
            if((x[0]-x[2]!=0)){
                xe_inc=(x[0]-x[2])/dxe;
            }

            int pe1=2*dxe-dye;
            int pe2=2*dye-dxe;

            int ks=0;
            int ke=0;

            Line ScanLine(start,end);

            if(y_top!=y_mid){
            for(int y=y_top;y>=y_mid;y--){
                ScanLine.v1.set_y(y);
                ScanLine.v2.set_y(y);
                ScanLine.DrawLine(r,g,b);
                //for Start Edge
                {
                    if(dxs<dys){
                        if(ps1<0){
                            ps1=ps1+2*dxs;
                        }
                        else{
                            ScanLine.v1.increase_x(xs_inc);
                            ps1=ps1+2*dxs-2*dys;
                        }
                }
                    else{
                        while(ks!=dxs){
                            if(ps2<0){
                                ScanLine.v1.increase_x(xs_inc);
                                ps2=ps2+2*dys;
                            }
                            else{
                                ps2+=2*dys-2*dxs;
                                ScanLine.v1.increase_x(xs_inc);
                                break;
                            }
                        }
                    }
                }
                //for End Edge
                {
                    if(dxe<dye){
                        if(pe1<0){
                            pe1=pe1+2*dxe;
                        }
                        else{
                            ScanLine.v2.increase_x(xe_inc);
                            pe1=pe1+2*dxe-2*dye;
                        }
                    }
                    else{
                        while(ke!=dxe){
                            if(pe2<0){
                                ScanLine.v2.increase_x(xe_inc);
                                pe2=pe2+2*dye;
                            }
                            else{
                                pe2+=2*dye-2*dxe;
                                ScanLine.v2.increase_x(xe_inc);
                                break;
                            }
                        }
                    }
                }
            }
            }
        ///////////////////////////////////
            //From Bottom to Mid

            start.set_x(x[0]);
            end.set_x(x[0]);

            Line Scanline2(start,end);

            //For Start Edge
            dxs=abs(x[1]-x[0]);
            dys=abs(y[1]-y[0]);
            xs_inc=1;
            if((x[1]-x[0]!=0)){
                xs_inc=(x[1]-x[0])/dxs;
            }

            ps1=2*dxs-dys;
            ps2=2*dys-dxs;

            //For End Edge
            dxe=abs(x[2]-x[0]);
            dye=abs(y[2]-y[0]);
            xe_inc=1;
            if((x[2]-x[0]!=0)){
                xe_inc=(x[2]-x[0])/dxe;
            }

            pe1=2*dxe-dye;
            pe2=2*dye-dxe;

            ks=0;
            ke=0;
            if(y_bottom!=y_mid){
            for(int y=y_bottom;y<=y_mid;y++){
                Scanline2.v1.set_y(y);
                Scanline2.v2.set_y(y);
                Scanline2.DrawLine(r,g,b);
                //for Start Edge
                {
                    if(dxs<dys){
                        if(ps1<0){
                            ps1=ps1+2*dxs;
                        }
                        else{
                            Scanline2.v1.increase_x(xs_inc);
                            ps1=ps1+2*dxs-2*dys;
                        }
                    }
                    else{
                        while(ks!=dxs){
                            if(ps2<0){
                                Scanline2.v1.increase_x(xs_inc);
                                ps2=ps2+2*dys;
                            }
                            else{
                                ps2+=2*dys-2*dxs;
                                Scanline2.v1.increase_x(xs_inc);
                                break;
                            }
                        }
                    }
                }
                //for End Edge
                {
                    if(dxe<dye){
                        if(pe1<0){
                            pe1=pe1+2*dxe;
                        }
                        else{
                            Scanline2.v2.increase_x(xe_inc);
                            pe1=pe1+2*dxe-2*dye;
                        }
                    }
                    else{
                        while(ke!=dxe){
                            if(pe2<0){
                                Scanline2.v2.increase_x(xe_inc);
                                pe2=pe2+2*dye;
                            }
                            else{
                                pe2+=2*dye-2*dxe;
                                Scanline2.v2.increase_x(xe_inc);
                                break;
                            }
                        }
                    }
                }
            }
            }
        ///////////////////////////////////
        }
};

// Clear all pixels with white color
void Clear(){
    for (int i = 0; i < g_width; ++i){
        for (int j = 0; j < g_height; ++j){
            Vertex a(i,j);

            if (a.y > g_height || a.x > g_width || a.x<0 || a.y<0) return;

    unsigned char c = 255;
    int r=255, g=255, b=255;
    // Create the color for given rgb values: the format for integer in hex is aarrggbb
    // e.g. for white all r,g,b are FFH: FFFFFFFF
    //      for balck, all are 00H:  FF000000
    unsigned int color = (c << 24) | (r << 16) | (g << 8) | b;

    g_framebuffer[a.y*g_width + a.x] = color;
        }
    }
}
