#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) :
	GameObject(_monedaTextura, _posicionX, _posicionY)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	//collider ancho
	collider->w = ancho;
	//collider alto
	collider->h = alto;

	//collider posicionX
	collider->x = posicionX;

	//collider posicionY
	collider->y = posicionY;

	// Inicializa propiedade de de pacman
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;
	Score = 0;
}

void Moneda::ContadorScore() {
	if (Score < 200) {
		Score++;
	}
}



//DESTRUCTOR y deja un espacio libre 
Moneda::~Moneda()
{
	free();
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

		collider->x = posicionX;
		collider->y = posicionY;
	}
}


//colisiones
void Moneda::Delete()
{
	// Llamar a la función base
	GameObject::Delete();

	tileActual->setMoneda(nullptr);
}
