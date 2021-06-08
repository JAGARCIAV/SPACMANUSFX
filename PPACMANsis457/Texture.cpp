#include "Texture.h"

SDL_Renderer* Texture::renderer = nullptr;

Texture::Texture()
{
	texture = nullptr;
	ancho = 0;
	alto = 0;
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

//RECORRER MAP DE TEXTURA
Texture::~Texture() {
	free();
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

//bool loadMedia()
//{
//	//Loading success flag
//	bool success = true;
//
//	//Open the font
//	gFont = TTF_OpenFont("lazy.ttf", 28);
//	if (gFont == NULL)
//	{
//		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//		success = false;
//	}
//	else
//	{
//		//Render text
//		SDL_Color textColor = { 5, 87, 2 };
//		if (!gTexture.loadFromRenderedText("PEJI ERES DON KEVIN ", textColor))
//		{
//			printf("Failed to render text texture!\n");
//			success = false;
//		}
//	}
//
//	return success;
//}
//
//bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
//{
//	//Get rid of preexisting texture
//	free();
//
//	//Render text surface
//	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
//	if (textSurface == NULL)
//	{
//		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//	}
//	else
//	{
//		//Create texture from surface pixels
//		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
//		if (mTexture == NULL)
//		{
//			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//		}
//		else
//		{
//			//Get image dimensions
//			mWidth = textSurface->w;
//			mHeight = textSurface->h;
//		}
//
//		//Get rid of old surface
//		SDL_FreeSurface(textSurface);
//	}
//
//	//Return success
//	return mTexture != NULL;
//}
//
//void close()
//{
//	//Free loaded images
//	gTextTexture.free();
//
//	//Free global font
//	TTF_CloseFont(gFont);
//	gFont = NULL;
//
//	//Destroy window	
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	gRenderer = NULL;
//
//	//Quit SDL subsystems
//	TTF_Quit();
//	IMG_Quit();
//	SDL_Quit();
//}