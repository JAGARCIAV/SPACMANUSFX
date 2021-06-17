#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"

#include "PathFinder.h"
#include "Pacman.h"
//ko

using namespace std;

class Fantasma : 
	public GameObject
{
protected:
	//PROPIEDADES

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;



	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidad;

	int posicionXDestino;
	int posicionYDestino;

	int incrementoPosicionX;
	int incrementoPosicionY;

	int posicionXEnTextura;
	int posicionYEnTextura;

	bool tratarDeMover(MoveDirection _direccionNueva);

	vector<Tile*> camino;

public:
	//Constructores y destructores
	Fantasma(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _velocidad);

	//~Fantasma();

	static const int Width = 25;
	static const int Height = 25;

	//Metodos accesores

	int getVelocidad() { return velocidad; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadPatron(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }


	// Metodos varios


	// Manejador de eventos de pacman
	//void handleEvent(SDL_Event* event) override;
	// 
	// Mover pacman
	void update() override;
	// Renderizar imagen pacman
	void render() override;

	// Marque el objeto a eliminar
	//void Delete() override;

	// Devuelve la ficha de pacman
	//Tile* GetTile();

	static bool AvoidInPathFinder(Tile* _tile);
};
