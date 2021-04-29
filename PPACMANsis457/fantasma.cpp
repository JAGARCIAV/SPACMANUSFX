#include "Fantasma.h"
#include <iostream>

using namespace std;

//Fantasma::Fantasma(string path, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
//	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
//{
//	// Inicializa propiedade de de pacman
//	posicionXDestino = getPosicionX();
//	posicionYDestino = getPosicionY();
//	velocidadX = 1;
//	velocidadY = 1;
//	numeroFrame = 0;
//	contadorFrames = 0;
//	velocidadPatron = _velocidadPatron;
//	fantasmaTexture = new Texture();
//	fantasmaTexture->loadFromImage(path.c_str());
//}


Fantasma::Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_fantasmaTexture, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	posicionXDestino = getPosicionX();
	posicionYDestino = getPosicionY();

	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = _velocidadPatron;
}

void Fantasma::move()
{
	if (incrementoPosicionX > 0) {
		if (getPosicionX() >= posicionXDestino || (getPosicionX() + getAncho()) >= getAnchoPantalla()) {
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			if (getPosicionX() > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else {
				incrementoPosicionX = 1;
			}

		}
		else {
			setPosicionX(getPosicionX() + incrementoPosicionX * velocidadX);
		}
	}
	else {
		if (getPosicionX() <= posicionXDestino || (getPosicionX() <= 0)) {
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			if (getPosicionX() > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else {
				incrementoPosicionX = 1;
			}
		}
		else {
			setPosicionX(getPosicionX() + incrementoPosicionX * velocidadX);
		}
	}

	if (incrementoPosicionY > 0) {
		if (getPosicionY() >= posicionYDestino || (getPosicionY() + getAlto()) >= getAltoPantalla()) {
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (getPosicionY() > posicionYDestino) {
				incrementoPosicionY = -1;
			}
			else {
				incrementoPosicionY = 1;
			}
		}
		else {
			setPosicionY(getPosicionY() + incrementoPosicionY * velocidadY);
		}
	}
	else {
		if (getPosicionY() <= posicionYDestino || (getPosicionY() <= 0)) {
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (getPosicionY() > posicionYDestino) {
				incrementoPosicionY = -1;
			}
			else {
				incrementoPosicionY = 1;
			}
		}
		else {
			setPosicionY(getPosicionY() + incrementoPosicionY * velocidadY);
		}
	}
}

