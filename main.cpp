#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Draw.h"
#include "Matrix.h"
#include "shapes.h"
#include <cstdlib>
#include "Vector.h"

using namespace std;
//flags for transformation
float thetaX=0,thetaY=0,thetaz=0,sx=1,sy=1,sz=1;



void Render(const Matrix w2v,const Matrix projection)
{
    // All rendering code goes here:

// initializing all the parts of the "Hawamma Mahal"
    cube base(Vector(0,0,100),100,100,5,205	,193,	197);
    cube side1(Vector(0,50,5),5,5,50,224,	255,	255);
    cube side2(Vector(0,50,50+50),5,5,50,224,	255,	255);
    cube side3(Vector(45+50,50,50+50),5,5,50,224,	255,	255);
    cube side4(Vector(45+50,50,5),5,5,50,224,	255,	255);
    cube Main(Vector(15,50,85),70,70,50,255,	182, 193);
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


    cube top(Vector(30,75,70),40,40,25,255,	0, 193);

  //  pyramid top(Vector(25+25,70,25+25),30,40,238	,162	,173);
    flag f(Vector(25+25,95,25+25),Vector(25+25,120,25+25),Vector(25+25,105,25+25),Vector(25+25,120,25+25),Vector(27.5+25+20,105,25+25),102	,139	,139);
 //   top.Draw(Camera,LookTo,0.01f,1000.0f,g_width,g_height);


    sphere golo1(Vector(2.5,57.5,2.5),5,139	,0,	139);
    sphere golo2(Vector(2.5,57.5,97.5),5,139	,0,	139);
    sphere golo3(Vector(97.5,57.5,97.5),5,139	,0,	139);
    sphere golo4(Vector(97.5,57.5,2.5),5,139	,0,	139);

    Csphere light(Vector(120,120,50),5,255,0,0);
//
    hemisphere semi(Vector(50,75,50),20,139,0,139);
//
////
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


    if(sx>0)
    {
    Matrix _scale = scal(sx,sy,sz);
        base._trans(_scale);
        side1._trans(_scale);
        side2._trans(_scale);
        side3._trans(_scale);
        side4._trans(_scale);
        Main._trans(_scale);
        door._trans(_scale);

        main1._trans(_scale);
        main2._trans(_scale);
        main3._trans(_scale);
        main4._trans(_scale);
        main5._trans(_scale);
        main6._trans(_scale);
        main7._trans(_scale);
        main8._trans(_scale);
        main10._trans(_scale);
        main11._trans(_scale);
        main12._trans(_scale);
        main13._trans(_scale);
        main14._trans(_scale);
        main15._trans(_scale);
        main16._trans(_scale);
        main17._trans(_scale);
        main18._trans(_scale);
        main19._trans(_scale);
        main20._trans(_scale);
        main21._trans(_scale);

        top._trans(_scale);
        f._trans(_scale);

        golo1._trans(_scale);
        golo2._trans(_scale);
        golo3._trans(_scale);
        golo4._trans(_scale);
        semi._trans(_scale);

        thisss._trans(_scale);
        thissss._trans(_scale);
        thisssss._trans(_scale);


        yo._trans(_scale);
        yo1._trans(_scale);
        yo2._trans(_scale);


        this1._trans(_scale);
        this2._trans(_scale);
        this3._trans(_scale);

        this11._trans(_scale);
        this22._trans(_scale);
        this33._trans(_scale);

    }

    if(thetaX!=0)
    {
    Matrix xRot = rotX(thetaX);

        base._trans(xRot);
        side1._trans(xRot);
        side2._trans(xRot);
        side3._trans(xRot);
        side4._trans(xRot);
        Main._trans(xRot);
        door._trans(xRot);
      //  main._trans(xRot);

        main1._trans(xRot);
        main2._trans(xRot);
        main3._trans(xRot);
        main4._trans(xRot);
        main5._trans(xRot);
        main6._trans(xRot);
        main7._trans(xRot);
        main8._trans(xRot);
        main10._trans(xRot);
        main11._trans(xRot);
        main12._trans(xRot);
        main13._trans(xRot);
        main14._trans(xRot);
        main15._trans(xRot);
        main16._trans(xRot);
        main17._trans(xRot);
        main18._trans(xRot);
        main19._trans(xRot);
        main20._trans(xRot);
        main21._trans(xRot);

        top._trans(xRot);
        f._trans(xRot);

        golo1._trans(xRot);
        golo2._trans(xRot);
        golo3._trans(xRot);
        golo4._trans(xRot);
        semi._trans(xRot);

        thisss._trans(xRot);
        thissss._trans(xRot);
        thisssss._trans(xRot);


        yo._trans(xRot);
        yo1._trans(xRot);
        yo2._trans(xRot);


        this1._trans(xRot);
        this2._trans(xRot);
        this3._trans(xRot);

        this11._trans(xRot);
        this22._trans(xRot);
        this33._trans(xRot);

    }

    if(thetaY!=0)
    {

    Matrix yRot = rotY(thetaY);

        base._trans(yRot);
        side1._trans(yRot);
        side2._trans(yRot);
        side3._trans(yRot);
        side4._trans(yRot);
        Main._trans(yRot);
        door._trans(yRot);
       // main._trans(yRot);

        main1._trans(yRot);
        main2._trans(yRot);
        main3._trans(yRot);
        main4._trans(yRot);
        main5._trans(yRot);
        main6._trans(yRot);
        main7._trans(yRot);
        main8._trans(yRot);
        main10._trans(yRot);
        main11._trans(yRot);
        main12._trans(yRot);
        main13._trans(yRot);
        main14._trans(yRot);
        main15._trans(yRot);
        main16._trans(yRot);
        main17._trans(yRot);
        main18._trans(yRot);
        main19._trans(yRot);
        main20._trans(yRot);
        main21._trans(yRot);

        top._trans(yRot);
        f._trans(yRot);

        golo1._trans(yRot);
        golo2._trans(yRot);
        golo3._trans(yRot);
        golo4._trans(yRot);
        semi._trans(yRot);

        thisss._trans(yRot);
        thissss._trans(yRot);
        thisssss._trans(yRot);


        yo._trans(yRot);
        yo1._trans(yRot);
        yo2._trans(yRot);


        this1._trans(yRot);
        this2._trans(yRot);
        this3._trans(yRot);

        this11._trans(yRot);
        this22._trans(yRot);
        this33._trans(yRot);

    }
// Rendering
    door.Draw(w2v, projection);
    main1.Draw(w2v, projection);
    main2.Draw(w2v, projection);
    main3.Draw(w2v, projection);
    main4.Draw(w2v, projection);
    main5.Draw(w2v, projection);
    main6.Draw(w2v, projection);
    main7.Draw(w2v, projection);
    main8.Draw(w2v, projection);
    main10.Draw(w2v, projection);
    main11.Draw(w2v, projection);
    main12.Draw(w2v, projection);
    main13.Draw(w2v, projection);
    main14.Draw(w2v, projection);
    main15.Draw(w2v, projection);
    main16.Draw(w2v, projection);
    main17.Draw(w2v, projection);
    main18.Draw(w2v, projection);
    main19.Draw(w2v, projection);
    main20.Draw(w2v, projection);
    main21.Draw(w2v, projection);

    top.Draw(w2v, projection);

    base.Draw(w2v, projection);
    side1.Draw(w2v, projection);
    side2.Draw(w2v, projection);
    side3.Draw(w2v, projection);
    side4.Draw(w2v, projection);
    Main.Draw(w2v, projection);
    f.Draw(w2v, projection);
//
    golo1.Draw(w2v, projection);
    golo2.Draw(w2v, projection);
    golo3.Draw(w2v, projection);
    golo4.Draw(w2v, projection);
//
    semi.Draw(w2v, projection);
//
    thisss.Draw(w2v, projection);
    thissss.Draw(w2v, projection);
    thisssss.Draw(w2v, projection);

    yo.Draw(w2v, projection);
    yo1.Draw(w2v, projection);
    yo2.Draw(w2v, projection);

    this1.Draw(w2v, projection);
    this2.Draw(w2v, projection);
    this3.Draw(w2v, projection);

    this11.Draw(w2v, projection);
    this22.Draw(w2v, projection);
    this33.Draw(w2v, projection);

    light.Draw(w2v,projection);
}

