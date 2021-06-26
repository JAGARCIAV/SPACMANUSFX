#pragma once
#include "Fantasma.h"
class FantasmaClasico :
    public Fantasma
{

protected:

    /*Tile* tileActual;
    Tile* tileSiguiente;*/

public:

    FantasmaClasico(Tile* _tile, Texture* _fantasmaClasicoTextura, int _posicionX, int _posicionY, int _velocidadPatron);
    /*Tile* getTile() { return tileActual; }
    Tile* getTileSiguiente() { return tileSiguiente; }*/
    //void setTile(Tile* _tileNuevo);
    //void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }
    void update() { Fantasma::update(); }

    
    Fantasma* clone();

};

