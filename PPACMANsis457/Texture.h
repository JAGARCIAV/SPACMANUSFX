#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <map>

// #include <SDL_image.h>

using namespace std;
class Texture
{
private:
	// Textura actual
	SDL_Texture* texture;
	//map<string, Texture*> mapTexturas;

	//Texture* textureAnimationManager;
	//Texture* texture;

	map<string, vector<SDL_Rect*>> mapCuadrosAnimacion;

	/*const string pathPacman = "Resources/AurelioSol.png";
	const string pathFantasma1 = "Resources/AZULGR.png";
	const string pathFantasma2 = "Resources/VERDEGR.png";
	const string pathFantasma3 = "Resources/NARANJAGR.png";
	const string pathFantasma4 = "Resources/PLOMOGR.png";
	const string pathFruta = "Resources/Frutas.png";
	const string pathMoneda = "Resources/Monedas.png";
	const string pathSuperMoneda = "Resources/SuperMoneda.png";
	const string pathPared = "Resources/Muro.png";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;
	*/
	int ancho;
	int alto;

public:
	// Static SDL_Renderer so we don't have to ask for it
	// when creating the texture or when rendering
	// TODO: Temporary solution, should be removed after implementation of Game class
	static SDL_Renderer* renderer;

	Texture();
	~Texture();


	//Texture* getTexture() { return texture; }

	vector<SDL_Rect*> getCuadrosAnimacion(string _key) { return mapCuadrosAnimacion[_key]; }

	//Texture* getTexture(string _key) { return mapTexturas[_key]; }
	//void addTexture(string _key, Texture* _texture);
	void free();

	//void setTexture(Texture* _textura) { texture = _textura; }
	void setCuadrosAnimacion(string _key, vector<SDL_Rect*> _vectorCuadrosAnimacion) {
		mapCuadrosAnimacion[_key] = _vectorCuadrosAnimacion;
	}
	void addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion);

	// Load texture from file
	bool loadFromImage(std::string path, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);

	// Load texture from rendered text
	bool loadFromRenderedText(TTF_Font* font, std::string text, SDL_Color textColor);

	// Render the texture
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip renderFlip = SDL_FLIP_NONE);

	// Set color
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Set blend mode
	void setBlendMode(SDL_BlendMode blendMode);

	// Set alpha
	void setAlpha(Uint8 alpha);

	// Free assets
	//void free();

	int getAncho() { return ancho; }
	int getAlto() { return alto; }

};

