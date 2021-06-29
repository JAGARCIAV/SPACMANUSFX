#include "PacmanClasico.h"
#include <stdio.h>

PacmanClasico::PacmanClasico(Tile* _tile, Texture* _texturaPacmanClasico) :
	Pacman(_tile, _texturaPacmanClasico)
{

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}


	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;


	// Inicializa propiedade de de pacman
	//velocidad = _velocidad;
	vida = 10;
}



//DESTRUCTOR y deja un espacio libre 
PacmanClasico::~PacmanClasico()
{
	//Free();
}
