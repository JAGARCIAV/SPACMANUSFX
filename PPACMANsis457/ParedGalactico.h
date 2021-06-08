#pragma once
#include "GameObject.h"
#include "Tile.h"
class ParedGalactico :
    public GameObject
{
public:
    ParedGalactico(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
};

