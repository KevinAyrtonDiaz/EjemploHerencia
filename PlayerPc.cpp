#include "PlayerPc.h"
#include <stdlib.h>

void PlayerPc::seleccionar()
{
	int opcion = rand() % 3 + 1;
	setJugada(opcion); // Corregido el nombre
}