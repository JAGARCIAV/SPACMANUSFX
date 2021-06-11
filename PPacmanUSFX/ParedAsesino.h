#pragma once
#include "Tile.h"
#include "Pared.h"
#include "Pacman.h"

class ParedAsesino : public Pared
{

    const int notElectricTime = 100;
public:
    ParedAsesino(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, bool _isElectrica);

};

