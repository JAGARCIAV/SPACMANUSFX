#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <fstream>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "SuperMoneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "MsPacman.h"
#include "Fruta.h"
#include "Pared.h"
#include "Tile.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "FactoryPacmanClasico.h"
#include "FactoryPacmanGalactico.h"
#include "Factory.h"
#include "FantasmasFactory.h"

//#include "GamePanel.h"
using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;
	TileGraph* tileGraph;
	TextureManager* textureManager;
	Factory* factory;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla, Factory* fabrica);
	//MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*> &_vectorObjetosJuegoGM);
};

