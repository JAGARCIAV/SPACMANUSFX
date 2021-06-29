#include "PacmanGalactico.h"
#include <stdio.h>

PacmanGalactico::PacmanGalactico(Tile* _tile, Texture* _texturaPacmanGalactico) :
	Pacman(_tile, _texturaPacmanGalactico)
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


}

//DESTRUCTOR y deja un espacio libre 
PacmanGalactico::~PacmanGalactico()
{
	//Free();
}