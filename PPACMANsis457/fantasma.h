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
#include "MoveDirection.h"
#include "TextureManager.h" 
#include "PathFinder.h"



using namespace std;

class Fantasma : public GameObject
{
private:
	//PROPIEDADES

	//// Compruebe si pacman está colisionando con otro colisionador
	//bool CheckForCollision(const SDL_Rect& otherCollider);

	//// Compruebe si el colisionador dado está colisionando con otro colisionador
	//bool CheckForCollision(const SDL_Rect& collider, const SDL_Rect& otherCollider);
	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

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
	Fantasma(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Fantasma();

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
	//void Delete() override;

	// Devuelve la ficha de pacman
	//Tile* GetTile();

	static bool AvoidInPathFinder(Tile* _tile);
};
