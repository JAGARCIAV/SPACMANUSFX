#pragma once
#include "GameObject.h"
#include "Tile.h"

class PacmanClasico :
    public GameObject
{
public:
    PacmanClasico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron);

};
