#include "TileGraph.h"

#include<algorithm>

TileGraph::TileGraph() {
	tiles = nullptr
	anchoTileGrahp = 0;
	altoTileGrahp = 0;
}

TileGraph::TileGraph(int _anchoTileGraph, int _altoTileGraph) {

	tiles = new Tile[_anchoTileGraph * _altoTileGraph];

	for (int y = 0; y < _altoTileGraph;y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			tiles[x + (y * _anchoTileGraph)].setPosicionX(x);
			tiles[x + (y * _anchoTileGraph)].setPosicionX(y);

		}
	}

	anchoTileGrahp = _anchoTileGraph;
	altoTileGrahp = _altoTileGraph;
}

void TileGraph::configurar(int _anchoTileGraph, int _altoTileGraph) {
	if (tiles != nullptr)
		delete[] tiles;

}

Tile* TileGraph::getTileEn(int _x, int _y) {

}

