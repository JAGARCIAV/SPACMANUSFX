#include "GaFabricaGamePanel.h"

GamePanel* GaFabricaGamePanel::TipoTexto1 = 0;
GamePanel* GaFabricaGamePanel::TipoTexto2 = 0;


GamePanel* GaFabricaGamePanel::getObjetoTipoTexto1()
{
	return TipoTexto1->Clonar();
}

GamePanel* GaFabricaGamePanel::getObjetoTipoTexto2()
{
	return TipoTexto2->Clonar();
}