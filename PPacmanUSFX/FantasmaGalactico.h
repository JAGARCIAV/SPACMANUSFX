#pragma once
#include "Fantasma.h"
class FantasmaGalactico :
    public Fantasma
{
protected:

    Tile* tileActual;

    Tile* tileSiguiente;
    

public:

    FantasmaGalactico(Tile* _tile, Texture* _fantasmaGalacticoTextura, int _posicionX, int _posicionY, int _velocidadPatron);
    Tile* getTile() { return tileActual; }
    Tile* getTileSiguiente() { return tileSiguiente; }
    void setTile(Tile* _tileNuevo);
    void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

    void update() override;
    Fantasma* clone();
};
