#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "Pacman.h"
#include "Fantasma.h"

#include "MoveDirection.h"
#include "TextureManager.h" 
#include "PathFinder.h"



using namespace std;

class Poder : public GameObject
{
private:
	//PROPIEDADES

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el Poder en cualquier eje
	int velocidadPatron;

	int posicionXDestino;
	int posicionYDestino;

	int incrementoPosicionX;
	int incrementoPosicionY;

	int posicionXEnTextura;
	int posicionYEnTextura;

	vector<Tile*> camino;

public:
	//Constructores y destructores
	Poder(Tile* _tile, Texture* _texturaPoder, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	~Poder();

	static const int Width = 25;
	static const int Height = 25;

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
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
	void Delete() override;

	// Devuelve la ficha de pacman
	Tile* GetTile();

	static bool AvoidInPathFinder(Tile* _tile);
};

