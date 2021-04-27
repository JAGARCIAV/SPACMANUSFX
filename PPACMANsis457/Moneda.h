#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"



enum PODER_MONEDA {
    PODER_MONEDA_NINGUNO,
    PODER_MONEDA_CRECIMIENTO,
    PODER_MONEDA_COMER,
    PODER_MONEDA_VELOCIDAD,
    PODER_MONEDA_SALTO
};


class Moneda :public GameObject
{
private:
    int valor;
    PODER_MONEDA tipoPoderMoneda;
    int tiempoPoderMoneda;

    Texture* texture;

    //int numeroFrame; //laboratorio N°4
    //int contadorFrames; //laboratorio N°4

    const int framesMovimiento = 2; 


    //public:
    //    // Renderizador de la ventana
    //    SDL_Renderer* renderer = nullptr;
    //
    //    // Textura de la grafica del fantasma
    //    SDL_Texture* monedaTexture = nullptr;

public:
    //Moneda(SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
    Moneda(Texture* _texture, int _posicionX, int _posicionY, int _ancho, int _alto,
        int _anchoPantalla, int _altoPantalla,int _numeroFrame, int _contadorFrames);



    int getValor() { return valor; }
    PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }

    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PODER_MONEDA _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }



    void render();

    void update();

};

