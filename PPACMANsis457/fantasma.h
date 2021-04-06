#pragma once
#include <SDL.h>
#include "Movimientos.h"

class Fantasma {
private:
	DireccionMovimiento direccionActual;
	DireccionMovimiento direccionSiguiente;

	SDL_Point posicionActual;

public:
	DireccionMovimiento getDireccionActual() { return direccionActual; }
	void setDireccionActual(DireccionMovimiento _direccionActual) { direccionActual = _direccionActual; }

	DireccionMovimiento getDireccionSiguiente() { return direccionSiguiente; }
	void setDireccionSiguiente(DireccionMovimiento _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }

};