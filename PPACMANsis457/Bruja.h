#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Bruja : public GameObject {
private:
	//Velocidad en eje X y Y
	int velocidadX;
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXDestino;
	int posicionYDestino;

	int incrementoPosicionX;
	int incrementoPosicionY;


public:
	//Constructores y destructores
	Bruja(Texture* _brujaTexture, int _posicionX, int _posicionY, int _ancho, int _alto,
		int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Bruja();

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	void move();



};