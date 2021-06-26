#pragma once
#include "Tile.h"
#include "Pared.h"
#include "Pacman.h"

class ParedAsesino : public Pared
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
    ParedAsesino(bool _isElectrica, int tipo, Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
    void update();
};
