#pragma once
#include <SDL.h>
#include "GameActor.h"
#include "Texture.h"
#include "TileGraph.h"

enum typeFruta {
    TIPO_FRUTA_GUINDA,
    TIPO_FRUTA_FRUTILLA,
    TIPO_FRUTA_NARANJA,
    TIPO_FRUTA_PLATANO,
    TIPO_FRUTA_MANZANA,
    TIPO_FRUTA_MAXIMO
};


class Fruta :
    public GameActor {
protected:
    int valor;
    typeFruta tipoPoderMoneda;
    int tiempoPoderMoneda;
    GameObjectType returType() { return MONEDA; }
public:
    Fruta(Tile* _tile, Texture* _textura);

    int getValor() { return valor; }
    typeFruta getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }

    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(typeFruta _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTileActual(Tile* _tileNuevo);

    void deleteGameObject() override;
    void handleEvent(SDL_Event* event) {};

};

