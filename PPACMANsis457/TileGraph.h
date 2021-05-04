#pragma once
#include <vector>
#include <iostream>
#include <array>

#include "Tile.h"
using namespace std;

class TileGraph
{
private:
	vector<Tile*> tilesGraph;

	int anchoTileGraph;
	int altoTileGraph;

	int getIndice(int _x, int _y);

public:
	TileGraph() {};
	TileGraph(int _anchoTileGraph, int _altoTileGraph) {};
	//~TileGrah() {};

	void configurar(int _anchoTileGraph, int _altoTileGraph) {};
	Tile* getTileEnLaPosicion(int _x, int _y) {};

	array<Tile*, 4> getVecinos(Tile* _tile) {};
	array<Tile*, 8> getVecinosConDiagonales(Tile* _tile) {};


};