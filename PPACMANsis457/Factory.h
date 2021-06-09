#pragma once
#include "GameObject.h"
#include "Tile.h"

class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY,  int _velocidadPatron) = 0;
	virtual GameObject* createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY,  int _velocidadPatron) = 0;
	virtual GameObject* createFrutaInstance(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createParedInstance(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createMonedaInstace(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) = 0;

};


