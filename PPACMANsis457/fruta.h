#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "Pacman.h"
#include "TextureManager.h" 

using namespace std;

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_MANZANA,
	TIPO_FRUTA_MAXIMO
};


class Fruta : public GameObject
{
private:
	TIPO_FRUTA tipoFruta;

	int tiempoVisible;
	int tiempoNoVisible;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
	int numeroFrutaVisible;

	Tile* tileActual;

public:

	Texture* FrutaSurface = nullptr;

	static const int Width = 25;
	static const int Height = 25;

	static const int Margin = 11;
	//Constructores y destructores

	Fruta(Tile* _tile, Texture* _frutasTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	~Fruta();

	//Metodos accesores

	TIPO_FRUTA getTipoFruta() { return tipoFruta; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	Tile* getTile() { return tileActual; }

	void setTipoFruta(TIPO_FRUTA _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }
	void setTile(Tile* _tileNuevo);

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	void mostrar();

	// Marque el objeto a eliminar
	void Delete()override;

	// Devuelve la ficha de pacman
	Tile* GetTile();

	//void render();

};






