#include "Fruta.h"
#include "Tile.h"

#include <iostream>

using namespace std;

Fruta::Fruta(Texture* _frutaTextura, int _posicionX, int _posicionY) :
	GameObject(_frutaTextura, _posicionX, _posicionY){
	// Inicializa propiedade de la fruta
	tipoFruta = TIPO_FRUTA_GUINDA;

	ancho = Tile::anchoTile;
	alto = Tile::altoTile;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	int numeroFrutaVisible = 0;
}


void Fruta::update()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % tileGraph->anchoPantalla;
			posicionY = 1 + rand() % tileGraph->altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
			numeroFrutaVisible = rand() % 4;
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}