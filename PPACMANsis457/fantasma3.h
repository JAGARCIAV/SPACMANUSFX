#pragma once
#include <SDL.h>

class Fantasma3 {
public:

	int xi;
	int xf;
	int yi;
	int yf;

	int posicionX;
	int posicionY;

	//Velocidad en eje X
	int velocidadX;

	//Velocidad en el eje Y
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;
public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	SDL_Surface* fantasma3Surface = nullptr;

public:
	//Constructores y destructores
	Fantasma3();
	//~Fantasma();

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }

	int getXi() { return xi; }
	int getYi() { return yi; }
	int getXf() { return xf; }
	int getYf() { return yf; }



	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }

	void setXi(int _xi) { xi = _xi; }
	void setYi(int _yi) { yi = _yi; }
	void setXf(int _xf) { xf = _xf; }
	void setYf(int _yf) { yf = _yf; }


	// Mover fantasma2
	void move();
	// Renderizar imagen fantasma
	void render();

};