#pragma once
#include<map>
#include "Texture.h"
#include "AnimationFrames.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;
	map<string, AnimationFrames*> mapFramesAnimaciones;


	//VERSION PACMAN CLASICO
	const string pathPacmanClasico = "IMAGENES/VERSION CLASICO/PACMAN_CLASICO.png";
	const string pathMsPacmanClasico = "IMAGENES/VERSION CLASICO/MSPACMAN_CLASICO.png";
	const string pathFantasmaClasico1 = "IMAGENES/VERSION CLASICO/FANTASMA_CLASICO1.png";
	const string pathFantasmaClasico2 = "IMAGENES/VERSION CLASICO/FANTASMA_CLASICO2.png";
	const string pathFantasmaClasico3 = "IMAGENES/VERSION CLASICO/FANTASMA_CLASICO3.png";
	const string pathFantasmaClasico4 = "IMAGENES/VERSION CLASICO/FANTASMA_CLASICO4.png";
	const string pathFrutaClasico = "IMAGENES/VERSION CLASICO/FRUTA_CLASICO.png";
	const string pathMonedaClasico = "IMAGENES/VERSION CLASICO/MONEDA_CLASICO.png";
	const string pathSuperMonedaClasico = "IMAGENES/VERSION CLASICO/SUPERMONEDA_CLASICO.png";
	const string pathParedClasico = "IMAGENES/VERSION CLASICO/PARED_CLASICO.png";

	//VERSION PACMAN GALACTICO
	const string pathPacmanGalactico =	  "IMAGENES/VERSION GALACTICO/PACMAN_GALACTICO.png";
	const string pathMsPacmanGalactico = "IMAGENES/VERSION GALACTICO/MSPACMAN_GALACTICO.png";
	const string pathFantasmaGalactico1 = "IMAGENES/VERSION GALACTICO/FANTASMA_GALACTICO1.bmp";
	const string pathFantasmaGalactico2 = "IMAGENES/VERSION GALACTICO/FANTASMA_GALACTICO2.png";
	const string pathFantasmaGalactico3 = "IMAGENES/VERSION GALACTICO/FANTASMA_GALACTICO3.bmp";
	const string pathFantasmaGalactico4 = "IMAGENES/VERSION GALACTICO/FANTASMA_GALACTICO4.bmp";
	const string pathFrutaGalactico = "IMAGENES/VERSION GALACTICO/FRUTA_GALACTICO.png";
	const string pathMonedaGalactico = "IMAGENES/VERSION GALACTICO/MONEDA_GALACTICO.png";
	const string pathSuperMonedaGalactico = "IMAGENES/VERSION GALACTICO/SUPERMONEDA_GALACTICO.png";
	const string pathParedGalactico = "IMAGENES/VERSION GALACTICO/PARED_GALACTICO.bmp";


	//VERSION PACMAN CLASICO
	Texture* pacmanClasicoTexture;
	Texture* MsPacmanClasicoTexture;
	Texture* fantasmaClasico1Texture;
	Texture* fantasmaClasico2Texture;
	Texture* fantasmaClasico3Texture;
	Texture* fantasmaClasico4Texture;
	Texture* frutaClasicoTexture;
	Texture* monedaClasicoTexture;
	Texture* superMonedaClasicoTexture;
	Texture* paredClasicoTexture;
	
	//VERSION PACMAN GALACTICO
	Texture* pacmanGalacticoTexture;
	Texture* MsPacmanGalacticoTexture;
	Texture* fantasmaGalactico1Texture;
	Texture* fantasmaGalactico2Texture;
	Texture* fantasmaGalactico3Texture;
	Texture* fantasmaGalactico4Texture;
	Texture* frutaGalacticoTexture;
	Texture* monedaGalacticoTexture;
	Texture* superMonedaGalacticoTexture;
	Texture* paredGalacticoTexture;
	Texture* paredGalacticoAdapterTexture;
	
	// Frames de animacion de Pacman
	AnimationFrames* framesAnimacionPacmanClasico;

	// Frames de animacion de Fantasmas
	AnimationFrames* framesAnimacionFantasmaClasico;

public:
	TextureManager();
	~TextureManager();

	Texture* getTextura(string _key) { return mapTexturas[_key]; }
	AnimationFrames* getFramesAnimacion(string _key) { return mapFramesAnimaciones[_key]; }

	void addTextura(string _key, Texture* _textura);
	void addFramesAnimacion(string _key, AnimationFrames* _framesAnimacion);
	void free();
};