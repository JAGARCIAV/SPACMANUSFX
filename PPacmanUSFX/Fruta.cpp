#include "Fruta.h"

Fruta::Fruta(Tile* _tile, Texture* _textura) :
	GameActor(_textura)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);

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


	// Inicializa propiedade de de pacman
	valor = 1;

	tiempoPoderMoneda = 0;
}

void Fruta::setTileActual(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setFruta(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}

void Fruta::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setFruta(nullptr);
}
