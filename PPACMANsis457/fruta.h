#pragma once
#include <SDL.h>

#include "GameObject.h"

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_MANZANA
};


class Fruta : public GameObject
{
private:
	int R;
	TIPO_FRUTA tipoFruta;

	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

public:
	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// Array de las texturas de las diferentes frutas;
	SDL_Texture* frutasTextures[3];


public:
	//Constructores y destructores
	Fruta(SDL_Renderer* _renderer, SDL_Texture* _frutasTextures[3], int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	//~Fruta();

	//Metodos accesores

	TIPO_FRUTA getTipoFruta() { return tipoFruta; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }

	void setTipoFruta(TIPO_FRUTA _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	void render();

};


