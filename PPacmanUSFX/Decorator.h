#pragma once
#include "Fantasma.h"
class Decorator:
	public Fantasma
{
protected:
	Fantasma* widFantasma;

public:
	Decorator(Fantasma* wF);
	void update();

};

