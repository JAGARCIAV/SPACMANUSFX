#pragma once
#include "Tile.h"
#include "Pared.h"
#include "Pacman.h"

class ParedAsesino : public Pared
{

public:
    ParedAsesino(bool _isElectrica, int tipo, Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
   
};
