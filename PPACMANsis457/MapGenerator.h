#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"
#include "Pared.h"

using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;

	const string pathPacman = "Resources/PacMan.bmp";
	const string pathFantasma1 = "Resources/Blinky.bmp";
	const string pathFantasma2 = "Resources/Clyde.bmp";
	const string pathFantasma3 = "Resources/Inkey.bmp";
	const string pathFantasma4 = "Resources/Pinky.bmp";
	const string pathFruta = "Resources/Frutas.png";
	const string pathMoneda = "Resources/Moneda14.bmp";
	const string pathSuperMoneda = "Resources/Moneda13.bmp";
	const string pathPared = "Resources/Wall_sprite.bmp";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
};

