#include <stdio.h>
#include "Pacman.h"

Pacman::Pacman()
{
	//Initialize the offsets
	posicion = { 0, 0 };
	velocidad = { 0, 0 };
}

void Pacman::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidad.y -= PACMAN_VEL; break;
		case SDLK_DOWN: velocidad.y += PACMAN_VEL; break;
		case SDLK_LEFT: velocidad.x -= PACMAN_VEL; break;
		case SDLK_RIGHT: velocidad.x += PACMAN_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidad.y += PACMAN_VEL; break;
		case SDLK_DOWN: velocidad.y -= PACMAN_VEL; break;
		case SDLK_LEFT: velocidad.x += PACMAN_VEL; break;
		case SDLK_RIGHT: velocidad.x -= PACMAN_VEL; break;
		}
	}
	//move();
}

void Pacman::move()
{
	//Move the dot left or right
	posicion.x += velocidad.x;

	//If the dot went too far to the left or right
	if ((posicion.x < 0) || (posicion.x + PACMAN_WIDTH > SCREEN_WIDTH))
	{
		//Move back
		posicion.x -= velocidad.x;
	}

	//Move the dot up or down
	posicion.y += velocidad.y;

	//If the dot went too far up or down
	if ((posicion.y < 0) || (posicion.y + PACMAN_HEIGHT > SCREEN_HEIGHT))
	{
		//Move back
		posicion.y -= velocidad.y;
	}
}

void Pacman::render()
{

	//Color key image
	SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(pacmanSurface->format, 0, 0xFF, 0xFF));

	SDL_Texture* newTexture = NULL;

	newTexture = SDL_CreateTextureFromSurface(renderer, pacmanSurface);
	if (newTexture == NULL)
	{
		cout << "Unable to create texture from pacmanSurface, SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		//Get image dimensions
		ancho = pacmanSurface->w;
		alto = pacmanSurface->h;
	}

	SDL_Rect* clip = NULL;
	double angle = 0.0;
	SDL_Point* center = NULL;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	SDL_Rect renderQuad = { posicion.x, posicion.y, ancho, alto };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, newTexture, clip, &renderQuad, angle, center, flip);
}


