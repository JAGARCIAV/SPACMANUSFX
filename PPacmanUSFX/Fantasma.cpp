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

//void Fantasma::reconfigurar(Tile* _tile, int _posicionX, int _posicionY, int _velocidad) 
//{
//	/*framesAnimacion = new TextureAnimation();
//	framesAnimacion->setTexture(_fantasmaTexture);
//	framesAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
//	framesAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));*/
//
//	tileActual = _tile;
//	tileSiguiente = nullptr;
//
//	if (tileActual != nullptr) {
//		tileActual->setFantasma(this);
//		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());
//
//		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
//		posicionY = tileActual->getPosicionY() * Tile::altoTile;
//	}
//	else {
//		posicionX = 0;
//		posicionY = 0;
//	}
//
//	colisionador->w = ancho;
//	colisionador->h = alto;
//
//	direccionActual = MOVE_RIGHT;
//	direccionSiguiente = MOVE_RIGHT;
//
//	// Inicializa propiedade de de pacman
//
//	velocidad = _velocidad;
//}



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

//bool Fantasma::tratarDeMover(MoveDirection _direccionNueva) {
//	Tile* tileDestino = nullptr;
//
//	switch (_direccionNueva) {
//	case MOVE_UP:
//		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
//		break;
//	case MOVE_DOWN:
//		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
//		break;
//	case MOVE_LEFT:
//		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
//		break;
//	case MOVE_RIGHT:
//		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
//		break;
//	}
//
//	if (tileDestino == nullptr) {
//		setTileSiguiente(nullptr);
//		return false;
//	}
//
//	if (tileDestino->getPared() != nullptr) {
//		setTileSiguiente(nullptr);
//		return false;
//	}
//
//	setTileSiguiente(tileDestino);
//
//	return true;
//}

void Fantasma::update()
{
	Pacman* pacman = tileGraph->getPacman();

	if (pacman != nullptr) {

		// en este punto seguira a pacman
		if (tileActual == tileSiguiente ) {
			// cnsigue el camino para seguir a pacman
			PathFinder astar(tileGraph);
			astar.SetAvoidFunction(Fantasma::avoidInPathFinder);
			camino = astar.CalculateRoute(tileActual, pacman->getTileActual());

			if (camino.size() > 1) {
				tileSiguiente = camino[1];
			}
			// Lo que se desea despues es ver el NPC deberia ir
			if (posicionX < tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_RIGHT;

			else if (posicionX > tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_LEFT;

			else if (posicionY > tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_UP;

			else if (posicionY < tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_DOWN;

			// Revisa si fantasma colisiono con pacman, por tanto pacman es eliminado
			if (revisarColision(pacman->getColisionador())) {
				pacman->restarEnergia();
				if (pacman->getEnergia() <= 0) {
					tileActual->setPacman(nullptr);
					pacman->deleteGameObject();
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

