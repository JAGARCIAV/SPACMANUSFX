#pragma once
#include "../GameObject.h"
#include <iostream>
#include <string>
using namespace std;

class Component :
    public GameObject
{
protected:
	SDL_Renderer* renderer;
public:
	Component() {};
	Component(SDL_Renderer* _renderer, string _nombre);	
	virtual void add(Component*) {}
	virtual void remove(Component*) {}

	virtual void render() {};
	virtual void update() {};
	virtual void handleEvent(SDL_Event* event) {};
	virtual void deleteGameObject() { GameObject::deleteGameObject(); };
};

