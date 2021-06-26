#pragma once
#include "FantasmaClasico.h"
#include "FantasmaGalactico.h"
#include "TextureManager.h" 

class FantasmasFactory
{
private:
	static Fantasma* tipoClasicoBlinky;
	static Fantasma* tipoClasicoClyde;
	static Fantasma* tipoClasicoInkey;
	static Fantasma* tipoClasicoPinky;

	static Fantasma* tipoGalacticoBlinky;
	static Fantasma* tipoGalacticoClyde;
	static Fantasma* tipoGalacticoInkey;
	static Fantasma* tipoGalacticoPinky;

public:
	static void  initialize()
	{
		tipoClasicoBlinky = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico1"), 0, 0, 10);
		tipoClasicoClyde = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico2"), 0, 0, 10);
		tipoClasicoInkey = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico3"), 0, 0, 10);
		tipoClasicoPinky = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico4"), 0, 0, 10);
		tipoGalacticoBlinky = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico1"), 0, 0, 10);
		tipoGalacticoClyde = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico2"), 0, 0, 10);
		tipoGalacticoInkey = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico3"), 0, 0, 10);
		tipoGalacticoPinky = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico4"), 0, 0, 10);
	}

	static Fantasma* getTipoClasicoBlinky();
	static Fantasma* getTipoClasicoClyde();
	static Fantasma* getTipoClasicoInkey();
	static Fantasma* getTipoClasicoPinky();
	static Fantasma* getTipoGalacticoBlinky();
	static Fantasma* getTipoGalacticoClyde();
	static Fantasma* getTipoGalacticoInkey();
	static Fantasma* getTipoGalacticoPinky();

};



