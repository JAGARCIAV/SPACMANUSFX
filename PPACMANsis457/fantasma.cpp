#include "Fantasma.h"
#include <iostream>

using namespace std;




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

//void Fantasma::move()
//{
//	if (incrementoPosicionX > 0) {
//		if (getPosicionX() >= posicionXDestino || (getPosicionX() + getAncho()) >= getAnchoPantalla()) {
//			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
//			if (getPosicionX() > posicionXDestino) {
//				incrementoPosicionX = -1;
//			}
//			else {
//				incrementoPosicionX = 1;
//			}
//
//		}
//		else {
//			setPosicionX(getPosicionX() + incrementoPosicionX * velocidadX);
//		}
//	}
//	else {
//		if (getPosicionX() <= posicionXDestino || (getPosicionX() <= 0)) {
//			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
//			if (getPosicionX() > posicionXDestino) {
//				incrementoPosicionX = -1;
//			}
//			else {
//				incrementoPosicionX = 1;
//			}
//		}
//		else {
//			setPosicionX(getPosicionX() + incrementoPosicionX * velocidadX);
//		}
//	}
//
//	if (incrementoPosicionY > 0) {
//		if (getPosicionY() >= posicionYDestino || (getPosicionY() + getAlto()) >= getAltoPantalla()) {
//			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
//			if (getPosicionY() > posicionYDestino) {
//				incrementoPosicionY = -1;
//			}
//			else {
//				incrementoPosicionY = 1;
//			}
//		}
//		else {
//			setPosicionY(getPosicionY() + incrementoPosicionY * velocidadY);
//		}
//	}
//	else {
//		if (getPosicionY() <= posicionYDestino || (getPosicionY() <= 0)) {
//			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
//			if (getPosicionY() > posicionYDestino) {
//				incrementoPosicionY = -1;
//			}
//			else {
//				incrementoPosicionY = 1;
//			}
//		}
//		else {
//			setPosicionY(getPosicionY() + incrementoPosicionY * velocidadY);
//		}
//	}
//}
//

void Fantasma::move()
{
	incrementoX += velocidadPatron * velocidadX;
	setPosicionX(incrementoX);
	incrementoY += velocidadPatron * velocidadY;
	setPosicionY(incrementoY);
	if (velocidadX == 1) {
		if (incrementoX + ancho >= posicionXDestino) {
			velocidadX = 0;
			if (incrementoY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	else if (velocidadX == -1) {
		if (incrementoX <= posicionXDestino) {
			velocidadX = 0;
			if (incrementoY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	if (velocidadY == 1) {
		if (incrementoY + alto >= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (posicionXDestino != incrementoX) {
				velocidadX = (posicionXDestino - incrementoX) / abs(posicionXDestino - incrementoX);
			}
			else {
				velocidadX = 1;
			}
		}
	}
	else if (velocidadY == -1) {
		if (incrementoY <= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (posicionYDestino != incrementoY) {
				velocidadY = (posicionYDestino - incrementoY) / abs(posicionYDestino - incrementoY);
			}
			else {
				velocidadY = 1;
			}
		}
	}
	if ((incrementoX < 0) || (incrementoX + getAncho()) >= getAnchoPantalla()) {
		velocidadX *= -1;
	}

	if ((incrementoY < 0) || (incrementoY + getAlto()) >= getAltoPantalla()) {
		velocidadY *= -1;
	}
}