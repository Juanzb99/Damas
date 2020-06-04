#pragma once
#include <iostream>
#include "Tablero.h"
#include "Motor.h"

using namespace std;

//la clase máquina permite crear un jugador para el modo humano contra maquina
//cuenta con un método que recorre el tablero preguntando a las fichas por todos los moviminetos que podrían hacer y devuelve el primer movimiento legal que encuentra

class Maquina
{
public:
	friend class tablero;
	
	move_t blancaMueve(tablero t);
	move_t negraMueve(tablero t);
};

