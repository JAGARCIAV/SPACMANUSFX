#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	//MAPA PARA GUARDAR LOS STRING O ADMINISTRADOR DE TEXTURA
	map<string, Texture*> mapTexturas;

	Texture* textureManager;

	// string de las clases 
	const string pathPacman = "Resources/AurelioSolClasico.png";

	//const string pathPacmanClasico = "Resources/AurelioSolClasico.png";
	//const string pacthPacmanGalactico = "Resources/AurelioSolGalactico.png";

	const string pathPoder = "Resources/Poder1.png";

	const string pathFantasma1 = "Resources/AZULGR.png";
	const string pathFantasma2 = "Resources/VERDEGR.png";
	const string pathFantasma3 = "Resources/NARANJAGR.png";
	const string pathFantasma4 = "Resources/PLOMOGR.png";
	const string pathFruta = "Resources/Frutas.png";
	const string pathMoneda = "Resources/Monedas.png";
	const string pathSuperMoneda = "Resources/SuperMoneda.png";
	const string pathPared = "Resources/Muro.png";
	
	//TEXTURAS DEL LAS CLASES con un puntero direcionamos a cada clase
	Texture* pacmanTexture;
	Texture* poderTexture;

	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;
public:
	//METODOS 
	
	//CONSTRUCTOR
	TextureManager();

	//DESTRUCTOR
	~TextureManager();

	//metodo getTexture OBTENER textura, me devuelve una textura con puntero, como estamos trabajando con map tenemos que devolver una llave;
	//retorna mapTExtura, y me debuelve la llave
	//pares de valores
	Texture* getTexture(string _key) { return mapTexturas[_key]; }

	//metodo addTexture Paso un estrin con la llave
	void addTexture(string _key, Texture* _texture);
	void free();

	
};

