#pragma once
#include "GamePanel.h"
#include "GaPanelConcretoTipe2.h"
#include "GaPanelConcretoTipe1.h"


class GaFabricaGamePanel
{
protected:
	static GamePanel* TipoTexto1;
	static GamePanel* TipoTexto2;



public:
	static void  Inicializar() {

		TipoTexto1 = new GaPanelConcretoTipe1(0,0,0);
		TipoTexto2 = new GaPanelConcretoTipe1(0,0,0);

	};

	static GamePanel* getObjetoTipoTexto1() { return TipoTexto1->Clonar(); }
	static GamePanel* getObjetoTipoTexto2() { return TipoTexto2->Clonar(); }


};

