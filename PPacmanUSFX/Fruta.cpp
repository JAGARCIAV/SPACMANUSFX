#include "Fruta.h"
#include <iostream>

using namespace std;


Fruta::Fruta(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY) :
	GameObject(_frutaTextura, _posicionX, _posicionY)
{
	visible = false;

	tiempoVisible = 20;
	tiempoNoVisible = 10;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	int numeroFrutaVisible = 0;

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
	//colisionador ancho
	collider->w = ancho;
	//colisionador alto
	collider->h = alto;

	//colisionador posicionX
	collider->x = posicionX;

	//colisionador posicionY
	collider->y = posicionY;



	// Inicializa propiedade de de pacman
	//valor = 1;
	//tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	//tiempoPoderMoneda = 0;
}

void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			//posicionX = 1 + rand() % anchoPantalla;
			//posicionY = 1 + rand() % altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
			//numeroFrutaVisible = rand() % 4;
		}
		else {
			contadorTiempoNoVisible++;
			contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}

}

//DESTRUCTOR y deja un espacio libre 
Fruta::~Fruta()
{
	free();
}

void Fruta::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setFruta(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		collider->x = posicionX;
		collider->y = posicionY;
	}

}

//void Fruta::update()
//{
//	if (contadorTiempoVisible >= tiempoVisible) {
//		visible = false;
//		if (contadorTiempoInvisible >= tiempoInvisible) {
//			posicionX = 1 + rand() % 800;
//			posicionY = 1 + rand() % 600;
//			contadorTiempoVisible = 0;
//			contadorTiempoInvisible = 0;
//			visible = true;
//			//numeroFrutaVisible = rand() % frutasTextures.size();
//			numeroFrutaVisible = rand() % 4;
//		}
//		else {
//			contadorTiempoInvisible++;
//		}
//	}
//	else {
//		contadorTiempoVisible++;
//	}
//}


//colisiones
void Fruta::Delete()
{
	// Llamar a la función base
	GameObject::Delete();

	tileActual->setFruta(nullptr);
}
