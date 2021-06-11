#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "Tile.h"
#include "GameObject.h"
#include "TileGraph.h"

using namespace std;

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_MANZANA,
	TIPO_FRUTA_MAXIMO
};


class Fruta: public GameObject
{
private:
	TIPO_FRUTA tipoFruta;
	
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
	int numeroFrutaVisible;

public:
	//Constructores y destructores
	Fruta(Texture* _frutaTextura, int _posicionX, int _posicionY);
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
	void update();
	// Renderizar imagen fruta
	//void render();

};

