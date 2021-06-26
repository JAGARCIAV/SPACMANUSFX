#pragma once
#include "Pared.h"
#include "Wall.h"

class ParedClasicoAdapter :
    public Pared, private Wall
{
public:
    ParedClasicoAdapter(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
    
    void render() override { Wall::Render(); }
    
};

