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

	//vertical
	GameObject* contenedorPaneles = new GUIComposite(TextureManager::getInstancia()->getRenderer(), "Root");

	GameObject* objetoPanel1 = new Panel(TextureManager::getInstancia()->getRenderer(), 1628, 0, 62, 525, "PANEL A1");
	((Panel*)objetoPanel1)->setPanelColorRGBA(250, 0, 6, 250);

	GameObject* objetoPanel11 = new Panel(TextureManager::getInstancia()->getRenderer(), 1632, 4, 54,40, "PANEL A11");
	((Panel*)objetoPanel11)->setPanelColorRGBA(0,0, 0, 250);

	GameObject* objetoPanel111 = new Panel(TextureManager::getInstancia()->getRenderer(), 1632, 50, 54, 15, "PANEL A111");
	((Panel*)objetoPanel111)->setPanelColorRGBA(0, 0, 0, 250);

	//Horizontal
	GameObject* objetoPanel2 = new Panel(TextureManager::getInstancia()->getRenderer(), 3, 528, 130, 43, "PANEL B");
	((Panel*)objetoPanel2)->setPanelColorRGBA(12, 258, 22, 253);

	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel1);

	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel2);

	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel11);

	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel111);

	/*((GUIComposite*)contenedorPaneles)->add(550, 500, 100, 50, "PANEL B", 10, 255, 24, 255, true);
	((GUIComposite*)contenedorPaneles)->add(570, 75, 50, 50, "BUTTON A", 0, 5, 65, 255, true);
	vectorObjetosJuego.push_back(contenedorPaneles);
	GameObject* objetoPanel = new Panel(TextureManager::getInstancia()->getRenderer(), 620, 50, 150, 300, "BUTTON A");
	((Panel*)objetoPanel)->setPanelColorRGBA(250, 180, 35, 250);*/
	vectorObjetosJuego.push_back(contenedorPaneles);
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