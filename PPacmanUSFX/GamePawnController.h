#pragma once
#include <SDL.h>
#include "MoveDirection.h"

class GamePawnController
{
protected:
	MoveDirection direccionSiguiente;
public:

	MoveDirection getDireccionSiguiente() { return direccionSiguiente; }

	virtual void handleEvent(SDL_Event* event) {};
};

