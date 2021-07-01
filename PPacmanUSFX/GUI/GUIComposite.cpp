#include "GUIComposite.h"

GUIComposite::GUIComposite(SDL_Renderer* _renderer, string _nombre)
{
	renderer = renderer;
	nombre = _nombre;
}

void GUIComposite::add(Component* _component)
{
	vectorComponentes.push_back(_component);
}

void GUIComposite::remove(Component* _component)
{
	/*vectorComponentes.erase((std::remove(vectorComponentes.begin(), vectorComponentes.end(), _gameObject), vectorComponentes.end());
	auto ivectorComponentes = vectorComponentes.begin();
	vectorComponentes.erase(ivectorComponentes.begin(), ivectorComponentes.end());*/
}

void GUIComposite::render()
{
	for (Component* component: vectorComponentes) {
		component->render();
	}
}

void GUIComposite::update()
{
	for (Component* component : vectorComponentes) {
		component->update();
	}
}
