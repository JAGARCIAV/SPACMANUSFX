#pragma once
#include "FantasmaClasico.h"
#include "FantasmaGalactico.h"
#include "TextureManager.h" 

class FantasmasFactory
{
private:
	static Fantasma* tipoFantasmaClasico1;
	static Fantasma* tipoFantasmaClasico2;
	static Fantasma* tipoFantasmaClasico3;
	static Fantasma* tipoFantasmaClasico4;

	static Fantasma* tipoFantasmaGalactico1;
	static Fantasma* tipoFantasmaGalactico2;
	static Fantasma* tipoFantasmaGalactico3;
	static Fantasma* tipoFantasmaGalactico4;

public:
	static void  initialize()
	{
		tipoFantasmaClasico1 = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico1"));
		tipoFantasmaClasico2 = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico2"));
		tipoFantasmaClasico3 = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico3"));
		tipoFantasmaClasico4 = new FantasmaClasico(nullptr, (new TextureManager())->getTextura("fantasma_clasico4"));
		
		tipoFantasmaGalactico1 = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico1"));
		tipoFantasmaGalactico2 = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico2"));
		tipoFantasmaGalactico3 = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico3"));
		tipoFantasmaGalactico4 = new FantasmaGalactico(nullptr, (new TextureManager())->getTextura("fantasma_galactico4"));
	}

	static Fantasma* getTipoFantasmaClasico1();
	static Fantasma* getTipoFantasmaClasico2();
	static Fantasma* getTipoFantasmaClasico3();
	static Fantasma* getTipoFantasmaClasico4();

	static Fantasma* getTipoFantasmaGalactico1();
	static Fantasma* getTipoFantasmaGalactico2();
	static Fantasma* getTipoFantasmaGalactico3();
	static Fantasma* getTipoFantasmaGalactico4();

};



