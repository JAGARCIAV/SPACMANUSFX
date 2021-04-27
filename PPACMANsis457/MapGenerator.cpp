#include "MapGenerator.h"

MapGenerator::MapGenerator(Texture* _texture, int _anchoPantalla, int _altoPantalla, int _numeroFrame, int  _contadorFrames)
{
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared);
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
			GameObject* newObject = nullptr;

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				newObject = new Pared(paredTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, _numeroFrame, _contadorFrames);
			


				//newObject = new Wall(tile, pTextureManager->Get("wall"));
				break;

			case '.':
				newObject = new Moneda(monedaTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, _numeroFrame, _contadorFrames);
				break;
			case '0':
				newObject = new Moneda(superMonedaTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, _numeroFrame, _contadorFrames);
				break;

				//pacman
			case 'p':
				newObject = new Pacman(pacmanTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5, _numeroFrame, _contadorFrames);
				break;
				//fantasmas
			case 'b':
				//newObject = new Fantasma(fantasma1Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3, _numeroFrame, _contadorFrames);
				break;
			case 'f':
				//newObject = new Fantasma(fantasma2Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3, _numeroFrame, _contadorFrames);
				break;
			case 'g':
				//newObject = new Fantasma(fantasma3Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3, _numeroFrame, _contadorFrames);
				break;
			case 'h':
				//newObject = new Fantasma(fantasma4Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3, _numeroFrame, _contadorFrames);
				break;
			}

			// If the object was created, add it to the vector
			if (newObject != NULL)
				vectorObjetosJuego.push_back(newObject);
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}
}