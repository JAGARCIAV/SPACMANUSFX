#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"
#include "TextureManager.h"
#include "Texture.h"

using namespace std;

class Fantasma : public GameObject {
	//class Fantasma : public GameTexture {

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

		int numeroFrame;
		int contadorFrames;

		const int framesMovimiento = 4;

		//// Renderizador de la ventana
		//SDL_Renderer* renderer = nullptr;

		//// Textura de la grafica del fantasma
		//SDL_Texture* fantasmaTexture = nullptr;

	public:
		//Constructores y destructores
		//Fantasma(SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
		Fantasma(string path, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
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

		// Actualizar datos fantasma
		void update() override;
	//};
};