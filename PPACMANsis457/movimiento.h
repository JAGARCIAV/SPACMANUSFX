#pragma once

//movimiento con teclas
#define TECLA_ARRIBA	'w'
#define TECLA_ABAJO		's'	
#define TECLA_ABAJO		'a'	
#define TECLA_ABAJO		'd'	


//Direccion de pacman
enum DireccionMovimiento {
	MOVER_ARRIBA,
	MOVER_ABAJO,
	MOVER_IZQUIERDA,
	MOVER_DERECHA,
	MOVER_SIN_MOVIMIENTO,
};