#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta() {
	al = 0;
	posicionX = 50;
	posicionY = 50;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;

	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
}

Fruta::Fruta(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutasTextures[3], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;

	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	frutasTextures[0] = _frutasTextures[0];
	frutasTextures[1] = _frutasTextures[1];
	frutasTextures[2] = _frutasTextures[2];
	frutasTextures[3] = _frutasTextures[3];
}


void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % anchoPantalla;
			posicionY = 1 + rand() % altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
		al = rand() % 4;
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {

		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		SDL_RenderCopyEx(renderer, frutasTextures[al], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}