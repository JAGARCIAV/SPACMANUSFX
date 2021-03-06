#include "FactoryPacmanClasico.h"



GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager) {
    //GameObject* objetoNuevo = nullptr;
    //((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("pacman_clasico"));
    //((GameActor*)objetoNuevo)->setFramesDireccion(2);
    return new PacmanClasico(_tile, _textureManager->getTextura("pacman_clasico"));
}

GameObject* FactoryPacmanClasico::createMsPacmanInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MsPacmanClasico(_tile, _textureManager->getTextura("mspacman_clasico"));
}

GameObject* FactoryPacmanClasico::createFantasma1Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaClasico(_tile, _textureManager->getTextura("fantasma_clasico1"));
}

GameObject* FactoryPacmanClasico::createFantasma2Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaClasico(_tile, _textureManager->getTextura("fantasma_clasico2"));
}

GameObject* FactoryPacmanClasico::createFantasma3Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaClasico(_tile, _textureManager->getTextura("fantasma_clasico3"));
}

GameObject* FactoryPacmanClasico::createFantasma4Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaClasico(_tile, _textureManager->getTextura("fantasma_clasico4"));
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _textureManager) {
    return new ParedClasico(_tile, _textureManager->getTextura("pared_clasico"));
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new FrutaClasico(_tile, _textureManager->getTextura("fruta_clasico"));
}

GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaClasico(_tile, _textureManager->getTextura("moneda_clasico"));
}

GameObject* FactoryPacmanClasico::createSuperMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new SuperMonedaClasico(_tile, _textureManager->getTextura("supermoneda_clasico"));
}