#pragma once
#include <SDL.h>

class Pacman;
class Poder;

class Fantasma;
class Fruta;
class Moneda;
class Pared;

class Tile
{
private:
	Pacman* pacman;
	Poder* poder;

	Fantasma* fantasma;
	Fruta* fruta;
	Moneda* moneda;
	Pared* pared;

	int posicionX;
	int posicionY;

public:
	static const int anchoTile = 25;
	static const int altoTile = 25;

public:
	Tile();
	Tile(int _x, int _y);

	Pacman* getPacman() { return pacman; }
	Poder* getPoder() { return poder; }


	Fantasma* getFantasma() { return fantasma; }
	Fruta* getFruta() { return fruta; }
	Moneda* getMoneda() { return moneda; }
	Pared* getPared() { return pared; }

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }

	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setPoder(Poder* _poder) { poder = _poder; }


	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setFruta(Fruta* _fruta) { fruta = _fruta; }
	void setMoneda(Moneda* _moneda) { moneda = _moneda; }
	void setPared(Pared* _pared) { pared = _pared; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

};

