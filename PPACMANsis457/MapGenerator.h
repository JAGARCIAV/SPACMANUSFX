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


using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;

	const string pathPacman = "Resources/AurelioSol.png";

	const string pathFantasma1 = "Resources/Azul.png";
	const string pathFantasma2 = "Resources/Verde.png";
	const string pathFantasma3 = "Resources/rojo.png";
	const string pathFantasma4 = "Resources/Morado.png";

	const string pathFruta = "Resources/Frutas.png";

	const string pathMoneda = "Resources/Monedas.png";
	const string pathSuperMoneda = "Resources/SuperMoneda.png";

	const string pathPared = "Resources/Wall.bmp";

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

