#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <map>

// #include <SDL_image.h>

using namespace std;
class Texture //Es el que nos permite manejar las imagenes
{
private:
	// Textura actual
	SDL_Texture* texture;

	map<string, vector<SDL_Rect*>> mapCuadrosAnimacion;

	int ancho;
	int alto;

public:

	static SDL_Renderer* renderer;

	Texture();
	//destructor
	~Texture();

	vector<SDL_Rect*> getCuadrosAnimacion(string _key) { return mapCuadrosAnimacion[_key]; }

	void free();

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

