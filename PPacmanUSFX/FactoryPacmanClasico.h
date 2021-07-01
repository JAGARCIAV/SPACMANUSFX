#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "MsPacmanClasico.h"
#include "FantasmaClasico.h"
#include "FrutaClasico.h"
#include "ParedClasico.h"
#include "MonedaClasico.h"
#include "SuperMonedaClasico.h"
#include "GameActor.h"
#include "GameObject.h"


class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createMsPacmanInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma1Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma2Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma3Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma4Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createSuperMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;

};