int main()
{
    //SDL ko kura haru
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Hawamaa Mahal", 100, 100, 1366, 768, SDL_WINDOW_SHOWN);
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    g_framebuffer = (unsigned int*)screen->pixels;
    // screen hieight and width for future use
    g_width = screen->w;
    g_height = screen->h;
//camera and lookto vectors
    Vector Camera(20,50,-100);
    cam = Camera;
    Vector LookTo(20,0,80);

//Event handling
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
                    case SDLK_RIGHT:
                        RotateY(Camera,2);
                        break;
                    case SDLK_LEFT:
                        RotateY(Camera,-2);
                        break;
                    case SDLK_i:
                        sx+=0.2; sy+=0.2; sz+=0.2;  //scale ++
                        break;
                    case SDLK_o:
                        sx-=0.2; sy-=0.2; sz-=0.2;  //scale --
                        if (sx<=0.2)
                        {
                            sx=0.2; sy=0.2; sz=0.2;
                        }
                        break;
                    case SDLK_x:
                        thetaX+=5;  //xrotation ++
                        break;
                    case SDLK_y:
                        thetaY+=5;     //yrotation ++
                        break;

                }
            }
        }
        // matrices to be used for world to pixel transformation, defined in transformation.cpp
    Matrix w2v = Cam(Camera,LookTo);
    Matrix projection = proj(0.01f,1000.0f,g_width,g_height);

        Clear();        //zBuffer reset and clear screen, defined at the end of Draw.h

        SDL_LockSurface(screen);
// Rendering function, defined mathi
        Render(w2v,projection);

        SDL_UnlockSurface(screen);

        SDL_UpdateWindowSurface(win);

    }

    SDL_FreeSurface(screen);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
