#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 
#include "Moneda.h"

using namespace std;

class Pacman: public GameObject
{
protected:
	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;
		
	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXEnTextura;
	int posicionYEnTextura;

	TextureAnimation* texturaAnimacion;
	//static Pacman* instancia;

	int energia;
	int state;
	
public:
	Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron);

//	static Pacman* crearInstancia(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Constructores y destructores
	
	//~Pacman();

	//Metodos accesores
	int getState() { return state; }
	void setState(int _state) { state = _state; }


	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	int getEnergia() { return energia; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }
	void setEnergia(int _energia) { energia = _energia; }

	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
	void restarEnergia();

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;
	// Mover pacman
	void update() override;
	// Renderizar imagen pacman
	void render() override;
	//void update();
	void deleteGameObject() override;

};

