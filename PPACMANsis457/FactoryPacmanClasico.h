#pragma once
#include "Factory.h"
#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Pared.h"
#include "Moneda.h"

class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) override;

    GameObject* createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)override;

    GameObject* createParedInstance(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla)override;

    GameObject* createFrutaInstance(Tile* _tile, Texture* _frutasTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla)override;

    GameObject* createMonedaInstace(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla)override;

};

