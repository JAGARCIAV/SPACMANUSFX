#pragma once
#include <SDL.h>
#include "GameActor.h"
#include "Texture.h"
#include "TileGraph.h"

enum PoderSuperMoneda {
    PODER_NINGUNO,
    PODER_CRECIMIENTO,
    PODER_COMER,
    PODER_VELOCIDAD,
    PODER_SALTO
};


class SuperMoneda :
    public GameActor {
protected:
    int valor;
    //int Score;


    PoderSuperMoneda tipoPoderMoneda;
    int tiempoPoderMoneda;
    GameObjectType returType() { return MONEDA; }
public:
    SuperMoneda(Tile* _tile, Texture* _textura);

    int getValor() { return valor; }
    PoderSuperMoneda getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    // int getScore() { return Score; }


    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PoderSuperMoneda _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTileActual(Tile* _tileNuevo);
    // void setScore(int _Score) { Score = _Score; }

    // void ContadorScore();
    void deleteGameObject() override;
    void handleEvent(SDL_Event* event) {};

};
