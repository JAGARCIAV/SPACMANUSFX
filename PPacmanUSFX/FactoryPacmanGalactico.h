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
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma1Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma2Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma3Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFantasma4Instance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
};

