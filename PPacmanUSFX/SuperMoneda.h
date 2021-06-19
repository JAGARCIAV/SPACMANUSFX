#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"
#include "TileGraph.h"

enum  PODER_SUPERMONEDA {
    PODER_DE_COMER_FANTASMA,
    PODER_DE_VELOCIDAD

};


class SuperMoneda :
    public GameObject
{
private:
    int valor;
   PODER_SUPERMONEDA tipoPoderMoneda;
    int tiempoPoderMoneda;
    Tile* tileActual;
    int Score;


public:
    // Prefixed width and height of a wall
    static const int Width = 25;
    static const int Height = 25;

    static const int Margin = 11;
    SuperMoneda(Tile* _tile, Texture* _superMonedaTextura, int _posicionX, int _posicionY);

    //DESTRUCTOR de moneda
    ~SuperMoneda();

    // Marque el objeto a eliminar
    void Delete()override;


    int getValor() { return valor; }
    PODER_SUPERMONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    Tile* getTile() { return tileActual; }
    int getScore() { return Score; }



    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PODER_SUPERMONEDA _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTile(Tile* _tileNuevo);
    void setScore(int _Score) { Score = _Score; }

    void ContadorScore();

};

