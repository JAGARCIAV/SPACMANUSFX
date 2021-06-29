#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTexture) :
	GameActor(_fantasmaTexture)
{
	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	colisionador->w = ancho;
	colisionador->h = alto;

	direccionActual = MOVE_STILL;
	direccionSiguiente = MOVE_STILL;

	// Inicializa propiedade de de pacman

	velocidad = 5;
}





void Fantasma::setTileActual(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}



void Fantasma::update()
{
	Pacman* pacman = tileGraph->getPacman();

	if (pacman != nullptr) {

		// The NPC will calculate a new camino every time it has entered a new tile
		// In this way, it will dynamically follow Pacman
		if (tileActual == tileSiguiente) {
			// Get a camino to Pacman using A* algorithm
			if (tileGraph->getPacman() != nullptr) {
				PathFinder astar(tileGraph);
				astar.SetAvoidFunction(Fantasma::avoidInPathFinder);
				camino = astar.CalculateRoute(tileActual, pacman->getTileActual());

				if (camino.size() > 1) {
					tileSiguiente = camino[1];

					// All we really want to do after this is check the direction the NPC should go
					if (posicionX < tileSiguiente->getPosicionX() * Tile::anchoTile)
						direccionActual = MOVE_RIGHT;

					else if (posicionX > tileSiguiente->getPosicionX() * Tile::anchoTile)
						direccionActual = MOVE_LEFT;

					else if (posicionY > tileSiguiente->getPosicionY() * Tile::anchoTile)
						direccionActual = MOVE_UP;

					else if (posicionY < tileSiguiente->getPosicionY() * Tile::anchoTile)
						direccionActual = MOVE_DOWN;

					// Check if Fantasma collides with Pacman, if so delete Pacman
					// TODO: There should be a Kill() method within Pacman, which will play death animation
					if (revisarColision(pacman->getColisionador())) {
						pacman->restarVidas();
						cout << "VIDA = " << pacman->getVidas() << endl;

						if (pacman->getVidas() <= 0) {
							tileActual->setPacman(nullptr);
							pacman->deleteGameObject();
						}
					}
				}
			}
		}

		// Dependiendo a la direccion de movimiento, mueve el NPC cordinadamente
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		// Actualizar la colision
		colisionador->x = posicionX;
		colisionador->y = posicionY;
		/*setTile(tileSiguiente);*/

		// Revisa si el NPC se movio al siguiente tile, si es asi cambia su direccion
		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
}


void Fantasma::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}

	textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}


bool Fantasma::hasPositionChanged(SDL_Point firstPos, SDL_Point secondPoint)
{
	if (firstPos.x != secondPoint.x || firstPos.y != secondPoint.y) {
		return true;
	}

	return false;
}

bool Fantasma::avoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr) {

		return true;
	}

	return false;
}

void Fantasma::deleteGameObject()
{
	// Calling the base function
	GameObject::deleteGameObject();
	tileActual->setFantasma(nullptr);
}

