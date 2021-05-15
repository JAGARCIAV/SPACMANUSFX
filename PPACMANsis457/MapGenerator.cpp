#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureAnimationManager* _textureAnimationManager, int _anchoPantalla, int _altoPantalla)
{
	tileGraph = _tileGraph;
	textureAnimationManager = _textureAnimationManager;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}


bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'C':
				objetoNuevo = new Moneda(tileNuevo, textureAnimationManager->getTexture("supermoneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(9);
				break;
			case '-':
				objetoNuevo = new Moneda(tileNuevo, textureAnimationManager->getTexture("moneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(7);
				break;
			case 'Y':
				objetoNuevo = new Fruta(textureAnimationManager->getTexture("fruta"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(4);

				break;

			case 'J':
				objetoNuevo = new Fantasma(tileNuevo, textureAnimationManager->getTexture("fantasma1"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'I':
				objetoNuevo = new Fantasma(tileNuevo, textureAnimationManager->getTexture("fantasma2"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'H':
				objetoNuevo = new Fantasma(tileNuevo, textureAnimationManager->getTexture("fantasma3"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'G':
				objetoNuevo = new Fantasma(tileNuevo, textureAnimationManager->getTexture("fantasma4"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'W':
				objetoNuevo = new Pared(tileNuevo, textureAnimationManager->getTexture("pared"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'P':
				objetoNuevo = new Pacman(tileNuevo, textureAnimationManager->getTexture("pacman"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			}

			// If the object was created, add it to the vector
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	/*for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}*/

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}