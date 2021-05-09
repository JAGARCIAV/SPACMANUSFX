#pragma once
#include<iostream>
#include<vector>
#include<list>
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
	//vector<GameObject*> vectorObjetosJuego;
	list<GameObject*> listaObjetosJuegos;

	const string pathPacman = "Resources/AurelioSol.png";

	const string pathFantasma1 = "Resources/Azul.png";
	const string pathFantasma2 = "Resources/Morado.png";
	const string pathFantasma3 = "Resources/Rojo.png";
	const string pathFantasma4 = "Resources/Verde.png";
	const string pathFruta = "Resources/Frutas.png";
	const string pathBruja = "Resources/Bruja.png";
	const string pathMoneda = "Resources/monedas.png";
	const string pathSuperMoneda = "Resources/SuperMoneda.png";
	const string pathPared = "Resources/Muro.png";

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

	//void populate(std::list<GameObject*>& _vectorObjetosJuegoGM);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	//void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
	void populate(list<GameObject*>& _listaObjetosJuegoGM);

};

