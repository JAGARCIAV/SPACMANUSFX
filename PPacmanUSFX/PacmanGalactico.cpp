#include "PacmanGalactico.h"
//
//PacmanGalactico::PacmanGalactico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron) 
//	:GameObject(_texturaPacman, _posicionX, _posicionY)
//{
//
//
//}

#include <stdio.h>

PacmanGalactico::PacmanGalactico(Tile* _tile, Texture* _texturaPacmanGalactico, int _posicionX, int _posicionY, int _velocidad) :
	Pacman(_tile, _texturaPacmanGalactico, _posicionX, _posicionY, _velocidad)
{
	//texturaAnimacion = new TextureAnimation();
	//texturaAnimacion->setTexture(_texturaPacmanGalactico);
	textura->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	textura->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	textura->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	textura->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	textura->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	textura->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	textura->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	textura->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));


	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}



	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;


}

//DESTRUCTOR y deja un espacio libre 
PacmanGalactico::~PacmanGalactico()
{
	//Free();
}