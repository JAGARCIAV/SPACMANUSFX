#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _frutaTexture, int _posicionX, int _posicionY) :
	GameObject( _frutaTexture, _posicionX, _posicionY)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	tipoFruta = TIPO_FRUTA_FRUTILLA;
	
	visible = false;
	
	tiempoVisible = 100;
	tiempoInvisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoInvisible = 0;
	int numeroFrutaVisible = 0;
}



