#pragma once
#include<iostream>

#include<map>
#include "Texture.h"
#include "AnimationFrames.h"
using namespace std;

class TextureManager
{
private:

	//VERSION PACMAN CLASICO
	const string pathPacmanClasico =    "Imagenes/Version_Clasico/PACMAN_CLASICO.png";
	const string pathMsPacmanClasico =  "Imagenes/Version_Clasico/MsPacman_Clascico.png";
	const string pathFantasmaClasico1 = "Imagenes/Version_Clasico/FANTASMA_CLASICO1.png";
	const string pathFantasmaClasico2 = "Imagenes/Version_Clasico/FANTASMA_CLASICO2.png";
	const string pathFantasmaClasico3 = "Imagenes/Version_Clasico/FANTASMA_CLASICO3.png";
	const string pathFantasmaClasico4 = "Imagenes/Version_Clasico/FANTASMA_CLASICO4.png";
	const string pathFrutaClasico =     "Imagenes/Version_Clasico/FRUTA_CLASICO.png";
	const string pathMonedaClasico =    "Imagenes/Version_Clasico/MONEDA_CLASICO.png";
	const string pathSuperMonedaClasico="Imagenes/Version_Clasico/SUPERMONEDA_CLASICO.png";
	const string pathParedClasico =     "Imagenes/Version_Clasico/PARED_CLASICO.png";

	//VERSION PACMAN GALACTICO
	const string pathPacmanGalactico =	  "Imagenes/Version_Galactico/Pacman_Galactico.png";
	const string pathMsPacmanGalactico =  "Imagenes/Version_Galactico/MsPacman_Galactico01.png";
	const string pathFantasmaGalactico1 = "Imagenes/Version_Galactico/AZUL_GALACTICO.png";
	const string pathFantasmaGalactico2 = "Imagenes/Version_Galactico/PLOMO_GALACTICO.png";
	const string pathFantasmaGalactico3 = "Imagenes/Version_Galactico/VERDE_GALACTICO.png";
	const string pathFantasmaGalactico4 = "Imagenes/Version_Galactico/VERDE_GALACTICO.png";
	const string pathFrutaGalactico =     "Imagenes/Version_Galactico/FRUTA_GALACTICO.png";
	const string pathMonedaGalactico =    "Imagenes/Version_Galactico/MONEDA_GALACTICO.png";
	const string pathSuperMonedaGalactico="Imagenes/Version_Galactico/SUPERMONEDA_GALACTICO.png";
	const string pathParedGalactico =     "Imagenes/Version_Galactico/PARED_GALACTICO.bmp";


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
	Texture* paredClasicoAdapterTexture;

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

	AnimationFrames* framesAnimacionPacmanClasico;
	AnimationFrames* framesAnimacionFantasmaClasico;

private:
	map<string, Texture*> mapTexturas;
	map<string, AnimationFrames*> mapFramesAnimaciones;

	map<string, SDL_Texture*> mapTexturasSDL;
	SDL_Renderer* renderer;

	TextureManager();
	~TextureManager();

	static TextureManager* instancia;
public:
	static TextureManager* getInstancia();

	//Metodos accesores
	SDL_Renderer* getRenderer() { return renderer; }
	void setRenderer(SDL_Renderer* _renderer) { renderer = _renderer; }

	void inicializarRecursos();
	void inicializarRecursosSDL(SDL_Renderer* _renderer);

	Texture* getTextura(string _key) { return mapTexturas[_key]; }
	AnimationFrames* getFramesAnimacion(string _key) { return mapFramesAnimaciones[_key]; }

	void addTextura(string _key, Texture* _textura);
	void addFramesAnimacion(string _key, AnimationFrames* _framesAnimacion);
	void free();

	//Metodos propuesta nueva
	bool load(string fileName, string _key, SDL_Renderer* _renderer);

	void clearTextureMap();
	void clearFromTextureMap(string _key);

	void draw(string _key, int x, int y, int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string _key, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, double angle, int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawTile(string _key, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer);
};