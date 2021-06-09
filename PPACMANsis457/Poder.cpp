

#include <stdio.h>
#include "Poder.h"
Poder::Poder(Tile* _tile, Texture* _texturaPoder, int _posicionX, int _posicionY, int _velocidadPatron) :
	GameObject(_texturaPoder, _posicionX, _posicionY)
{
	_texturaPoder = new Texture();
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
		tileActual->setPoder(this);

		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());


		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	//Colisionador ancho y alto 
	collider->w = Width;
	collider->h = Height;



	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;




	// Inicializa propiedade de de pacman
	posicionXDestino = getPosicionX();
	posicionYDestino = getPosicionY();

	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
}

//DESTRUCTOR y deja un espacio libre 
Poder::~Poder()
{
	Free();
}

void Poder::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPoder(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPoder(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}







void Poder::update()
{

	//IA
	//Pacman* pacman = tileGraph->getPacman();
	Fantasma* fantasma = tileGraph->getFantasma();

	// Compruebe si hay colisión con el punto

	if (fantasma != nullptr) {

		if (tileActual == tileSiguiente) {
			// Get a camino to Pacman using A* algorithm
			PathFinder astar(tileGraph);
			astar.SetAvoidFunction(Poder::AvoidInPathFinder);
			camino = astar.CalculateRoute(tileActual, fantasma->getTile());

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

			// Check if Poder collides with Pacman, if so delete Pacman
			// TODO: There should be a Kill() method within Pacman, which will play death animation
			for (auto tile : tileGraph->get4Vecinos(tileActual)) {

				if (tile->getFantasma() != nullptr && CheckForCollision(tile->getFantasma()->GetCollider())) {
					tile->getFantasma()->Delete();
					cout << "MUERTE Fantasma " << endl;
				}

			}

		}






		////IA

		switch (direccionActual) {
		case MOVE_UP:
			posicionY = max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && getPosicionY() == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && getPosicionX() == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);

	}


}

void Poder::render()
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

bool Poder::AvoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}

//BORRAR 
void Poder::Delete()
{
	// Llamar a la función base
	GameObject::Delete();

	tileActual->setPoder(nullptr);
}
