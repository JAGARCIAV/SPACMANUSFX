#include "TextureManager.h"

TextureManager::TextureManager()
{
	//PACMAN CLASICO
	pacmanClasicoTexture = new Texture();
	pacmanClasicoTexture->loadFromImage(pathPacmanClasico);
	addTexture("pacman_clasico", pacmanClasicoTexture);
	fantasmaClasico1Texture = new Texture();
	fantasmaClasico1Texture->loadFromImage(pathFantasmaClasico1);
	addTexture("fantasma_clasico1", fantasmaClasico1Texture);
	fantasmaClasico2Texture = new Texture();
	fantasmaClasico2Texture->loadFromImage(pathFantasmaClasico2);
	addTexture("fantasma_clasico2", fantasmaClasico2Texture);
	fantasmaClasico3Texture = new Texture();
	fantasmaClasico3Texture->loadFromImage(pathFantasmaClasico3);
	addTexture("fantasma_clasico3", fantasmaClasico3Texture);
	fantasmaClasico4Texture = new Texture();
	fantasmaClasico4Texture->loadFromImage(pathFantasmaClasico4);
	addTexture("fantasma_clasico4", fantasmaClasico4Texture);
	frutaClasicoTexture = new Texture();
	frutaClasicoTexture->loadFromImage(pathFrutaClasico);
	addTexture("fruta_clasico", frutaClasicoTexture);
	monedaClasicoTexture = new Texture();
	monedaClasicoTexture->loadFromImage(pathMonedaClasico);
	addTexture("moneda_clasico", monedaClasicoTexture);
	superMonedaClasicoTexture = new Texture();
	superMonedaClasicoTexture->loadFromImage(pathSuperMonedaClasico);
	addTexture("supermoneda_clasico", superMonedaClasicoTexture);
	paredClasicoTexture = new Texture();
	paredClasicoTexture->loadFromImage(pathParedClasico);
	addTexture("pared_clasico", paredClasicoTexture);

	paredAdapterTexture = new Texture();
	paredAdapterTexture->loadFromImage(pathParedAdapter);
	addTexture("pared_clasico_adapter", paredAdapterTexture);

	//PACMAN GALACTICO
	pacmanGalacticoTexture = new Texture();
	pacmanGalacticoTexture->loadFromImage(pathPacmanGalactico);
	addTexture("pacman_galactico", pacmanGalacticoTexture);
	fantasmaGalactico1Texture = new Texture();
	fantasmaGalactico1Texture->loadFromImage(pathFantasmaGalactico1);
	addTexture("fantasma_galactico1", fantasmaGalactico1Texture);
	fantasmaGalactico2Texture = new Texture();
	fantasmaGalactico2Texture->loadFromImage(pathFantasmaGalactico2);
	addTexture("fantasma_galactico2", fantasmaGalactico2Texture);
	fantasmaGalactico3Texture = new Texture();
	fantasmaGalactico3Texture->loadFromImage(pathFantasmaGalactico3);
	addTexture("fantasma_galactico3", fantasmaGalactico3Texture);
	fantasmaGalactico4Texture = new Texture();
	fantasmaGalactico4Texture->loadFromImage(pathFantasmaGalactico4);
	addTexture("fantasma_galactico4", fantasmaGalactico4Texture);
	frutaGalacticoTexture = new Texture();
	frutaGalacticoTexture->loadFromImage(pathFrutaGalactico);
	addTexture("fruta_galactico", frutaGalacticoTexture);
	monedaGalacticoTexture = new Texture();
	monedaGalacticoTexture->loadFromImage(pathMonedaGalactico);
	addTexture("moneda_galactico", monedaGalacticoTexture);
	superMonedaGalacticoTexture = new Texture();
	superMonedaGalacticoTexture->loadFromImage(pathSuperMonedaGalactico);
	addTexture("supermoneda_galactico", superMonedaGalacticoTexture);
	paredGalacticoTexture = new Texture();
	paredGalacticoTexture->loadFromImage(pathParedGalactico);
	addTexture("pared_galactico", paredGalacticoTexture);

	//PACMAN ASESINO
	pacmanAsesinoTexture = new Texture();
	pacmanAsesinoTexture->loadFromImage(pathPacmanAsesino);
	addTexture("pacman_asesino", pacmanAsesinoTexture);
	fantasmaAsesino1Texture = new Texture();
	fantasmaAsesino1Texture->loadFromImage(pathFantasmaAsesino1);
	addTexture("fantasma_asesino1", fantasmaAsesino1Texture);
	fantasmaAsesino2Texture = new Texture();
	fantasmaAsesino2Texture->loadFromImage(pathFantasmaAsesino2);
	addTexture("fantasma_asesino2", fantasmaAsesino2Texture);
	fantasmaAsesino3Texture = new Texture();
	fantasmaAsesino3Texture->loadFromImage(pathFantasmaAsesino3);
	addTexture("fantasma_asesino3", fantasmaAsesino3Texture);
	fantasmaAsesino4Texture = new Texture();
	fantasmaAsesino4Texture->loadFromImage(pathFantasmaAsesino4);
	addTexture("fantasma_asesino4", fantasmaAsesino4Texture);
	frutaAsesinoTexture = new Texture();
	frutaAsesinoTexture->loadFromImage(pathFrutaAsesino);
	addTexture("fruta_asesino", frutaAsesinoTexture);
	monedaAsesinoTexture = new Texture();
	monedaAsesinoTexture->loadFromImage(pathMonedaAsesino);
	addTexture("moneda_asesino", monedaAsesinoTexture);
	superMonedaAsesinoTexture = new Texture();
	superMonedaAsesinoTexture->loadFromImage(pathSuperMonedaAsesino);
	addTexture("supermoneda_asesino", superMonedaAsesinoTexture);
	paredAsesinoTexture = new Texture();
	paredAsesinoTexture->loadFromImage(pathParedAsesino);
	addTexture("pared_asesino", paredAsesinoTexture);
	
}

TextureManager::~TextureManager() {
	free();
}

void TextureManager::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void TextureManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}
