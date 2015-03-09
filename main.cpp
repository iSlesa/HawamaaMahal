
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Draw.h"
#include "Pipeline.h"
#include "shapes.h"
#include <cstdlib>
using namespace std;

void Render(Vector Camera)
{
    // All rendering code goes here:
    Vector LookTo(50,0,0);

    cube base(Vector(0,0,0),100,-100,5,205	,193,	197);
    cube side1(Vector(0,50,5),5,5,50,224,	255,	255);
    cube side2(Vector(0,50,50+50),5,5,50,224,	255,	255);
    cube side3(Vector(45+50,50,50+50),5,5,50,224,	255,	255);
    cube side4(Vector(45+50,50,5),5,5,50,224,	255,	255);
    cube main(Vector(5+50/2-15,50,5+50/2-15),40+30,-40-30,50,255,	182, 193);
    cube main1(Vector(15,55,85),5,5,5,255,	182, 193);
    main1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main2(Vector(80,55,85),5,5,5,255,	182, 193);
    main2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main3(Vector(80,55,20),5,5,5,255,	182, 193);
    main3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main4(Vector(15,55,20),5,5,5,255,	182, 193);
    main4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main5(Vector(27,55,20),5,5,5,255,	182, 193);
    main5.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main6(Vector(39,55,20),5,5,5,255,	182, 193);
    main6.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main7(Vector(52,55,20),5,5,5,255,	182, 193);
    main7.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main8(Vector(66,55,20),5,5,5,255,	182, 193);
    main8.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main10(Vector(80,55,31),5,5,5,255,	182, 193);
    main10.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main11(Vector(80,55,43),5,5,5,255,	182, 193);
    main11.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main12(Vector(80,55,57),5,5,5,255,	182, 193);
    main12.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main13(Vector(80,55,72),5,5,5,255,	182, 193);
    main13.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main14(Vector(68,55,85),5,5,5,255,	182, 193);
    main14.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main15(Vector(55,55,85),5,5,5,255,	182, 193);
    main15.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main16(Vector(44,55,85),5,5,5,255,	182, 193);
    main16.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main17(Vector(29,55,85),5,5,5,255,	182, 193);
    main17.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main18(Vector(15,55,73),5,5,5,255,	182, 193);
    main18.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main19(Vector(15,55,60),5,5,5,255,	182, 193);
    main19.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main20(Vector(15,55,47),5,5,5,255,	182, 193);
    main20.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    cube main21(Vector(15,55,35),5,5,5,255,	182, 193);
    main21.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    cube top(Vector(30,75,30),40,-40,25,255,	0, 193);
    top.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
  //  pyramid top(Vector(25+25,70,25+25),30,40,238	,162	,173);
    flag f(Vector(25+25,95,25+25),Vector(25+25,120,25+25),Vector(25+25,105,25+25),Vector(25+25,120,25+25),Vector(27.5+25+20,105,25+25),102	,139	,139);
 //   top.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    base.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    f.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    sphere golo1(Vector(2.5,57.5,2.5),5,139	,0,	139);
    sphere golo2(Vector(2.5,57.5,97.5),5,139	,0,	139);
    sphere golo3(Vector(97.5,57.5,97.5),5,139	,0,	139);
    sphere golo4(Vector(97.5,57.5,2.5),5,139	,0,	139);
    golo1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    sphere semi(Vector(50,75,50),20,139,0,139);
    semi.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    clouds thisss(Vector(-5,0,-5),255,255,255);
    clouds thissss(Vector(-5-10,0,25),255,255,255);
    clouds thisssss(Vector(-5-29,0,10),255,255,255);
    thisss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    thissss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    thisssss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    clouds yo(Vector(105,0,-5),255,255,255);
    clouds yo1(Vector(105-21,0,25),255,255,255);
    clouds yo2(Vector(105-8,0,10),255,255,255);
    yo.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    yo1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    yo2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    clouds this1(Vector(105,0,95),255,255,255);
    clouds this2(Vector(105-12,0,125),255,255,255);
    clouds this3(Vector(105-18,0,110),255,255,255);
    this1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    clouds this11(Vector(-5,0,95),255,255,255);
    clouds this22(Vector(-5-12,0,125),255,255,255);
    clouds this33(Vector(-5-9,0,110),255,255,255);
    this11.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this22.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this33.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Teskaaaa Baaaaaaajey!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    Vector Camera(30,50,-100);
    g_framebuffer = (unsigned int*)screen->pixels;
    g_width = screen->w;
    g_height = screen->h;
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
        //zBufferRst();
        SDL_LockSurface(screen);

        Render(Camera);
        //DrawTriangle(a,b,c);

        SDL_UnlockSurface(screen);

        SDL_UpdateWindowSurface(win);

    }

    SDL_FreeSurface(screen);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
