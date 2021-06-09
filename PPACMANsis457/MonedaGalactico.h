#pragma once
#include "GameObject.h"
#include "Tile.h"
class MonedaGalactico :
    public GameObject
{
public:
    MonedaGalactico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);

};

