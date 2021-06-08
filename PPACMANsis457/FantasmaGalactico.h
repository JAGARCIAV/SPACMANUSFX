#pragma once
#include "GameObject.h"
#include "Tile.h"
class FantasmaGalactico :
    public GameObject
{
public:
    FantasmaGalactico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

};


