#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_monedaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	collider.w = ancho;
	collider.h = alto;

	collider.x = posicionX;
	collider.y = posicionY;

	// Inicializa propiedade de de pacman
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;
}

Moneda::~Moneda()
{
	Free();
}

void Moneda::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		collider.x = posicionX;
		collider.y = posicionY;
	}
}


//colisiones
void Moneda::Delete()
{
	// Llamar a la función base
	GameObject::Delete();

	tileActual->setMoneda(nullptr);
}


//Tile* Moneda::getTile()
//{
//	return tileActual;
//}