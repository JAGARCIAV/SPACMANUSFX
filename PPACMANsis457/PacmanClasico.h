#pragma once
#include "Pacman.h"

#include "GameObject.h"
#include "Tile.h"

class PacmanClasico :
    public Pacman
{
public:
    PacmanClasico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron);

};
