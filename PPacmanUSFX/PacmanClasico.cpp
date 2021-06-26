#include "PacmanClasico.h"

//PacmanClasico::PacmanClasico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron)
//	:GameObject(_texturaPacman, _posicionX, _posicionY)
//{
//}

#include <stdio.h>
//#include "Pacman.h"
PacmanClasico::PacmanClasico(Tile* _tile, Texture* _texturaPacmanClasico, int _posicionX, int _posicionY, int _velocidad) :
	Pacman(_tile, _texturaPacmanClasico, _posicionX, _posicionY, _velocidad)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_texturaPacmanClasico);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));


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


	//Colisionador ancho y alto 
	//collider->w = Width;
	//collider->h = Height;

	////colisionador posicionX
	//collider->x = posicionX;

	////colisionador posicionY
	//collider->y = posicionY;

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;


	// Inicializa propiedade de de pacman
	velocidad = _velocidad;
	vida = 10;
}



//DESTRUCTOR y deja un espacio libre 
PacmanClasico::~PacmanClasico()
{
	//Free();
}

bool PacmanClasico::tratarDeMover(MoveDirection _direccionNueva)
{
	return false;
}

