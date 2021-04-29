#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"

class Pared :
    public GameObject
{
private:
    int valor;
    //Texture* paredTexture;

public:
    Pared(Texture* _paredTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

    int getValor() { return valor; }

    void setValor(int _valor) { valor = _valor; }

};

