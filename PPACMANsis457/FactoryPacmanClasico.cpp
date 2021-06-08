#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) {
    return new Pacman(_tile, _texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _velocidadPatron);
}

GameObject* FactoryPacmanClasico::createFantasmaInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) {
    return new Fantasma(_tile, _texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _velocidadPatron);
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
    return new Fruta(_tile, _frutaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
    return new Pared(_tile,_paredTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);
}

GameObject* FactoryPacmanClasico::createMonedaInstace(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
    return new Moneda(_tile, _monedaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla);
}