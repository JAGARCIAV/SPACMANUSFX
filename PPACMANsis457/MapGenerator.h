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
#include "Bruja.h"


using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;

	const string pathPacman = "Resources/PersonaCC3.png";

	const string pathFantasma1 = "Resources/VERDE1.png";
	const string pathFantasma2 = "Resources/LILA2.png";
	const string pathFantasma3 = "Resources/LECHUGA4.png";
	const string pathFantasma4 = "Resources/CELESTE3.png";

	const string pathFruta = "Resources/vacuna.png";

	const string pathBruja = "Resources/Bruja1.png";

	const string pathMoneda = "Resources/monedas.png";
	const string pathSuperMoneda = "Resources/GRANDE.png";

	const string pathPared = "Resources/planta.png";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;

	Texture* frutaTexture;
	Texture* brujaTexture;

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

