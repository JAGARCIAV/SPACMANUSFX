#pragma once
#include "Moneda.h"
class MonedaAsesino :
    public Moneda
{
public:
    MonedaAsesino(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);

};

