#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"


class Fantasma : public GameObject {
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

	Texture* fantasmaTexture = nullptr;

	int numeroAnimacion;

	// Renderizador de la ventana
	//SDL_Renderer* renderer = nullptr;

	// Textura de la grafica del fantasma
	//SDL_Texture* fantasmaTexture = nullptr;

public:
	//Constructores y destructores
	
	//Fantasma(SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	// Metodos varios

	// Manejador de eventos del fantasma
	//void handleEvent(SDL_Event& e);

	// Mover fantasma
	void move();
	// Renderizar imagen fantasma
	void render() override;

};