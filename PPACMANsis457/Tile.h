#pragma once
//#include "pacman.h"
//#include "Fantasma.h"
//#include "Fruta.h"
//#include "Moneda.h"
//#include "Bruja.h"
//#include "Pared.h"
class Pacman;
class Fantasma;
class Fruta;
class Bruja;
class Moneda;
class Pared;

class Tile
{
private:
	int anchoTile;
	int altoTile;
	int posicionX;
	int posicionY;
	
	Pacman* pacman;
	Fantasma* fantasma;
	Moneda* moneda;
	Fruta* fruta;
	Bruja* bruja;
	Pared* pared;
public:
	Tile();
	Tile(int _x, int _y);

	int getAnchoTile() { return anchoTile; }
	int getAltoTile() { return altoTile; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }

	Pacman* getPacman() { return pacman; }
	Fantasma* getFantasma() { return fantasma; }
	Moneda* getMoneda() { return moneda; }
	Fruta* getFruta() { return fruta; }
	Bruja* getBruja() { return bruja; }
	Pared* getPared() { return pared; }
	
	void setAnchoTile(int _anchoTile) { anchoTile = _anchoTile; }
	void setAltoTile(int _altoTile) { anchoTile = _altoTile; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setMoneda(Moneda* _moneda) { moneda = _moneda; }
	void setFruta(Fruta* _fruta) { fruta = _fruta; }
	void setBruja(Bruja* _bruja) { bruja = _bruja; }
	void setParted(Pared* _pared) { pared = _pared; }

};

