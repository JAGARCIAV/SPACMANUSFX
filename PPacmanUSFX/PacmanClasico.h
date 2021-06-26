#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "MoveDirection.h"
#include "TextureManager.h" 

using namespace std;

class PacmanClasico :
	public Pacman
{
protected:
	//PROPIEDADES

	int vida;
	int portal;

public:
	//METODOS 

	//Constructores y destructores
	PacmanClasico(Tile* _tile, Texture* _texturaPacmanClasico, int _posicionX, int _posicionY, int _velocidad);
	~PacmanClasico();

	static const int Width = 25;
	static const int Height = 25;


	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);

	////vida del pacman
	//// Manejador de eventos de pacman
	//void handleEvent(SDL_Event* event) {};
	//// Mover pacman
	//void update() {};
	//// Renderizar imagen pacman
	//void render() {};
	////void update();
	//void deleteGameObject() {};

};
