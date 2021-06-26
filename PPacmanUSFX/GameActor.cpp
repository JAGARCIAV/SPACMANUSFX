#include "GameActor.h"

TileGraph* GameActor::tileGraph = nullptr;

GameActor::GameActor():GameObject()
{
	posicionX = 0;
	posicionY = 0;
	ancho = 0;
	alto = 0;

	solido = true;
	indestructible = true;
	visible = true;
	movil = false;
	enMovimiento = false;

	velocidad = 10;
	energia = 10;
	vidas = 3;

	textura = nullptr;
	framesAnimacion = nullptr;
	tileActual = nullptr;
	tileSiguiente = nullptr;

	direccionActual = MOVE_STILL;
	direccionSiguiente = MOVE_STILL;

	numeroFrame = 0;
	contadorFrames = 0;
	framesDireccion = 1;

	colisionador = new SDL_Rect({ 0, 0, ancho, alto });
}

GameActor::GameActor(Texture* _textura):GameObject()
{
	posicionX = 0;
	posicionY = 0;
	ancho = 0;
	alto = 0;

	solido = true;
	indestructible = true;
	visible = true;
	movil = false;
	enMovimiento = false;

	velocidad = 10;
	energia = 10;
	vidas = 3;

	textura = _textura;
	tileActual = nullptr;
	tileSiguiente = nullptr;

	direccionActual = MOVE_STILL;
	direccionSiguiente = MOVE_STILL;

	numeroFrame = 0;
	contadorFrames = 0;
	framesDireccion = 1;

	colisionador = new SDL_Rect({ posicionX, posicionY, ancho, alto });
}

GameActor::~GameActor()
{
	free();
}

bool GameActor::revisarColision(const SDL_Rect* _otroColisionador)
{
	if (_otroColisionador->x > colisionador->x + colisionador->w) {
		return false;
	}

	if (_otroColisionador->y > colisionador->y + colisionador->h) {
		return false;
	}

	if (_otroColisionador->x + _otroColisionador->w < colisionador->x) {
		return false;
	}

	if (_otroColisionador->y + _otroColisionador->h < colisionador->y) {
		return false;
	}

	return true;
}

bool GameActor::revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2)
{
	if (_colisionador1->x > _colisionador2->x + _colisionador2->w) {
		return false;
	}

	if (_colisionador1->y > _colisionador2->y + _colisionador2->h) {
		return false;
	}

	if (_colisionador1->x + _colisionador1->w < _colisionador2->x) {
		return false;
	}

	if (_colisionador1->y + _colisionador1->h < _colisionador2->y) {
		return false;
	}

	return true;
}


void GameActor::render()
{

	if (visible) {
		/*SDL_Rect rect = { posicionX, posicionY, ancho, alto };
		SDL_Rect clip = { 0 + frameX * Tile::anchoTile, 0 + frameY * Tile::altoTile, Tile::anchoTile, Tile::altoTile };
		textura->render(posicionX, posicionY, &clip, &rect);*/

		SDL_Rect* cuadroAnimacion = new SDL_Rect({ 25 * numeroFrame, 0, getAncho(), getAlto() });

		// Renderizar en la pantalla
		textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
	}

	
}

void GameActor::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesDireccion - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}

void GameActor::deleteGameObject()
{
	GameObject::deleteGameObject();
}


bool GameActor::tratarDeMover(MoveDirection _direccionNueva)
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

int GameActor::restarEnergia()
{
	if (energia > 0) {
		energia--;
	}

	return energia;
}

int GameActor::restarVida()
{
	if (vidas > 0) {
		vidas--;
	}

	return vidas;
}
