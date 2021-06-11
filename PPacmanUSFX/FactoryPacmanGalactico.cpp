#include "FactoryPacmanGalactico.h"

GameObject* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new PacmanGalactico(_tile, _textureManager->getTexture("pacman_galactico"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanGalactico::createFantasmaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
    return new FantasmaGalactico(_tile, _textureManager->getTexture("fantasma_galactico1"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanGalactico::createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) {
    return new ParedGalactico(_tile, _textureManager->getTexture("pared_galactico"), _posicionX, _posicionY, _isElectric);
}

GameObject* FactoryPacmanGalactico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new FrutaGalactico(_tile, _textureManager->getTexture("fruta_galactico"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
    return new MonedaGalactico(_tile, _textureManager->getTexture("moneda_galactico"), _posicionX, _posicionY);
}
