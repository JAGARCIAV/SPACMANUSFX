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
    SDL_Texture* gPacmanTexture;
    SDL_Texture* gFantasmaTexture;
    //SDL_Texture* gFrutasTextures[3];
    vector<SDL_Texture*> gFrutasTextures;
    SDL_Texture* gMonedaTexture;
    SDL_Texture* gSuperMonedaTexture;

    Texture* fantasmaTexture= nullptr;

    /*
    SDL_Texture* gFruta01Texture;
    SDL_Texture* gFruta02Texture;
    SDL_Texture* gFruta03Texture;
    SDL_Texture* gFruta04Texture;
    */

public:
    Pacman* pacman;
    vector<Fantasma*> fantasma[3];
    vector<Fruta*> fruta;
    vector<Moneda*> monedas;
    vector<Moneda*> superMonedas;
    vector<GameObject*> actoresJuego;
public:
    GameManager();
    int onExecute();

    bool onInit();

    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
    SDL_Texture* loadTexture(string path);
};

