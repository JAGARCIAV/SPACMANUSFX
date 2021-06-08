#pragma once
#include "GameObject.h"
#include "Tile.h"

class PacmanGalactico :
    public GameObject
{
public:
    PacmanGalactico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

};

