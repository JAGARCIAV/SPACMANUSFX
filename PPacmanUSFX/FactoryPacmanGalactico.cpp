#include "FactoryPacmanGalactico.h"

GameObject* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager) {
    return new PacmanGalactico(_tile, _textureManager->getTextura("pacman_galactico"));
}

GameObject* FactoryPacmanGalactico::createFantasma1Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaGalactico(_tile, _textureManager->getTextura("fantasma_galactico1"));
}

GameObject* FactoryPacmanGalactico::createFantasma2Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaGalactico(_tile, _textureManager->getTextura("fantasma_galactico2"));
}

GameObject* FactoryPacmanGalactico::createFantasma3Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaGalactico(_tile, _textureManager->getTextura("fantasma_galactico3"));
}

GameObject* FactoryPacmanGalactico::createFantasma4Instance(Tile* _tile, TextureManager* _textureManager) {
    return new FantasmaGalactico(_tile, _textureManager->getTextura("fantasma_galactico4"));
}

GameObject* FactoryPacmanGalactico::createParedInstance(Tile* _tile, TextureManager* _textureManager) {
    return new ParedGalactico(_tile, _textureManager->getTextura("pared_galactico"));
}

GameObject* FactoryPacmanGalactico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new FrutaGalactico(_tile, _textureManager->getTextura("fruta_galactico"));
}

GameObject* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaGalactico(_tile, _textureManager->getTextura("moneda_galactico"));
}
