#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron) {
    return new Pacman(_tile, _texturaPacman, _posicionX, _posicionY,  _velocidadPatron);
}

GameObject* FactoryPacmanClasico::createFantasmaInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron) {
    return new Fantasma(_tile, _texturaPacman, _posicionX, _posicionY,  _velocidadPatron);
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY) {
    return new Fruta(_tile, _frutaTextura, _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY) {
    return new Pared(_tile,_paredTextura, _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createMonedaInstace(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) {
    return new Moneda(_tile, _monedaTextura, _posicionX, _posicionY);
}