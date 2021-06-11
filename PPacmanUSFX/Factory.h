#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "TextureManager.h"

class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createFantasma1Instance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createFantasma2Instance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createFantasma3Instance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createFantasma4Instance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createParedInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, bool _isElectric) = 0;
	virtual GameObject* createFrutaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createMonedaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createMoneda2Instance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) = 0;

};

