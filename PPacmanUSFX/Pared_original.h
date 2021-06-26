#pragma once
#include "GameObject.h"
#include "MazeObject.h"
#include "TileGraph.h"

class Pared :
    public GameObject
{
private:
    Tile* tileActual;

public:
    Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
};

