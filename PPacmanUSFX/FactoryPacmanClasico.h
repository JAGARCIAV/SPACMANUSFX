#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "FantasmaClasico.h"
#include "FrutaClasico.h"
#include "ParedClasico.h"
#include "ParedClasicoAdapter.h"
#include "MonedaClasico.h"

class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma1Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma2Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma3Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma4Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
};

