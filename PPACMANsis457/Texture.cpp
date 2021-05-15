#include "Texture.h"

SDL_Renderer* Texture::renderer = nullptr;

Texture::Texture()
{
	texture = nullptr;
	ancho = 0;
	alto = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromImage(std::string path, Uint8 r, Uint8 g, Uint8 b)
{
	// Free the previous texture
	free();

	// Return if the renderer was not set
	if (renderer == nullptr)
		return false;

	// Load image to a surface
	//SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	// Set color key
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));

	// Create texture from the surface
	texture = SDL_CreateTextureFromSurface(Texture::renderer, loadedSurface);
	if (texture == nullptr) {
		printf("Unable to create texture from surface %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	// Set width and height of the texture
	ancho = loadedSurface->w;
	alto = loadedSurface->h;

	// Free the surface
	SDL_FreeSurface(loadedSurface);

	return true;
}

bool Texture::loadFromRenderedText(TTF_Font* font, std::string text, SDL_Color textColor)
{
	// Free the previous texture
	free();

	// Return if the renderer was not set
	if (renderer == NULL)
		return false;

	// Render the text using SDL_ttf library
	SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	if (loadedSurface == NULL) {
		printf("Unable to render text! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	// Create a texture from generated surface
	texture = SDL_CreateTextureFromSurface(Texture::renderer, loadedSurface);
	if (texture == nullptr) {
		printf("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Set width and height of the texture
	ancho = loadedSurface->w;
	alto = loadedSurface->h;

	// Free the surface
	SDL_FreeSurface(loadedSurface);

	return true;
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip renderFlip)
{
	// Return if the renderer was not set
	if (renderer == nullptr)
		return;

	SDL_Rect renderQuad = { x, y, getAncho(), getAlto() };

	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, renderFlip);
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blendMode)
{
	SDL_SetTextureBlendMode(texture, blendMode);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::free()
{
	if (texture != nullptr) {
		// Free the texture and set its pointer to NULL
		SDL_DestroyTexture(texture);
		texture = nullptr;

		ancho = 0;
		alto = 0;
	}
}

Texture::Texture()
{
	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	addTexture("pacman", pacmanTexture);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	addTexture("fantasma1", fantasma1Texture);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	addTexture("fantasma2", fantasma2Texture);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	addTexture("fantasma3", fantasma3Texture);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	addTexture("fantasma4", fantasma4Texture);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	addTexture("fruta", frutaTexture);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	addTexture("moneda", monedaTexture);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);
	addTexture("supermoneda", superMonedaTexture);
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared);
	addTexture("pared", paredTexture);
}
Texture::~Texture() {
	free();
}

void Texture::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void Texture::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}



void Texture::addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion)
{
	auto emca = mapCuadrosAnimacion.find(_key);

	if (emca != mapCuadrosAnimacion.end()) {
		emca->second.push_back(_cuadroAnimacion);
	}
	else
	{
		vector<SDL_Rect*> vca;
		vca.push_back(_cuadroAnimacion);
		mapCuadrosAnimacion[_key] = vca;
	}

}