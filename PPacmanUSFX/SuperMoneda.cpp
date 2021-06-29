#include "SuperMoneda.h"


SuperMoneda::SuperMoneda(Tile* _tile, Texture* _textura) :
	GameActor(_textura)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setSuperMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	colisionador->w = ancho;
	colisionador->h = alto;

	colisionador->x = posicionX;
	colisionador->y = posicionY;


	// Inicializa propiedade de de moneda
	tiempoPoderMoneda = 0;
}



void SuperMoneda::setTileActual(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setSuperMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}

void SuperMoneda::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setSuperMoneda(nullptr);
}
