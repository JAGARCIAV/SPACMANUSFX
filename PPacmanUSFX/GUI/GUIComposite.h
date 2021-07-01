#pragma once
#include <vector>
#include "../GUI/Component.h"


class GUIComposite :
    public Component
{
protected:
	vector<Component*> vectorComponentes;
public:
	// Constructores y destructores
	GUIComposite(SDL_Renderer* _renderer, string _nombre);
	// Metodos accesores

	// Metodos varios
	void add(Component*);
	void remove(Component*);

	// Metodos virtuales, redefinidos o sobrecargados
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event* event) {};
	virtual void deleteGameObject() { GameObject::deleteGameObject(); };
};

