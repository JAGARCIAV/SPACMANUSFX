#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Moneda.h"
#include "Texture.h"
#include "MapGenerator.h"
#include "TileGraph.h"

using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 1625;
const int SCREEN_HEIGHT = 525;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

public:
    vector<GameObject*> actoresJuego;
    MapGenerator* generadorNivelJuego;
public:
    GameManager();
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
};

