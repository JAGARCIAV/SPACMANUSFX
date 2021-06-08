#pragma once
#include "Factory.h"
#include "PacmanGalactico.h"
#include "FantasmaGalactico.h"
#include "ParedGalactico.h"
#include "FrutaGalactico.h"
#include "MonedaGalactico.h"
#include "Tile.h"

class FactoryPacmanGalactico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) {
        return new PacmanGalactico(_tile, _texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _velocidadPatron);
    }


    GameObject* createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron){
        return new FantasmaGalactico(_tile,_texturaFantasma, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _velocidadPatron);
    }

    GameObject* createParedInstance(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
        return new ParedGalactico(_tile, _paredTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);
    }

    GameObject* createFrutaInstance(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
        return new FrutaGalactico(_tile, _frutaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);

    }

    GameObject* createMonedaInstance(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
        return new MonedaGalactico(_tile, _monedaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);
    }

};

