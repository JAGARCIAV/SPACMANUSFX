#pragma once
#include "Tile.h"
#include "Pared.h"
#include "Pacman.h"

class ParedGalactico :  public Pared
{
private:
    int velocidadPacman;
    bool isElectrica;
    Tile* tileActual;
    bool isGalactico;
    int state;
    int cont1 = 50;
    int cont2 = 100;
    const int electricTime = 50;
    const int notElectricTime = 100;
public:
     ParedGalactico(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, bool _isElectrica);
     void update();
};

