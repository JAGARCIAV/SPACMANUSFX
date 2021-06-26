#include "FantasmasFactory.h"

Fantasma* FantasmasFactory::tipoClasicoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoClasicoClyde = nullptr;
Fantasma* FantasmasFactory::tipoClasicoInkey = nullptr;
Fantasma* FantasmasFactory::tipoClasicoPinky = nullptr;

Fantasma* FantasmasFactory::tipoGalacticoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoClyde = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoInkey = nullptr;
Fantasma* FantasmasFactory::tipoGalacticoPinky = nullptr;

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