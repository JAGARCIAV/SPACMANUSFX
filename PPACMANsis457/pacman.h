#pragma once
#include <SDL.h>

class Pacman
{
private:
	SDL_Point posicion;

	int color;

	SDL_Point velocidad;

public:

	SDL_Point getPosicion() { return posicion; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }


	SDL_Point getVelocidad() { return velocidad; }
	void setVelocidad(SDL_Point _velocidad) { velocidad = _velocidad; }

};