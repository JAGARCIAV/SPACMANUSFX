#pragma once
#include "Pared.h"
#include "Wall.h"

class ParedAdapter :
    public Pared, private Wall
{
public:
    ParedAdapter(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);

    void render() override { Wall::Render(); }

};

