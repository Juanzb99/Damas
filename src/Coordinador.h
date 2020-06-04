#include "Mundo.h"
#pragma once

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();


	void Inicializa();
	void Tecla(unsigned char key);
	void Dibuja();
	void Raton(int, int, int, bool);
	void TurnoSolo();
	void TurnoMulti();


protected:
	Mundo mundo;

	enum Estado { INICIO, GANA_B, GANA_N, TABLAS, SOLO, MULTI, PAUSASOLO, PAUSAMULTI };
	enum Turno { JUGADOR_B, JUGADOR_N};
	Estado estado;
	Turno turno;
	bool bloqueo_n = false;
	bool bloqueo_b = false;
	bool cadena = false; //la cadena se construye al comer y se rompe (:=false) cuando no se puede comer mas
};

