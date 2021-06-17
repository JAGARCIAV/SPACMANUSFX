#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "FantasmaClasico.h"
#include "FrutaClasico.h"
#include "ParedClasico.h"
#include "ParedAdapter.h"

#include "MonedaClasico.h"


class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasma1Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasma2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasma3Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasma4Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) override;
    GameObject* createMoneda2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) override;

};

