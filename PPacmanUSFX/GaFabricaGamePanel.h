#pragma once
#include "GamePanel.h"
//#include "GaPanelConcretoTipe2.h"
#include "GaPanelConcretoTipe1.h"


class GaFabricaGamePanel
{
protected:
	static GamePanel* TipoTexto1;

	static GamePanel* TipoTexto2;



public:
	static void  Inicializar() {

		TipoTexto1 = new GaPanelConcretoTipe1(new Texture(), 10, 540);
		TipoTexto2 = new GaPanelConcretoTipe1(new Texture(), 50, 540);

	};

	static GamePanel* getObjetoTipoTexto1(); 
	static GamePanel* getObjetoTipoTexto2(); 


};

