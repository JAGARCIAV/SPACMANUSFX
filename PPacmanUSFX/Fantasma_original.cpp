#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidadPatron) :
	GameObject(_fantasmaTexture, _posicionX, _posicionY)
{
	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	// Inicializa propiedade de de pacman
	posicionXDestino = getPosicionX();
	posicionYDestino = getPosicionY();

	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = _velocidadPatron;
}

void Fantasma::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if(tileActual != nullptr){
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

bool Fantasma::tratarDeMover(MoveDirection _direccionNueva) {
	Tile* tileDestino = nullptr;

	switch (_direccionNueva) {
	case MOVE_UP:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_DOWN:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_LEFT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_RIGHT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
		break;
	}

	if (tileDestino == nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);

	return true;
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
				astar.SetAvoidFunction(Fantasma::AvoidInPathFinder);
				camino = astar.CalculateRoute(tileActual, pacman->getTile());

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
						pacman->restarEnergia();
						if (pacman->getEnergia() <= 0) {
							tileActual->setPacman(nullptr);
							pacman->deleteGameObject();
						}
					}
				}
			}
		}

			// Depending of the direction of movement, move the NPC accordingly
			switch (direccionActual)
			{
			case MOVE_UP:
				posicionY = std::max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
				break;
			case MOVE_DOWN:
				posicionY = std::min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
				break;
			case MOVE_LEFT:
				posicionX = std::max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
				break;
			case MOVE_RIGHT:
				posicionX = std::min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
				break;
			}

			// Update the collider
			colisionador->x = posicionX;
			colisionador->y = posicionY;

			// Check if the NPC has moved to the next tile, if so, change his current tile
			if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
				setTile(tileSiguiente);

			if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
				setTile(tileSiguiente);
		
	}
}

bool Fantasma::AvoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}

