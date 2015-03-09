
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Draw.h"
#include "Pipeline.h"
#include "shapes.h"
#include <cstdlib>
using namespace std;

float thetaX=0,thetaY=0,thetaz=0,sx=0,sy=0,sz=0;

void Render(Vector Camera)
{
    // All rendering code goes here:
    Vector LookTo(50,0,0);

    cube base(Vector(0,0,0),100,-100,5,205	,193,	197);
    cube side1(Vector(0,50,5),5,5,50,224,	255,	255);
    cube side2(Vector(0,50,50+50),5,5,50,224,	255,	255);
    cube side3(Vector(45+50,50,50+50),5,5,50,224,	255,	255);
    cube side4(Vector(45+50,50,5),5,5,50,224,	255,	255);
    cube main(Vector(15,50,15),70,-40-30,50,255,	182, 193);
    cube door(Vector(15+25,35,15),20,3,35,0,0,0);

    cube main1(Vector(15,55,85),5,5,5,255,	182, 193);

    cube main2(Vector(80,55,85),5,5,5,255,	182, 193);

    cube main3(Vector(80,55,20),5,5,5,255,	182, 193);

    cube main4(Vector(15,55,20),5,5,5,255,	182, 193);

    cube main5(Vector(27,55,20),5,5,5,255,	182, 193);

    cube main6(Vector(39,55,20),5,5,5,255,	182, 193);

    cube main7(Vector(52,55,20),5,5,5,255,	182, 193);

    cube main8(Vector(66,55,20),5,5,5,255,	182, 193);

    cube main10(Vector(80,55,31),5,5,5,255,	182, 193);

    cube main11(Vector(80,55,43),5,5,5,255,	182, 193);

    cube main12(Vector(80,55,57),5,5,5,255,	182, 193);

    cube main13(Vector(80,55,72),5,5,5,255,	182, 193);

    cube main14(Vector(68,55,85),5,5,5,255,	182, 193);

    cube main15(Vector(55,55,85),5,5,5,255,	182, 193);

    cube main16(Vector(44,55,85),5,5,5,255,	182, 193);

    cube main17(Vector(29,55,85),5,5,5,255,	182, 193);

    cube main18(Vector(15,55,73),5,5,5,255,	182, 193);

    cube main19(Vector(15,55,60),5,5,5,255,	182, 193);

    cube main20(Vector(15,55,47),5,5,5,255,	182, 193);

    cube main21(Vector(15,55,35),5,5,5,255,	182, 193);


    cube top(Vector(30,75,30),40,-40,25,255,	0, 193);

  //  pyramid top(Vector(25+25,70,25+25),30,40,238	,162	,173);
    flag f(Vector(25+25,95,25+25),Vector(25+25,120,25+25),Vector(25+25,105,25+25),Vector(25+25,120,25+25),Vector(27.5+25+20,105,25+25),102	,139	,139);
 //   top.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);


    sphere golo1(Vector(2.5,57.5,2.5),5,139	,0,	139);
    sphere golo2(Vector(2.5,57.5,97.5),5,139	,0,	139);
    sphere golo3(Vector(97.5,57.5,97.5),5,139	,0,	139);
    sphere golo4(Vector(97.5,57.5,2.5),5,139	,0,	139);

    sphere semi(Vector(50,75,50),20,139,0,139);

//
    clouds thisss(Vector(-5,0,-5),255,255,255);
    clouds thissss(Vector(-5-10,0,25),255,255,255);
    clouds thisssss(Vector(-5-29,0,10),255,255,255);


    clouds yo(Vector(105,0,-5),255,255,255);
    clouds yo1(Vector(105-21,0,25),255,255,255);
    clouds yo2(Vector(105-8,0,10),255,255,255);


    clouds this1(Vector(105,0,95),255,255,255);
    clouds this2(Vector(105-12,0,125),255,255,255);
    clouds this3(Vector(105-18,0,110),255,255,255);

    clouds this11(Vector(-5,0,95),255,255,255);
    clouds this22(Vector(-5-12,0,125),255,255,255);
    clouds this33(Vector(-5-9,0,110),255,255,255);

    if(sx!=0)
    {
        base.scale(sx,sy,sz);
        side1.scale(sx,sy,sz);
        side2.scale(sx,sy,sz);
        side3.scale(sx,sy,sz);
        side4.scale(sx,sy,sz);
        main.scale(sx,sy,sz);
        door.scale(sx,sy,sz);
        main.scale(sx,sy,sz);

        main1.scale(sx,sy,sz);
        main2.scale(sx,sy,sz);
        main3.scale(sx,sy,sz);
        main4.scale(sx,sy,sz);
        main5.scale(sx,sy,sz);
        main6.scale(sx,sy,sz);
        main7.scale(sx,sy,sz);
        main8.scale(sx,sy,sz);
        main10.scale(sx,sy,sz);
        main11.scale(sx,sy,sz);
        main12.scale(sx,sy,sz);
        main13.scale(sx,sy,sz);
        main14.scale(sx,sy,sz);
        main15.scale(sx,sy,sz);
        main16.scale(sx,sy,sz);
        main17.scale(sx,sy,sz);
        main18.scale(sx,sy,sz);
        main19.scale(sx,sy,sz);
        main20.scale(sx,sy,sz);
        main21.scale(sx,sy,sz);

        top.scale(sx,sy,sz);
        f.scale(sx,sy,sz);

        golo1.scale(sx,sy,sz);
        golo2.scale(sx,sy,sz);
        golo3.scale(sx,sy,sz);
        golo4.scale(sx,sy,sz);
        semi.scale(sx,sy,sz);

    }

    if(thetaX!=0)
    {
        base.rotateX(thetaX);
        side1.rotateX(thetaX);
        side2.rotateX(thetaX);
        side3.rotateX(thetaX);
        side4.rotateX(thetaX);
        main.rotateX(thetaX);
        door.rotateX(thetaX);
        main.rotateX(thetaX);

        main1.rotateX(thetaX);
        main2.rotateX(thetaX);
        main3.rotateX(thetaX);
        main4.rotateX(thetaX);
        main5.rotateX(thetaX);
        main6.rotateX(thetaX);
        main7.rotateX(thetaX);
        main8.rotateX(thetaX);
        main10.rotateX(thetaX);
        main11.rotateX(thetaX);
        main12.rotateX(thetaX);
        main13.rotateX(thetaX);
        main14.rotateX(thetaX);
        main15.rotateX(thetaX);
        main16.rotateX(thetaX);
        main17.rotateX(thetaX);
        main18.rotateX(thetaX);
        main19.rotateX(thetaX);
        main20.rotateX(thetaX);
        main21.rotateX(thetaX);

        top.rotateX(thetaX);
        f.rotateX(thetaX);

        golo1.rotateX(thetaX);
        golo2.rotateX(thetaX);
        golo3.rotateX(thetaX);
        golo4.rotateX(thetaX);
        semi.rotateX(thetaX);

    }

    if(thetaY!=0)
    {
        base.rotateY(thetaY);
        side1.rotateY(thetaY);
        side2.rotateY(thetaY);
        side3.rotateY(thetaY);
        side4.rotateY(thetaY);
        main.rotateY(thetaY);
        door.rotateY(thetaY);
        main.rotateY(thetaY);

        main1.rotateY(thetaY);
        main2.rotateY(thetaY);
        main3.rotateY(thetaY);
        main4.rotateY(thetaY);
        main5.rotateY(thetaY);
        main6.rotateY(thetaY);
        main7.rotateY(thetaY);
        main8.rotateY(thetaY);
        main10.rotateY(thetaY);
        main11.rotateY(thetaY);
        main12.rotateY(thetaY);
        main13.rotateY(thetaY);
        main14.rotateY(thetaY);
        main15.rotateY(thetaY);
        main16.rotateY(thetaY);
        main17.rotateY(thetaY);
        main18.rotateY(thetaY);
        main19.rotateY(thetaY);
        main20.rotateY(thetaY);
        main21.rotateY(thetaY);

        top.rotateY(thetaY);
        f.rotateY(thetaY);

        golo1.rotateY(thetaY);
        golo2.rotateY(thetaY);
        golo3.rotateY(thetaY);
        golo4.rotateY(thetaY);
        semi.rotateY(thetaY);

    }

    door.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main5.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main6.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main7.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main8.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main10.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main11.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main12.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main13.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main14.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main15.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main16.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main17.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main18.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main19.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main20.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main21.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    top.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    base.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    side4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    main.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    f.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    golo1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    golo4.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    semi.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    thisss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    thissss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    thisssss.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    yo.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    yo1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    yo2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    this1.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this2.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this3.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);

    this11.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this22.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
    this33.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Hawamaa Mahal", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
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
                    case SDLK_z:
                        sx+=5; sy+=5; sz+=5;
                        break;
                    case SDLK_x:
                        thetaX+=5;
                        break;
                    case SDLK_y:
                        thetaY+=5;
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
