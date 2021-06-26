#pragma once
#include <SDL.h>
#include "GameActor.h"
#include "Texture.h"
#include "TileGraph.h"

enum PoderMoneda {
    PODER_MONEDA_NINGUNO,
    PODER_MONEDA_CRECIMIENTO,
    PODER_MONEDA_COMER,
    PODER_MONEDA_VELOCIDAD,
    PODER_MONEDA_SALTO
};


class Moneda :
    public GameActor{
protected:
    int valor;
    PoderMoneda tipoPoderMoneda;
    int tiempoPoderMoneda;
    GameObjectType returType() { return MONEDA; }
public:
    Moneda(Tile* _tile, Texture* _textura);

    int getValor() { return valor; }
    PoderMoneda getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
   
    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PoderMoneda _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTileActual(Tile* _tileNuevo);

    void deleteGameObject() override;
    void handleEvent(SDL_Event* event){};

};

