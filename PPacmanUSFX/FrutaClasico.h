#pragma once
#include "Fruta.h"
class FrutaClasico :
    public Fruta
{
private:
	int aumentarPuntosVida;
	int aumentarVelocidad;

public:
	FrutaClasico(Tile* _tile, Texture* _frutaTexture);
	int getAumentarPuntosVida() { return aumentarPuntosVida; }
	int getAumentarVelocidad() { return aumentarVelocidad; }

	void setAumentarPuntosVida(int _aumentarPuntosVida) { aumentarPuntosVida = _aumentarPuntosVida; }
	void setAumentarVelocidad(int _aumentarVelocidad) { aumentarVelocidad = _aumentarVelocidad; }

	//Manejador de Eventos
	void update() override;
};
 