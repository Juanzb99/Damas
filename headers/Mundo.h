#include "Tabuleiro.h"
#include "Motor.h"
#include "Ficha.h"
#include "Tablero.h"
#include "Maquina.h"
#pragma once

class Mundo
{
private:
	int clic = 0;
	bool turno;

	cas_t origen_b = {0,0};
	cas_t destino_b = { 0,0 };
	cas_t destino_n = { 0,0 };
	cas_t origen_n = { 0,0 };
	tablero tab;
	Tabuleiro tabuleiro;
	Engine motor;
	ficha ficha;
	Maquina maquina;
public:
	Mundo();
	virtual ~Mundo();

	void Inicializa();
	void Dibuja();
	void DibujaCasilla(cas_t& c);
	void Tecla(unsigned char key);
	void Raton(int, int, int, bool, char t);
	int MovimientoHumano(char t, char clase_turno);
	int MovimientoMaquina(char clase_turno);
	void setMov(cas_t ori, cas_t dest);

};

