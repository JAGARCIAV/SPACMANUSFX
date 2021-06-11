#pragma once
#include "Fantasma.h"
#include "TileGraph.h"

class FantasmaAsesino :
    public Fantasma
{
private:

    Tile* tileActual;

    Tile* tileSiguiente;


public:

    FantasmaAsesino(Tile* _tile, Texture* _fantasmaAsesinoTextura, int _posicionX, int _posicionY, int _velocidadPatron);
    Tile* getTile() { return tileActual; }
    Tile* getTileSiguiente() { return tileSiguiente; }
    void setTile(Tile* _tileNuevo);
    void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

    void update() override;
};

