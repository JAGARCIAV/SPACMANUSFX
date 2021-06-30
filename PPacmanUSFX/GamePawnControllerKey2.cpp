#include "GamePawnControllerKey2.h"

GamePawnControllerKey2::GamePawnControllerKey2() :GamePawnController()
{
}

void GamePawnControllerKey2::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
		switch (event->key.keysym.sym)
		{
			// Move up
		case SDLK_w:
			direccionSiguiente = MOVE_UP; break;

			// Move down
		case SDLK_s:
			direccionSiguiente = MOVE_DOWN; break;

			// Move left
		case SDLK_a:
			direccionSiguiente = MOVE_LEFT; break;

			// Move right
		case SDLK_d:
			direccionSiguiente = MOVE_RIGHT; break;
		}
	}
}
