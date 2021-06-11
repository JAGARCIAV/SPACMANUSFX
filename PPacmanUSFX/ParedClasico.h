#pragma once

#include "Tile.h"
#include "Pared.h"
class ParedClasico :
	public Pared
{

public:
	ParedClasico(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);

};

