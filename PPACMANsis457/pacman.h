#pragma once
#include <iostream>
#include <string>

#include <SDL.h>


using namespace std;

class Pacman
{
private:
	// Posicion actual del fantasma en la pantalla
	int posicionX;
	int posicionY;

	// Velocidad en eje X
	int velocidadX;

	// Velocidad en el eje Y
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Superficie grafica de pacman;
	SDL_Surface* pacmanSurface = nullptr;

	// Textura grafica de pacman;
	SDL_Texture* pacmanTexture = nullptr;


public:
	//Constructores y destructores
	Pacman();
	Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla);
	Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Surface* _pacmanSurface);
	Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Surface* _pacmanSurface, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _pacmanTexture, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Pacman();

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

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }

	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
	// Renderizar imagen pacman
	void render();

};

