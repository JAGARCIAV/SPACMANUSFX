#include "FantasmasFactory.h"

//CLASICO
Fantasma* FantasmasFactory::tipoClasicoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoClasicoClyde = nullptr;
Fantasma* FantasmasFactory::tipoClasicoInkey = nullptr;
Fantasma* FantasmasFactory::tipoClasicoPinky = nullptr;

//GALACTICO
Fantasma* FantasmasFactory::tipoGalacticoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoClyde = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoInkey = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoPinky = nullptr;

//ASESINO
Fantasma* FantasmasFactory::tipoAsesinoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoAsesinoClyde = nullptr;
Fantasma* FantasmasFactory::tipoAsesinoInkey = nullptr;
Fantasma* FantasmasFactory::tipoAsesinoPinky = nullptr;

//CLASICOS
Fantasma* FantasmasFactory::getTipoClasicoBlinky()
{
	return tipoClasicoBlinky->clone();
}

Fantasma* FantasmasFactory::getTipoClasicoClyde()
{
	return tipoClasicoClyde->clone();
}

Fantasma* FantasmasFactory::getTipoClasicoInkey()
{
	return tipoClasicoInkey->clone();
}

Fantasma* FantasmasFactory::getTipoClasicoPinky()
{
	return tipoClasicoPinky->clone();
}

//GALACTICO
Fantasma* FantasmasFactory::getTipoGalacticoBlinky()
{
	return tipoGalacticoBlinky->clone();
}

Fantasma* FantasmasFactory::getTipoGalacticoClyde()
{
	return tipoGalacticoClyde->clone();
}

Fantasma* FantasmasFactory::getTipoGalacticoInkey()
{
	return tipoGalacticoInkey->clone();
}

Fantasma* FantasmasFactory::getTipoGalacticoPinky()
{
	return tipoGalacticoPinky->clone();
}

//ASESINO
Fantasma* FantasmasFactory::getTipoAsesinoBlinky()
{
	return tipoAsesinoBlinky->clone();
}

Fantasma* FantasmasFactory::getTipoAsesinoClyde()
{
	return tipoAsesinoClyde->clone();
}

Fantasma* FantasmasFactory::getTipoAsesinoInkey()
{
	return tipoAsesinoInkey->clone();
}

Fantasma* FantasmasFactory::getTipoAsesinoPinky()
{
	return tipoAsesinoPinky->clone();
}