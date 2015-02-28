
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Draw.h"
#include "Pipeline.h"
#include "shapes.h"
using namespace std;

void Render(Vector Camera)
{
    // All rendering code goes here:
    Vector LookTo(0,0,0);
//    Vector aa(0,0,0);
//    Vector bb(10,0,0);
//    Vector cc(10,10,0);
//    Vector dd(0,10,0);
//    Vector ee(0,0,10);
//    Vector ff(10,0,10);
//    Vector gg(10,10,10);
//    Vector hh(0,10,10);
//    point a1,b1,c1,d1,e1,f1,g1,h1;
//    a1=WorldToPixel(aa,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    b1=WorldToPixel(bb,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    c1=WorldToPixel(cc,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    d1=WorldToPixel(dd,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    e1=WorldToPixel(ee,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    f1=WorldToPixel(ff,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    g1=WorldToPixel(gg,Camera,LookTo,0.01f,1000.0f, 800, 600);
//    h1=WorldToPixel(hh,Camera,LookTo,0.01f,1000.0f, 800, 600);
//
//    Vertex a(a1.x,a1.y);
//    Vertex b(b1.x,b1.y);
//    Vertex c(c1.x,c1.y);
//    Vertex d(d1.x,d1.y);
//    Vertex e(e1.x,e1.y);
//    Vertex f(f1.x,f1.y);
//    Vertex g(g1.x,g1.y);
//    Vertex h(h1.x,h1.y);
//
//    Line e0(a,b);
//    Line e2(b,c);
//    Line e3(c,d);
//    Line e4(d,a);
//    Line e5(e,f);
//    Line e6(f,g);
//    Line e7(g,h);
//    Line e8(h,e);
//    Line e9(a,e);
//    Line e10(b,f);
//    Line e11(c,g);
//    Line e12(d,h);
//
//    e0.DrawLine(16,0,31);
//    e2.DrawLine(161,0,131);
//    e3.DrawLine(16,0,31);
//    e4.DrawLine(16,0,31);
//    e5.DrawLine(16,0,31);
//    e6.DrawLine(126,0,31);
//    e7.DrawLine(16,0,31);
//    e8.DrawLine(1,0,31);
//    e9.DrawLine(16,110,31);
//    e10.DrawLine(16,0,31);
//    e11.DrawLine(16,140,31);
//    e12.DrawLine(16,1,31);
    cube base(Vector(0,0,0),100,-100,5);
    cube side1(Vector(0,50,5),5,5,50);
    cube side2(Vector(0,50,50+50),5,5,50);
    cube side3(Vector(45+50,50,50+50),5,5,50);
    cube side4(Vector(45+50,50,5),5,5,50);
    cube main(Vector(5+50/2,40,5+50/2),40,-40,40);
    pyramid top(Vector(25+25,70,25+25),30,40);
    flag f(Vector(25+25,70,25+25),Vector(25+25,80,25+25),Vector(25+25,75,25+25),Vector(25+25,80,25+25),Vector(27.5+25,75,25+25));
    top.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    base.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    side1.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    side2.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    side3.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    side4.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    main.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
    f.Draw(Camera,LookTo,0.01f,1000.0f,1024,700);
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Teskaaaa Baaaaaaajey!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    Vector Camera(0,0,-70);
    g_framebuffer = (unsigned int*)screen->pixels;
    zBuffer = new float [g_width*g_height]();
    g_width = screen->w;
    g_height = screen->h;
    zBufferRst();
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if(e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym){
                    case SDLK_w:
                        Camera.y++;
                        break;
                    case SDLK_s:
                        Camera.y--;
                        break;
                    case SDLK_a:
                        Camera.x--;
                        break;
                    case SDLK_d:
                        Camera.x++;
                        break;
                    case SDLK_UP:
                        Camera.z++;
                        break;
                    case SDLK_DOWN:
                        Camera.z--;
                        break;
                }
            }
        }

        Clear();
        zBufferRst();
        SDL_LockSurface(screen);

        Render(Camera);

        SDL_UnlockSurface(screen);

        SDL_UpdateWindowSurface(win);

    }

    SDL_FreeSurface(screen);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
