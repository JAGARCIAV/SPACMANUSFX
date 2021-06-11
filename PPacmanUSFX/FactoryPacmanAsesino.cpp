#include "FactoryPacmanAsesino.h"


GameObject* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new PacmanAsesino(_tile, _textureManager->getTexture("pacman_asesino"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createFantasma1Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaAsesino(_tile, _textureManager->getTexture("fantasma_asesino1"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createFantasma2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaAsesino(_tile, _textureManager->getTexture("fantasma_asesino2"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createFantasma3Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaAsesino(_tile, _textureManager->getTexture("fantasma_asesino3"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createFantasma4Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaAsesino(_tile, _textureManager->getTexture("fantasma_asesino4"), _posicionX, _posicionY, _velocidad);
}
GameObject* FactoryPacmanAsesino::createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) {
    return new ParedAsesino(_tile, _textureManager->getTexture("pared_asesino"), _posicionX, _posicionY, _isElectric);
}

GameObject* FactoryPacmanAsesino::createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new FrutaAsesino(_tile, _textureManager->getTexture("fruta_asesino"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new MonedaAsesino(_tile, _textureManager->getTexture("moneda_asesino"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanAsesino::createMoneda2Instance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new MonedaAsesino(_tile, _textureManager->getTexture("supermoneda_asesino"), _posicionX, _posicionY);
}