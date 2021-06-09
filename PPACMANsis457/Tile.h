#pragma once
#include <SDL.h>

class Pacman;
class PacmanClasico;
class PacmanGalactico;

class Poder;

class Fantasma;
class Fruta;
class Moneda;
class Pared;

class Tile
{
private:
	Pacman* pacman;
	PacmanClasico* pacmanClasico;
	PacmanGalactico* pacmanGalactico;
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
	PacmanClasico* getPacmanClasico() { return pacmanClasico; }
	PacmanGalactico* getPacmanGalactico() { return pacmanGalactico; }

	Poder* getPoder() { return poder; }

	Fantasma* getFantasma() { return fantasma; }
	Fruta* getFruta() { return fruta; }
	Moneda* getMoneda() { return moneda; }
	Pared* getPared() { return pared; }

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }

	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setPacmanClasico(PacmanClasico* _pacmanClasico) { pacmanClasico = _pacmanClasico; }
	void setPacmanGalactico(PacmanGalactico* _pacmanGalactico) { pacmanGalactico = _pacmanGalactico; }

	void setPoder(Poder* _poder) { poder = _poder; }


	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setFruta(Fruta* _fruta) { fruta = _fruta; }
	void setMoneda(Moneda* _moneda) { moneda = _moneda; }
	void setPared(Pared* _pared) { pared = _pared; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

};

