#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
//#include "Movimientos.h"
//#include "Textura.h"
using namespace std;

class Pacman
{
private:
	SDL_Point posicion;
	SDL_Point velocidad;

	int ancho;
	int alto;

public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const int PACMAN_WIDTH = 20;
	const int PACMAN_HEIGHT = 20;
	const int PACMAN_VEL = 10;


	Pacman();
	void handleEvent(SDL_Event& e);
	void move();
	void render();

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The window renderer
	SDL_Renderer* renderer = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


	//Scene textures
	//Textura* PacmanTextura;
	SDL_Surface* pacmanSurface = NULL;

};


