#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla, Factory* _factory)
//MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla)
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

		//FantasmasFactory::initialize();

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Fantasma* objetoFantasmaClonado = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'W':

				objetoNuevo = factory->createParedInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesDireccion(1);

				break;
			case '-':

				objetoNuevo = factory->createMonedaInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesDireccion(6);


				break;
			case 'C':
				objetoNuevo = factory->createSuperMonedaInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesDireccion(6);
				
				break;
			case 'Y':

				objetoNuevo = factory->createFrutaInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesDireccion(4);
				break;

			case 'P':

				objetoNuevo = factory->createPacmanInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				break;

			case 'S':

				objetoNuevo = factory->createMsPacmanInstance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				break;

			case 'I':

				objetoNuevo = factory->createFantasma1Instance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(1);

				break;
			case 'G':
				objetoNuevo = factory->createFantasma2Instance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(4);
				break;
			case 'H':

				objetoNuevo = factory->createFantasma3Instance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(2);

				break;
			case 'J':
				objetoNuevo = factory->createFantasma4Instance(tileNuevo, textureManager);
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(3);
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

	/*GameObject* objetoPanel = new GamePanel(new Texture(), 20, 450);
	vectorObjetosJuego.push_back(objetoPanel);*/

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