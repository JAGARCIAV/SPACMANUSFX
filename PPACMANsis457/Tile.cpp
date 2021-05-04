#include "Tile.h"



Tile::Tile() {
	anchoTile = 25;
	altoTile = 25;
	posicionX = 0;
	posicionY = 0;
	
	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
	bruja = nullptr;

}

Tile::Tile(int _x, int _y) {
	posicion.x = _x;
	posicion.y = _y;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

void Tile::setPosicion(int _x, int _y) {
	posicion.x = _x;
	posicion.y = _y;
}