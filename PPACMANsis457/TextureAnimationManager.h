#pragma once
#include<map>
#include "Texture.h"
#include <vector>
#include <map>
#include <string>
#include <SDL.h>
#include "Texture.h"

using namespace std;
class TextureAnimationManager
{
private:
		map<string, Texture*> mapTexturas;
		Texture* texturaAnimacion;
		map<string, vector<SDL_Rect*>> mapCuadrosAnimacion;

		const string pathPacman = "Resources/AurelioSol.png";
		const string pathFantasma1 = "Resources/AZULG.png";
		const string pathFantasma2 = "Resources/VERDEG.png";
		const string pathFantasma3 = "Resources/NARANJAG.png";
		const string pathFantasma4 = "Resources/PLOMOG.png";
		const string pathFruta = "Resources/Frutas.png";
		const string pathMoneda = "Resources/Monedas.png";
		const string pathSuperMoneda = "Resources/SuperMoneda.png";
		const string pathPared = "Resources/Muro.png";

		Texture* pacmanTexture;


		Texture* fantasma1Texture;
		Texture* fantasma2Texture;
		Texture* fantasma3Texture;
		Texture* fantasma4Texture;
		Texture* frutaTexture;
		Texture* monedaTexture;
		Texture* superMonedaTexture;
		Texture* paredTexture;
	public:
		TextureAnimationManager();
		~TextureAnimationManager();


		Texture* getTexture() { return texturaAnimacion; }
		vector<SDL_Rect*> getCuadrosAnimacion(string _key) { return mapCuadrosAnimacion[_key]; }

		Texture* getTexture(string _key) { return mapTexturas[_key]; }
		void addTexture(string _key, Texture* _texture);
		void free();

		void setTexture(Texture* _textura) { texturaAnimacion = _textura; }
		void setCuadrosAnimacion(string _key, vector<SDL_Rect*> _vectorCuadrosAnimacion) {
			mapCuadrosAnimacion[_key] = _vectorCuadrosAnimacion;
		}
		void addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion);
};
