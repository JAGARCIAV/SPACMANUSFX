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

	const string pathPacmanClasico = "Resources/PACMAN_CLASICO.png";
	const string pathFantasmaClasico1 = "Resources/FANTASMA_CLASICO1.png";
	const string pathFantasmaClasico2 = "Resources/FANTASMA_CLASICO2.png";
	const string pathFantasmaClasico3 = "Resources/FANTASMA_CLASICO3.png";
	const string pathFantasmaClasico4 = "Resources/FANTASMA_CLASICO4.png";
	const string pathFrutaClasico = "Resources/FRUTA_CLASICO.png";
	const string pathMonedaClasico = "Resources/MONEDA_CLASICO.png";
	const string pathSuperMonedaClasico = "Resources/SUPERMONEDA_CLASICO.png";
	const string pathParedClasico = "Resources/PARED_CLASICO.png";
	const string pathParedClasicoAdapter = "Resources/wall_sprite.bmp";

	const string pathPacmanGalactico = "Resources/PACMAN_GALACTICO.png";
	const string pathFantasmaGalactico1 = "Resources/fantasmaamarillo.bmp ";
	const string pathFantasmaGalactico2 = "Resources/azul.png ";
	const string pathFantasmaGalactico3 = "Resources/fantasma.png ";
	const string pathFantasmaGalactico4 = "Resources/fantasmarojo.bmp ";
	const string pathFrutaGalactico = "Resources/espacial2.png";
	const string pathMonedaGalactico = "Resources/monedagalactico1.png";
	const string pathSuperMonedaGalactico = "Resources/Monedas03.jpg";
	const string pathParedGalactico = "Resources/WallTextures.png";

	Texture* pacmanClasicoTexture;
	Texture* fantasmaClasico1Texture;
	Texture* fantasmaClasico2Texture;
	Texture* fantasmaClasico3Texture;
	Texture* fantasmaClasico4Texture;
	Texture* frutaClasicoTexture;
	Texture* monedaClasicoTexture;
	Texture* superMonedaClasicoTexture;
	Texture* paredClasicoTexture;
	Texture* paredClasicoAdapterTexture;

	Texture* pacmanGalacticoTexture;
	Texture* fantasmaGalactico1Texture;
	Texture* fantasmaGalactico2Texture;
	Texture* fantasmaGalactico3Texture;
	Texture* fantasmaGalactico4Texture;
	Texture* frutaGalacticoTexture;
	Texture* monedaGalacticoTexture;
	Texture* superMonedaGalacticoTexture;
	Texture* paredGalacticoTexture;
	
	AnimationFrames* framesAnimacionPacmanClasico;
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

