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

		FantasmasFactory::initialize();

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Fantasma* objetoFantasmaClonado = nullptr;


			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'Y':
				objetoNuevo = factory->createFrutaInstance(tileNuevo, textureManager, x * 25, y * 25);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'W':
				objetoNuevo = factory->createParedInstance(tileNuevo, textureManager, x * Tile::altoTile, y * Tile::altoTile, false);
				objetoNuevo->setParametrosAnimacion(1);
				break;
			case '-':
				objetoNuevo = factory->createMonedaInstance(tileNuevo, textureManager, x * 25, y * 25);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'P':
				objetoNuevo = factory->createPacmanInstance(tileNuevo, textureManager, x * 25, y * 25, 5);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'J':
				//objetoNuevo = factory->createFantasma1Instance(tileNuevo, textureManager, x * 25, y * 25, 1);
				//objetoNuevo->setParametrosAnimacion(4);
				objetoNuevo = FantasmasFactory::getTipoClasicoBlinky();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, x * 25, y * 25, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'H':
				//objetoNuevo = factory->createFantasma2Instance(tileNuevo, textureManager, x * 25, y * 25, 2);
				//objetoNuevo->setParametrosAnimacion(4);
				objetoNuevo = FantasmasFactory::getTipoClasicoClyde();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, x * 25, y * 25, 2);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'I':
				//objetoNuevo = factory->createFantasma3Instance(tileNuevo, textureManager, x * 25, y * 25, 2);
				//objetoNuevo->setParametrosAnimacion(4);
				objetoNuevo = FantasmasFactory::getTipoClasicoInkey();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, x * 25, y * 25, 3);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'G':
				//objetoNuevo = factory->createFantasma4Instance(tileNuevo, textureManager, x * 25, y * 25, 3);
				//objetoNuevo->setParametrosAnimacion(4);
				objetoNuevo = FantasmasFactory::getTipoClasicoPinky();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, x * 25, y * 25, 4);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'C':
				objetoNuevo = factory->createSuperMonedaInstance(tileNuevo, textureManager, x * 25, y * 25);
				objetoNuevo->setParametrosAnimacion(9);
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


	////score Tff
	GaFabricaGamePanel::Inicializar();
	GamePanel* object;

	GameObject* objetoPanel = new GaPanelConcretoTipe1(new Texture(), 10, 540);
	vectorObjetosJuego.push_back(objetoPanel);



	//PATRON PROTOTYPE main score

	//GaFabricaGamePanel::Inicializar();
	//GamePanel* object;

	/* Todo el objeto fue creado clonando los prototipos.. */

	object = GaFabricaGamePanel::getObjetoTipoTexto1();
	cout << object->getTextoTipo() << " SCORE TIPO 1" <<endl;

	object = GaFabricaGamePanel::getObjetoTipoTexto2();
	cout << object->getTextoTipo() << " SCORE TIPO 2 " << endl;

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