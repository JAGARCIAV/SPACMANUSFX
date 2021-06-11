#pragma once

#include "Pacman.h"
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

class PacmanGalactico :
	public Pacman
{
public:
	//METODOS 

	//Constructores y destructores
	PacmanGalactico(Tile* _tile, Texture* _texturaPacmanClasico, int _posicionX, int _posicionY, int _velocidad);
	~PacmanGalactico();

	static const int Width = 25;
	static const int Height = 25;


	//Metodos accesores



	// Mark the object to be deleted
	//void Delete();
	



	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
};


