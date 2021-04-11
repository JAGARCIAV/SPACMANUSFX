#include "Fantasma3.h"
#include <iostream>

using namespace std;

Fantasma3::Fantasma3() {

	xi = 0;
	xf = 0;
	yi = 0;
	yf = 0;
	posicionX = 400;
	posicionY = 250;
	velocidadX = 2;
	velocidadY = 5;


	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 1400;
	altoPantalla = 1000;
}


void Fantasma3::move()
{

	// Mover el fantasma a la derecha o izquierda
	posicionX += velocidadX;

	// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{
		// Mover fantasma atras
		posicionX -= velocidadX;

		velocidadX *= -1;

	}

	// Mover el fantasma arriba o abajo
	posicionY -= velocidadY;

	// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// Mover fantasma atras
		posicionY += velocidadY;
		velocidadY *= -1;
	}


}


void Fantasma3::render()
{
	// Color primario de la imagen del fantasma
	//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(fantasmaSurface->format, 0, 0, 0));

	SDL_Texture* nuevaTextura = NULL;

	nuevaTextura = SDL_CreateTextureFromSurface(renderer, fantasma3Surface);
	if (nuevaTextura == NULL)
	{
		cout << "No se puede crear una textura a partir de fantasma3Surface, SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		// Obtener dimension de la imagen
		ancho = fantasma3Surface->w;
		alto = fantasma3Surface->h;
	}

	/*SDL_Rect* clip = nullptr;
	double angle = 0.0;
	SDL_Point* center = nullptr;
	SDL_RendererFlip flip = SDL_FLIP_NONE;*/

	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto, };

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
