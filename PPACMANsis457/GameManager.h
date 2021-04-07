#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "Pacman.h"
#include "Fantasma.h"
#include "Ceresa.h"


using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    //The surface contained by the window
    SDL_Surface* gScreenSurface;

    //The images we will load and show on the screen
    SDL_Surface* gPacManSurface;
    SDL_Surface* gFantasmaSurface;
    SDL_Surface* gCeresaSurface;

public:
    GameManager();
    int onExecute();

    bool onInit();

    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();

    /*  SDL_Surface* loadMediaToSurface(string _mediaFile);*/

    Pacman* pacman;
    Fantasma fantasma;
    Ceresa ceresa;
};



