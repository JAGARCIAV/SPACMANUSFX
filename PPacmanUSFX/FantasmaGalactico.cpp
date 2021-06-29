#include "FantasmaGalactico.h"


FantasmaGalactico::FantasmaGalactico(Tile* _tile, Texture* _fantasmaGalacticoTextura) :

	Fantasma(_tile, _fantasmaGalacticoTextura)


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

	//tipoFantasma = FANTASMA_GALACTICO;

};

//Fantasma* FantasmaGalactico::clone()
//{
//	return new FantasmaGalactico(*this);
//}
