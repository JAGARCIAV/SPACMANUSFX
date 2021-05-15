#include "TextureAnimationManager.h"

TextureAnimationManager::TextureAnimationManager()
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

TextureAnimationManager::~TextureAnimationManager() {
	free();
}

void TextureAnimationManager::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void TextureAnimationManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}



void TextureAnimationManager::addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion)
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