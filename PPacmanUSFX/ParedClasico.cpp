#include "ParedClasico.h"

ParedClasico::ParedClasico(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY)
	:Pared(_tile, _paredTextura, _posicionX, _posicionY)
{
	tipoTexturaPared = 17;
	tiempoVisible = 0;
	tiempoNoVisible = 0;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	cont = 0;
}

void ParedClasico::update() {

	if (cont >= timeColor) {
		int color = 17 + rand() % (22 - 17);
		setTexture(color);
		cont = 0;
	}
	else
		cont++;
}