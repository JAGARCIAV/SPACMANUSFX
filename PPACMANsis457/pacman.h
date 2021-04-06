#pragma once
#include <SDL.h>

class Pacman
{
private:
	SDL_Point posicion;
	SDL_Point velocidad;

public:
	void move(float _velocidadX, float _velocidadY) {};

	SDL_Point getPosicion() { return posicion; }
	int getPosicionX() { return posicion.x; }
	int getPosicionY() { return posicion.y; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }
	void setPosicionX(int _x) { posicion.x = _x; }
	void setPosicionY(int _y) { posicion.y = _y; }



	SDL_Point getVelocidad() { return velocidad; }
	int getVelocidadX() { return velocidad.x; }
	int getVelocidadY() { return velocidad.y; }
	void setVelocidad(SDL_Point _velocidad) { velocidad = _velocidad; }
	void setVelocidadX(int _x) { velocidad.x = _x; }
	void setVelocidadY(int _y) { velocidad.y = _y; }

};

