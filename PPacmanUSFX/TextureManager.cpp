#include "TextureManager.h"

TextureManager::TextureManager()
{
	// Texturas

	//PACMAN CLASICO
	pacmanClasicoTexture = new Texture();
	pacmanClasicoTexture->loadFromImage(pathPacmanClasico);
	addTextura("pacman_clasico", pacmanClasicoTexture);
	fantasmaClasico1Texture = new Texture();
	fantasmaClasico1Texture->loadFromImage(pathFantasmaClasico1);
	addTextura("fantasma_clasico1", fantasmaClasico1Texture);
	fantasmaClasico2Texture = new Texture();
	fantasmaClasico2Texture->loadFromImage(pathFantasmaClasico2);
	addTextura("fantasma_clasico2", fantasmaClasico2Texture);
	fantasmaClasico3Texture = new Texture();
	fantasmaClasico3Texture->loadFromImage(pathFantasmaClasico3);
	addTextura("fantasma_clasico3", fantasmaClasico3Texture);
	fantasmaClasico4Texture = new Texture();
	fantasmaClasico4Texture->loadFromImage(pathFantasmaClasico4);
	addTextura("fantasma_clasico4", fantasmaClasico4Texture);
	frutaClasicoTexture = new Texture();
	frutaClasicoTexture->loadFromImage(pathFrutaClasico);
	addTextura("fruta_clasico", frutaClasicoTexture);
	monedaClasicoTexture = new Texture();
	monedaClasicoTexture->loadFromImage(pathMonedaClasico);
	addTextura("moneda_clasico", monedaClasicoTexture);
	superMonedaClasicoTexture = new Texture();
	superMonedaClasicoTexture->loadFromImage(pathSuperMonedaClasico);
	addTextura("supermoneda_clasico", superMonedaClasicoTexture);
	paredClasicoTexture = new Texture();
	paredClasicoTexture->loadFromImage(pathParedClasico);
	addTextura("pared_clasico", paredClasicoTexture);
	paredClasicoAdapterTexture = new Texture();
	paredClasicoAdapterTexture->loadFromImage(pathParedClasicoAdapter);
	addTextura("pared_clasico_adapter", paredClasicoAdapterTexture);

	//PACMAN GALACTICO
	pacmanGalacticoTexture = new Texture();
	pacmanGalacticoTexture->loadFromImage(pathPacmanGalactico);
	addTextura("pacman_galactico", pacmanGalacticoTexture);
	fantasmaGalactico1Texture = new Texture();
	fantasmaGalactico1Texture->loadFromImage(pathFantasmaGalactico1);
	addTextura("fantasma_galactico1", fantasmaGalactico1Texture);
	fantasmaGalactico2Texture = new Texture();
	fantasmaGalactico2Texture->loadFromImage(pathFantasmaGalactico2);
	addTextura("fantasma_galactico2", fantasmaGalactico2Texture);
	fantasmaGalactico3Texture = new Texture();
	fantasmaGalactico3Texture->loadFromImage(pathFantasmaGalactico3);
	addTextura("fantasma_galactico3", fantasmaGalactico3Texture);
	fantasmaGalactico4Texture = new Texture();
	fantasmaGalactico4Texture->loadFromImage(pathFantasmaGalactico4);
	addTextura("fantasma_galactico4", fantasmaGalactico4Texture);
	frutaGalacticoTexture = new Texture();
	frutaGalacticoTexture->loadFromImage(pathFrutaGalactico);
	addTextura("fruta_galactico", frutaGalacticoTexture);
	monedaGalacticoTexture = new Texture();
	monedaGalacticoTexture->loadFromImage(pathMonedaGalactico);
	addTextura("moneda_galactico", monedaGalacticoTexture);
	superMonedaGalacticoTexture = new Texture();
	superMonedaGalacticoTexture->loadFromImage(pathSuperMonedaGalactico);
	addTextura("supermoneda_galactico", superMonedaGalacticoTexture);
	paredGalacticoTexture = new Texture();
	paredGalacticoTexture->loadFromImage(pathParedGalactico);
	addTextura("pared_galactico", paredGalacticoTexture);
		

	// Frames de animacion
	framesAnimacionPacmanClasico = new AnimationFrames();
	framesAnimacionPacmanClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));
	addFramesAnimacion("pacman_clasico", framesAnimacionPacmanClasico);

	framesAnimacionFantasmaClasico = new AnimationFrames();
	framesAnimacionFantasmaClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));
	addFramesAnimacion("fantasma_clasico", framesAnimacionFantasmaClasico);
}

TextureManager::~TextureManager() {
	free();
}

void TextureManager::addTextura(string _key, Texture* _textura)
{
	mapTexturas[_key] = _textura;
}

void TextureManager::addFramesAnimacion(string _key, AnimationFrames* _framesAnimacion)
{
	mapFramesAnimaciones[_key] = _framesAnimacion;
}



void TextureManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}
