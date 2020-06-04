#include <iostream>
#include "Ficha.h"
#include "Vector2D.h"
#pragma once

using namespace std;

class tablero {
	friend class Engine;
public:
	static const int n = 8;
	static const int dist = 2; //DO NOT CHANGE
	int nFichas;
	ficha* tab[n][n];
private:
	void nulify();
public:
	////////////
	//forma canónica
	tablero();
	void Inicializa();
	virtual ~tablero();
	tablero(const tablero&);
	tablero& operator=	(const tablero&);
	/////////////

	tablero& operator +=(const ficha&);
	tablero& operator -=(const ficha&);

	int number_of_pieces();

	//I/O
	ostream& print(ostream& o = cout) const;
	ficha* getFichas() { return tab[n][n]; } 
};