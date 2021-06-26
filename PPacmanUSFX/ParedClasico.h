#pragma once

#include "Tile.h"
#include "Pared.h"
class ParedClasico :
	public Pared
{
private:
	const int timeColor = 100;
	int cont;
	int tiempoVisible;
	int tiempoNoVisible;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
public:
	ParedClasico(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
	void update();

};

