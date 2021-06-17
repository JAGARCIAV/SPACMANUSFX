#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _velocidad) :
	GameObject(_texturaFantasma, _posicionX, _posicionY)
{
	_texturaFantasma = new Texture();
	//texture->setTexture(_texturaPacman);
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
	//collider ancho y alto 
	collider->w = Width;
	collider->h = Height;



	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;




	// Inicializa propiedade de de pacman
	posicionXDestino = getPosicionX();
	posicionYDestino = getPosicionY();


	velocidad = _velocidad;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
}

void Fantasma::setTile(Tile* _tileNuevo) {
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
					if (CheckForCollision(pacman->getColisionador())) {
						pacman->RestarVida();
						cout << "VIDA = " << pacman->getVida() << endl;

						if (pacman->getVida() <= 0) {
							tileActual->setPacman(nullptr);
							pacman->Delete();
						}
					}
				}
			}
		}


		// Depending of the direction of movement, move the NPC accordingly
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

		// Update the collider
		collider->x = posicionX;
		collider->y = posicionY;

		// Check if the NPC has moved to the next tile, if so, change his current tile
		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);

	}
}

void Fantasma::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = textura->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = textura->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = textura->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = textura->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}
	textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}



bool Fantasma::AvoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}
