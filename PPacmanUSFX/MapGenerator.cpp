#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla, Factory* _factory)
{
	factory = _factory;
	tileGraph = _tileGraph;
	textureManager = _textureManager;
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
			case 'x':
				objetoNuevo = factory->createParedInstance(tileNuevo, textureManager, x * Tile::altoTile, y * Tile::altoTile, false);
				objetoNuevo->setParametrosAnimacion(1);
				break;
			case '.':
				objetoNuevo = factory->createMonedaInstance(tileNuevo, textureManager, x * 25, y * 25);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'p':
				objetoNuevo = factory->createPacmanInstance(tileNuevo, textureManager, x * 25, y * 25, 5);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'a':
				objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'b':
				objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 2);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'c':
				objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 2);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'd':
				objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 3);
				objetoNuevo->setParametrosAnimacion(4);
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

	GameObject* objetoPanel = new GamePanel(new Texture(), 20, 450);
	vectorObjetosJuego.push_back(objetoPanel);

	return true;
}

void MapGenerator::populate(std::vector<GameObject*> &_vectorObjetosJuegoGM)
{
	/*for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}*/

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}