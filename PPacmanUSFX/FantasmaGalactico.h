#pragma once
#include "Fantasma.h"
class FantasmaGalactico :
    public Fantasma
{
protected:

    Tile* tileActual;

    Tile* tileSiguiente;
    

public:

    FantasmaGalactico(Tile* _tile, Texture* _fantasmaGalacticoTextura);
    Tile* getTile() { return tileActual; }
    Tile* getTileSiguiente() { return tileSiguiente; }
    void setTile(Tile* _tileNuevo);
    void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

    void update() override;
   // Fantasma* clone();
};
