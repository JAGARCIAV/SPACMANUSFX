#include "FantasmasFactory.h"

//VERSION CLASICO
Fantasma* FantasmasFactory::tipoFantasmaClasico1 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaClasico2 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaClasico3 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaClasico4 = nullptr;

//VERSION GALACTICO
Fantasma* FantasmasFactory::tipoFantasmaGalactico1 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaGalactico2 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaGalactico3 = nullptr;
Fantasma* FantasmasFactory::tipoFantasmaGalactico4 = nullptr;

//VERSION CLASICO
Fantasma* FantasmasFactory::getTipoFantasmaClasico1()
{
	return tipoFantasmaClasico1->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaClasico2()
{
	return tipoFantasmaClasico2->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaClasico3()
{
	return tipoFantasmaClasico3->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaClasico4()
{
	return tipoFantasmaClasico4->clone();
}


//VERSION GALACTICO
Fantasma* FantasmasFactory::getTipoFantasmaGalactico1()
{
	return tipoFantasmaGalactico1->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaGalactico2()
{
	return tipoFantasmaGalactico2->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaGalactico3()
{
	return tipoFantasmaGalactico3->clone();
}

Fantasma* FantasmasFactory::getTipoFantasmaGalactico4()
{
	return tipoFantasmaGalactico4->clone();
}