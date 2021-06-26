#include "Decorator.h"
Decorator::Decorator(Fantasma* wF) :
	Fantasma(*wF) {
	widFantasma = wF;
}

void Decorator::update() {
	widFantasma->update();
}