#pragma once
#include <iostream>
#include <string>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Pacman : public GameObject
{
private:
	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;


	int posicionXEnTextura;
	int posicionYEnTextura;

public:
	//Constructores y destructores
	//Pacman(SDL_Renderer* _renderer, SDL_Texture* _pacmanTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Pacman(Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Pacman();

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
	// Renderizar imagen pacman
	void rendere();
	void updatee();

};

