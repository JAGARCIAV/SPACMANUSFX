#pragma once
#include <SDL.h>
#include "Movimientos.h"
class fantasma{
private:
	DireccionMovimiento direccionActual;
	DireccionMovimiento direccionSiguiente;

	SDL_Point posicionActual;

public:
	DireccionMovimiento getDireccionActual() { return direccionActual; }
	void setDireccionActual(DireccionMovimiento direccionActual) { direccionActual = direccionActual; }

	DireccionMovimiento setDirecionActual(DireccionMovimiento _direccionActual) { direccionActual = _direccionActual;  }
	DireccionMovimiento setDireccionSiguiente(DireccionMovimiento _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }
};

