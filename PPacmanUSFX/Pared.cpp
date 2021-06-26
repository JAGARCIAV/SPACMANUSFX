#include "Pared.h"

Pared::Pared(Tile* _tile, Texture* _textura) :
	GameActor(_textura) {
	//tipoTexturaPared = TEXTURA_UNO;
	//setTexture(tipoTexturaPared);
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
};

void Pared::setTileActual(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

};

void Pared::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPared(nullptr);
}
