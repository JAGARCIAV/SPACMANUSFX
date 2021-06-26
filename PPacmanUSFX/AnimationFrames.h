#pragma once
#include <vector>
#include <map>
#include <string>
#include <SDL.h>
#include "Texture.h"

using namespace std;

//AnimationFrames

class AnimationFrames
{	
private:
	map<string, vector<SDL_Rect*>> mapCuadrosAnimacion;
public:
	AnimationFrames() {};
	~AnimationFrames() {};

	vector<SDL_Rect*> getCuadrosAnimacion(string _key) { return mapCuadrosAnimacion[_key]; }

	void setCuadrosAnimacion(string _key, vector<SDL_Rect*> _vectorCuadrosAnimacion) {
		mapCuadrosAnimacion[_key] = _vectorCuadrosAnimacion;
	}
	void addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion);
};

