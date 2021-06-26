#include "FantasmaClasico.h"

FantasmaClasico::FantasmaClasico(Tile* _tile, Texture* _fantasmaClasicoTextura, int _posicionX, int _posicionY, int _velocidadPatron) :
	Fantasma(_tile, _fantasmaClasicoTextura, _posicionX, _posicionY, _velocidadPatron)
{

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	tipoFantasma = FANTASMA_CLASICO;
}

Fantasma* FantasmaClasico::clone()
{
	return new FantasmaClasico(*this);
}

//void FantasmaClasico::setTile(Tile* _tileNuevo) {
//	if (tileActual != nullptr)
//		tileActual->setFantasma(nullptr);
//
//	tileActual = _tileNuevo;
//
//	if (tileActual != nullptr) {
//		tileActual->setFantasma(this);
//
//		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
//		posicionY = tileActual->getPosicionY() * Tile::altoTile;
//	}
//};
//
