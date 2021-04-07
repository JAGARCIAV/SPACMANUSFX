#pragma once
#include <SDL.h>

class Ceresa {
private:
	int posicionX;
	int posicionY;
	int tiempo;

	//Velocidad en eje X
	//int velocidadX;

	//Velocidad en el eje Y
	//int velocidadY;

	//Velocidad a la que mueve el seresa en cualquier eje
	//int velocidadPatron;

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

	// Supeerficie grafica del ceresa;
	SDL_Surface* ceresaSurface = nullptr;

public:
	//Constructores y destructores
	Ceresa();
	//~Ceresa();

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	//int getVelocidadX() { return velocidadX; }
	//int getVelocidadY() { return velocidadY; }
	//int getVelocidadPatron() { return velocidadPatron; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	//void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	//void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	//void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }


	// Metodos varios

	// Manejador de eventos del ceresa
	//void handleEvent(SDL_Event& e);

	// Mover ceresa
	void move();
	// Renderizar imagen ceresa
	void render();

};