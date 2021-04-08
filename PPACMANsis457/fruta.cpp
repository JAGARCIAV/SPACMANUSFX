#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta() {
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
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {
		// Color primario de la imagen del Fruta
		//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(FrutaSurface->format, 0, 0, 0));

		SDL_Texture* nuevaTextura = NULL;

		nuevaTextura = SDL_CreateTextureFromSurface(renderer, frutaSurface);
		if (nuevaTextura == NULL)
		{
			cout << "No se puede crear una textura a partir de FrutaSurface, SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			// Obtener dimension de la imagen
			ancho = frutaSurface->w;
			alto = frutaSurface->h;
		}

		/*SDL_Rect* clip = nullptr;
		double angle = 0.0;
		SDL_Point* center = nullptr;
		SDL_RendererFlip flip = SDL_FLIP_NONE;*/

		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

		// Establecer las dimensionces del recorte para remderizar
		/*if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}*/

		// Renderizar en la pantalla
		//SDL_RenderCopyEx(renderer, nuevaTextura, clip, &renderQuad, angle, center, flip);
		SDL_RenderCopyEx(renderer, nuevaTextura, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}