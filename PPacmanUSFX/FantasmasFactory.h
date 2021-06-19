#pragma once
#include "FantasmaClasico.h"
#include "FantasmaGalactico.h"
#include "FantasmaAsesino.h"

#include "TextureManager.h" 

class FantasmasFactory
{
private:
	//CLASICO
	static Fantasma* tipoClasicoBlinky;
	static Fantasma* tipoClasicoClyde;
	static Fantasma* tipoClasicoInkey;
	static Fantasma* tipoClasicoPinky;

	//GALACTICO
	static Fantasma* tipoGalacticoBlinky;
	static Fantasma* tipoGalacticoClyde;
	static Fantasma* tipoGalacticoInkey;
	static Fantasma* tipoGalacticoPinky;

	//ASESINO
	static Fantasma* tipoAsesinoBlinky;
	static Fantasma* tipoAsesinoClyde;
	static Fantasma* tipoAsesinoInkey;
	static Fantasma* tipoAsesinoPinky;

public:
	static void  initialize()
	{
		//CLASICO
		tipoClasicoBlinky = new FantasmaClasico(nullptr, (new TextureManager())->getTexture("fantasma_clasico1"), 50, 50, 10);
		tipoClasicoClyde = new FantasmaClasico(nullptr, (new TextureManager())->getTexture("fantasma_clasico2"), 50, 50, 10);
		tipoClasicoInkey = new FantasmaClasico(nullptr, (new TextureManager())->getTexture("fantasma_clasico3"), 50, 50, 10);
		tipoClasicoPinky = new FantasmaClasico(nullptr, (new TextureManager())->getTexture("fantasma_clasico4"), 50, 50, 10);

		//GALACTICO
		tipoGalacticoBlinky = new FantasmaGalactico(nullptr, (new TextureManager())->getTexture("fantasma_galactico1"), 50, 50, 10);
		tipoGalacticoClyde = new FantasmaGalactico(nullptr, (new TextureManager())->getTexture("fantasma_galactico2"), 50, 50, 10);
		tipoGalacticoInkey = new FantasmaGalactico(nullptr, (new TextureManager())->getTexture("fantasma_galactico3"), 50, 50, 10);
		tipoGalacticoPinky = new FantasmaGalactico(nullptr, (new TextureManager())->getTexture("fantasma_galactico4"), 50, 50, 10);

		//ASESINO
		tipoAsesinoBlinky = new FantasmaAsesino(nullptr, (new TextureManager())->getTexture("fantasma_galactico1"), 50, 50, 10);
		tipoAsesinoClyde = new FantasmaAsesino(nullptr, (new TextureManager())->getTexture("fantasma_galactico2"), 50, 50, 10);
		tipoAsesinoInkey = new FantasmaAsesino(nullptr, (new TextureManager())->getTexture("fantasma_galactico3"), 50, 50, 10);
		tipoAsesinoPinky = new FantasmaAsesino(nullptr, (new TextureManager())->getTexture("fantasma_galactico4"), 50, 50, 10);
	}

	//CLASICO
	static Fantasma* getTipoClasicoBlinky();
	static Fantasma* getTipoClasicoClyde();
	static Fantasma* getTipoClasicoInkey();
	static Fantasma* getTipoClasicoPinky();

	//GALACTICO
	static Fantasma* getTipoGalacticoBlinky();
	static Fantasma* getTipoGalacticoClyde();
	static Fantasma* getTipoGalacticoInkey();
	static Fantasma* getTipoGalacticoPinky();

	//ASESINO
	static Fantasma* getTipoAsesinoBlinky();
	static Fantasma* getTipoAsesinoClyde();
	static Fantasma* getTipoAsesinoInkey();
	static Fantasma* getTipoAsesinoPinky();

};



