#include <stdio.h>
#include "Pacman.h"
Pacman::Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron) :
	GameObject(_texturaPacman, _posicionX, _posicionY)
{
	//_texturaPacman = new Texture();
	//texture->setTexture(_texturaPacman);
	textura->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	textura->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	textura->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	textura->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	textura->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	textura->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	textura->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	textura->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));

	textura->addCuadroAnimacion("muerte", new SDL_Rect({ 0, 50, 25, 25 }));
	textura->addCuadroAnimacion("muerte", new SDL_Rect({ 25, 50, 25, 25 }));
	textura->addCuadroAnimacion("muerte", new SDL_Rect({ 50, 50, 25, 25 }));
	textura->addCuadroAnimacion("muerte", new SDL_Rect({ 75, 50, 25, 25 }));


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
	collider->w = Width;
	collider->h = Height;

	//colisionador posicionX
	collider->x = posicionX;

	//colisionador posicionY
	collider->y = posicionY;

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;


	// Inicializa propiedade de de pacman
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
	vida = 10;
}

void Pacman::RestarVida() {
	if (vida>0) {
		vida--;
	}
}



//DESTRUCTOR y deja un espacio libre 
Pacman::~Pacman()
{
	Free();
}

void Pacman::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}


void Pacman::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
		switch (event->key.keysym.sym)
		{
			// Move up
		case SDLK_UP:
		case SDLK_w: direccionSiguiente = MOVE_UP; break;

			// Move down
		case SDLK_DOWN:
		case SDLK_s: direccionSiguiente = MOVE_DOWN; break;

			// Move left
		case SDLK_LEFT:
		case SDLK_a: direccionSiguiente = MOVE_LEFT; break;

			// Move right
		case SDLK_RIGHT:
		case SDLK_d: direccionSiguiente = MOVE_RIGHT; break;
		}
	}
	if (posicionX <= 1) {

		cout << "portal 1" << endl;
		posicionX = 1550;
	}
	else if (posicionX >= 1600) {

		cout << "portal 2" << endl;
		posicionX = 1;

	}
}

bool Pacman::tratarDeMover(MoveDirection _direccionNueva)
{
	Tile* tileDestino = nullptr;

	// Retorna el tile destino dependiendo de la direccion de movimiento

	switch (_direccionNueva)
	{
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

	// Si el tile destino es nullptr, no se puede avanzar ahi
	if (tileDestino == nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	// Si el tile destino es una pared, no se puede avanzar ahi
	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);

	return true;
}






void Pacman::update()
{

	// Compruebe si hay colisión con el punto
	Moneda* moneda = tileGraph->getMoneda();



	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {

		//cout << "Aqui moneda " << endl;
		moneda->ContadorScore();
		cout << "Moneda = " << moneda->getScore() << endl;



		SDL_Rect* eatingHole = new SDL_Rect({
			posicionX ,
			posicionY ,
			ancho,
			alto,
			});

		if (CheckForCollision(eatingHole, tileSiguiente->getMoneda()->GetCollider())) {

			tileSiguiente->getMoneda()->Delete();

		}


	}

	if (tileActual != nullptr && tileActual->getFruta() != nullptr) {

		cout << "Aqui Fruta" << endl;


		SDL_Rect* eatingHole = new SDL_Rect({
			posicionX ,
			posicionY ,
			ancho,
			alto,
			});

		if (CheckForCollision(eatingHole, tileSiguiente->getFruta()->GetCollider())) {
			tileSiguiente->getFruta()->Delete();

		}


	}
	//cout << "X"<<posicionX << endl;
	//cout << "Y" << posicionY << endl;




	// Animacion de pacman

	if (enMovimiento) {
		GameObject::update();
	}

	// Cambiar de tile/direccion
	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;
	}
	else {
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

		collider->x = posicionX;
		collider->y = posicionY;


		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);

		//Rutina para atajo


	}

}



void Pacman::render()
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

//BORRAR 
void Pacman::Delete()
{
	// Llamar a la función base
	GameObject::Delete();

	tileActual->setPacman(nullptr);
}





