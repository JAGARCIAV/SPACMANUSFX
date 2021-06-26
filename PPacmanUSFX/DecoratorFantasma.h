#pragma once
#include "Fantasma.h"
#include "Pacman.h"
#include "Moneda.h"
#include "Decorator.h"


class DecoratorFantasma:
	public Decorator
{
public:
	DecoratorFantasma(Fantasma *wF):Decorator(wF){}

	void update();
};

