#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new PacmanClasico(_tile, _textureManager->getTexture("pacman_clasico"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasma1Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaClasico(_tile, _textureManager->getTexture("fantasma_clasico1"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasma2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaClasico(_tile, _textureManager->getTexture("fantasma_clasico2"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasma3Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaClasico(_tile, _textureManager->getTexture("fantasma_clasico3"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasma4Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaClasico(_tile, _textureManager->getTexture("fantasma_clasico4"), _posicionX, _posicionY, _velocidad);
}

//GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) {
//    return new ParedClasico(_tile, _textureManager->getTexture("pared_clasico"), _posicionX, _posicionY);
//}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) {
    return ((Pared*)new ParedAdapter(_tile, _textureManager->getTexture("pared_clasico_adapter"), _posicionX, _posicionY));
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new FrutaClasico(_tile, _textureManager->getTexture("fruta_clasico"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new MonedaClasico(_tile, _textureManager->getTexture("moneda_clasico"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createMoneda2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new MonedaClasico(_tile, _textureManager->getTexture("supermoneda_clasico"), _posicionX, _posicionY);
}