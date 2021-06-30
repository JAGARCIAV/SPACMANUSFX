#include "GamePawn.h"

GamePawn::GamePawn() :GameActor()
{
	gamePawnController = new GamePawnController();
}

GamePawn::GamePawn(Texture* _textura) : GameActor(_textura)
{
	gamePawnController = new GamePawnController();
}


GamePawn::~GamePawn()
{
	free();
}

void GamePawn::render()
{
	GameActor::render();
}

void GamePawn::update()
{
	GameActor::update();
}

void GamePawn::handleEvent(SDL_Event* event)
{
	gamePawnController->handleEvent(event);
	direccionSiguiente = gamePawnController->getDireccionSiguiente();
}

void GamePawn::deleteGameObject()
{
	GameObject::deleteGameObject();
}
