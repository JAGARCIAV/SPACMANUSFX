#pragma once
#include "GameObject.h"
#include "Tile.h"
class FrutaGalactico :
    public GameObject
{
public:
    FrutaGalactico(Tile* _tile, Texture* _frutasTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

};




