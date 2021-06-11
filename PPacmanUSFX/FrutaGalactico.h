#pragma once
#include "Fruta.h"
class FrutaGalactico :
    public Fruta
{
private:
    int disminuirPuntosVida;
    int congelaMovimiento;

public:
    FrutaGalactico(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY);

    int getDisminuirPuntosVida() { return disminuirPuntosVida; }
    int getCongelaMovimiento() { return congelaMovimiento; }

    void setDisminuirPuntosVida(int _disminuirPuntosVida) { disminuirPuntosVida = _disminuirPuntosVida; }
    void setCongelaMovimiento(int _congelaMovimiento) { congelaMovimiento = _congelaMovimiento; }

    void update() override;
};

