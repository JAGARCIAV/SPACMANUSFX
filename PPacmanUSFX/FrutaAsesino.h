#pragma once
#include "Fruta.h"
class FrutaAsesino :
    public Fruta
{
private:
    int disminuirPuntosVida;
    int congelaMovimiento;

public:
    FrutaAsesino(Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

    int getDisminuirPuntosVida() { return disminuirPuntosVida; }
    int getCongelaMovimiento() { return congelaMovimiento; }

    void setDisminuirPuntosVida(int _disminuirPuntosVida) { disminuirPuntosVida = _disminuirPuntosVida; }
    void setCongelaMovimiento(int _congelaMovimiento) { congelaMovimiento = _congelaMovimiento; }

    void update() {};
};

