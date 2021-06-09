#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"
#include "TileGraph.h"

enum PODER_MONEDA {
    PODER_MONEDA_NINGUNO,
    PODER_MONEDA_CRECIMIENTO,
    PODER_MONEDA_COMER,
    PODER_MONEDA_VELOCIDAD,
    PODER_MONEDA_SALTO
};


class Moneda :
    public GameObject
{
private:
    int valor;
    PODER_MONEDA tipoPoderMoneda;
    int tiempoPoderMoneda;
    Tile* tileActual;
    int Score;
 

public:
    // Prefixed width and height of a wall
    static const int Width = 25;
    static const int Height = 25;

    static const int Margin = 11;
    Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);
 
    //DESTRUCTOR de moneda
    ~Moneda();

    // Marque el objeto a eliminar
    void Delete()override;


    int getValor() { return valor; }
    PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    Tile* getTile() { return tileActual; }
    int getScore() { return Score; }
 


    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PODER_MONEDA _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTile(Tile* _tileNuevo);
    void setScore(int _Score) { Score = _Score; }



    void ContadorScore();

};

