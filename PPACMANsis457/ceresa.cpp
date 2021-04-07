#include "Ceresa.h"
#include <iostream>

using namespace std;

Ceresa::Ceresa() {
	posicionX = 200;
	posicionY = 200;
	//velocidadX = 0;
	//velocidadY = 0;
	//velocidadPatron = 4;
	tiempo = 0;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
}


void Ceresa::move()
{

	// Mover el ceresa a la izquierda o derecha
	//posicionX += velocidadX;

	// Verificar si la posicion del ceresa no salio de los bordes izquierdo o derecho
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{

		// Mover ceresa atras
		//posicionX += velocidadX;
	}

	// Mover el ceresa arriba o abajo
	//posicionY -= velocidadY;

	// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// Mover ceresa atras
		//posicionY -= velocidadY;
	}
}

void Ceresa::render()
{
	// Color primario de la imagen del fantasma
	//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(fantasmaSurface->format, 0, 0, 0));

	SDL_Texture* nuevaTextura = NULL;

	nuevaTextura = SDL_CreateTextureFromSurface(renderer, ceresaSurface);
	if (nuevaTextura == NULL)
	{
		cout << "No se puede crear una textura a partir de ceresaSurface, SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		// Obtener dimension de la imagen
		ancho = ceresaSurface->w;
		alto = ceresaSurface->h;
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