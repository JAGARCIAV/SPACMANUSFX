#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;


	//PACMAN CLASICO
	const string pathPacmanClasico = "Resources/PACMAN_CLASICO.png";
	const string pathFantasmaClasico1 = "Resources/FANTASMA_CLASICO1.png";
	const string pathFantasmaClasico2 = "Resources/FANTASMA_CLASICO2.png";
	const string pathFantasmaClasico3 = "Resources/FANTASMA_CLASICO3.png";
	const string pathFantasmaClasico4 = "Resources/FANTASMA_CLASICO4.png";
	const string pathFrutaClasico = "Resources/FRUTA_CLASICO.png";
	const string pathMonedaClasico = "Resources/MONEDA_CLASICO.png";
	const string pathSuperMonedaClasico = "Resources/SUPERMONEDA_CLASICO.png";
	const string pathParedClasico = "Resources/PARED_CLASICO.png";

	const string pathParedAdapter = "Resources/wall_sprite.bmp";

	//PACMAN GALACTICO
	const string pathPacmanGalactico = "Resources/PACMAN_GALACTICO.png";
	const string pathFantasmaGalactico1 = "Resources/FANTASMA_GALACTICO1.bmp ";
	const string pathFantasmaGalactico2 = "Resources/FANTASMA_GALACTICO2.png ";
	const string pathFantasmaGalactico3 = "Resources/FANTASMA_GALACTICO3.bmp ";
	const string pathFantasmaGalactico4 = "Resources/FANTASMA_GALACTICO4.bmp ";
	const string pathFrutaGalactico = "Resources/FRUTA_CLASICO.png";
	const string pathMonedaGalactico = "Resources/MONEDA_CLASICO.png";
	const string pathSuperMonedaGalactico = "Resources/SUPERMONEDA_GALACTICO.png";
	const string pathParedGalactico = "Resources/PARED_GALACTICO.bmp";

	//PACMAN ASESINO
	const string pathPacmanAsesino = "Resources/PACMAN_GALACTICO.png";
	const string pathFantasmaAsesino1 = "Resources/FANTASMA_GALACTICO1.bmp ";
	const string pathFantasmaAsesino2 = "Resources/FANTASMA_GALACTICO2.png ";
	const string pathFantasmaAsesino3 = "Resources/FANTASMA_GALACTICO3.bmp ";
	const string pathFantasmaAsesino4 = "Resources/FANTASMA_GALACTICO4.bmp ";
	const string pathFrutaAsesino = "Resources/FRUTA_CLASICO.png";
	const string pathMonedaAsesino = "Resources/MONEDA_CLASICO.png";
	const string pathSuperMonedaAsesino = "Resources/SUPERMONEDA_GALACTICO.png";
	const string pathParedAsesino = "Resources/PARED_ASESINO.png";

	//PACMAN CLASICO
	Texture* pacmanClasicoTexture;
	Texture* fantasmaClasico1Texture;
	Texture* fantasmaClasico2Texture;
	Texture* fantasmaClasico3Texture;
	Texture* fantasmaClasico4Texture;
	Texture* frutaClasicoTexture;
	Texture* monedaClasicoTexture;
	Texture* superMonedaClasicoTexture;
	Texture* paredClasicoTexture;

	Texture* paredAdapterTexture;

	//PACMAN GALACTICO
	Texture* pacmanGalacticoTexture;
	Texture* fantasmaGalactico1Texture;
	Texture* fantasmaGalactico2Texture;
	Texture* fantasmaGalactico3Texture;
	Texture* fantasmaGalactico4Texture;
	Texture* frutaGalacticoTexture;
	Texture* monedaGalacticoTexture;
	Texture* superMonedaGalacticoTexture;
	Texture* paredGalacticoTexture;

	//PACMAN ASESINO
	Texture* pacmanAsesinoTexture;

	Texture* fantasmaAsesino1Texture;
	Texture* fantasmaAsesino2Texture;
	Texture* fantasmaAsesino3Texture;
	Texture* fantasmaAsesino4Texture;
	Texture* frutaAsesinoTexture;
	Texture* monedaAsesinoTexture;
	Texture* superMonedaAsesinoTexture;
	Texture* paredAsesinoTexture;
	
public:
	TextureManager();
	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();


};

