#pragma once
#include <SDL.h>

class Pacman
{
private:
	SDL_Point posicion;
	int color;
	float velocidadX;
	float velocidadY;
public:
	void move(float _velocidadX, float _velocidadY) {};

	SDL_Point getPosicion() { return posicion; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }

	float getVelocidadX() { return velocidadX; }
	void setVelocidadX(float _velocidadX) { velocidadX = _velocidadX; }
	float getVelocidadY() { return velocidadY; }
	void setVelocidadY(float _velocidadY) { velocidadY = _velocidadY; }
};