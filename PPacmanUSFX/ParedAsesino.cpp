#include "ParedAsesino.h"

ParedAsesino::ParedAsesino(bool _isElectrica, int tipo, Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY)
	:Pared(_tile, _paredTextura, _posicionX, _posicionY)
{
	isElectrica = _isElectrica;
	tileActual = _tile;
	isGalactico = true;
	state = 0;
}

void ParedAsesino::update() {
	if (isElectrica) {
		velocidadPacman = 5;
		if (cont2 <= notElectricTime) {
			cont2++;
			if (cont2 >= notElectricTime) {
				cont1 = 0;
				setTexture(11);
				state = 1;
			}
		}
		else {
			if (cont1 <= electricTime) {
				cont1++;
				if (cont1 >= electricTime) {
					cont2 = 0;
					setTexture(10);
					state = 0;
					for (auto tile : tileGraph->get4Vecinos(tileActual)) {
						if (tile != nullptr && tile->getPacman() != nullptr && tile->getPacman()->getState() == 2) {
							tile->getPacman()->setVelocidad(velocidadPacman);
							tile->getPacman()->setState(0);
						}
					}
				}
			}
		}
	}
	if (state == 1) {
		for (auto tile : tileGraph->get4Vecinos(tileActual)) {
			if (tile != nullptr && tile->getPacman() != nullptr) {
				tile->getPacman()->setState(2);
				tile->getPacman()->setVelocidad(0);
			}
		}
	}
}