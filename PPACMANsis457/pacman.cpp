#include <stdio.h>
#include "Pacman.h"
Pacman::Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
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
	collider.w = Width;
	collider.h = Height;

	//colisionador posicionX
	collider.x = posicionX;

	//colisionador posicionY
	collider.y = posicionY;
	 
	direccionActual = MOVE_d;
	direccionSiguiente = MOVE_d;


	// Inicializa propiedade de de pacman
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
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
		case SDLK_w: direccionSiguiente = MOVE_w; break;

			// Move down
		case SDLK_DOWN:
		case SDLK_s: direccionSiguiente = MOVE_s; break;

			// Move left
		case SDLK_LEFT:
		case SDLK_a: direccionSiguiente = MOVE_a; break;

			// Move right
		case SDLK_RIGHT:
		case SDLK_d: direccionSiguiente = MOVE_d; break;
		}
	}
}

bool Pacman::tratarDeMover(MoveDirection _direccionNueva)
{
	Tile* tileDestino = nullptr;

	// Retorna el tile destino dependiendo de la direccion de movimiento

	switch (_direccionNueva)
	{
	case MOVE_w:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_s:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_a:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_d:
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


//COLISION
//comprobacion de que esta colisionando
bool Pacman::CheckForCollision(const SDL_Rect& otherCollider)

{	//otro colisionador.x > colisionador.x + colisionador.w
	if (otherCollider.x > collider.x + collider.w) {
		//printf("1");
		return false;
	}

	if (otherCollider.y > collider.y + collider.h) {
		//printf("2");
		return false;
	}

	if (otherCollider.x + otherCollider.w < collider.x) {
		//printf("3");
		return false;
	}

	if (otherCollider.y + otherCollider.h < collider.y) {
		//printf("4");
		return false;
	}

	return true;
}

//COLISION 2

//comprobando si colisiono, el OtroColisionador
bool Pacman::CheckForCollision(const SDL_Rect& collider, const SDL_Rect& otherCollider)
{
	if (otherCollider.x > collider.x + collider.w) {
		//printf("1");
		return false;
	}

	if (otherCollider.y > collider.y + collider.h) {
		//printf("2");
		return false;
	}

	if (otherCollider.x + otherCollider.w < collider.x) {
		//printf("3");
		return false;
	}

	if (otherCollider.y + otherCollider.h < collider.y) {
		//printf("4");
		return false;
	}

	return true;
}



void Pacman::update()
{
	
	// Compruebe si hay colisión con el punto

	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {
	
		cout << "Aqui = :"<<endl;

	
		SDL_Rect eatingHole = {
			posicionX ,
			posicionY ,
			ancho,
			alto,
		};

		if (CheckForCollision(eatingHole, tileSiguiente->getMoneda()->GetCollider())) {
			tileSiguiente->getMoneda()->Delete();
		}
	}


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
		case MOVE_w:
			posicionY = std::max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_s:
			posicionY = std::min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_a:
			posicionX = std::max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_d:
			posicionX = std::min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		collider.x = posicionX;
		collider.y = posicionY;


		if ((direccionActual == MOVE_s || direccionActual == MOVE_w) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_a || direccionActual == MOVE_d) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}
}

void Pacman::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_w:
		cuadroAnimacion = textura->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_s:
		cuadroAnimacion = textura->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_a:
		cuadroAnimacion = textura->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_d:
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


