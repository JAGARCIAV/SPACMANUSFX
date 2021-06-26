#pragma once
#include "Moneda.h"
class MonedaGalactico :
    public Moneda
{
public:
    MonedaGalactico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);
};

