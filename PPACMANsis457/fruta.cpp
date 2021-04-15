#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(SDL_Renderer* _renderer, SDL_Texture* _frutasTextures[3], int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla), renderer(_renderer) {
	// Inicializa propiedade de la fruta
	tipoFruta = TIPO_FRUTA_GUINDA;
	R = 0;
	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	//renderer = _renderer;
	frutasTextures[0] = _frutasTextures[0];
	frutasTextures[1] = _frutasTextures[1];
	frutasTextures[2] = _frutasTextures[2];
	frutasTextures[3] = _frutasTextures[3];
}


void Fruta::mostrar()
{
	srand(time(NULL));
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
		R = rand() % 4;
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {

		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		SDL_RenderCopyEx(renderer, frutasTextures[R], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}