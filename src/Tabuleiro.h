#define _USE_MATH_DEFINES
#define DEG2RAD M_PI/180.0
#define numero 8
#define ancho 0.15
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Tablero.h"
#include "glut.h"
#pragma once

class Tabuleiro {
private:
	//VAriables para el ratón
	int xcell_sel, ycell_sel;
	bool leftButton;
	bool rightButton;
	bool midButton;

	friend class Mundo;

protected:
	enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

public:
	
	void Dibuja(tablero&); 
	void DibujaEnCelda(tablero&, int, int); 
	void BotonMouse(int, int, int, bool); 
	void DibujaMalla();
	void drawFilledCircle(GLfloat, GLfloat, GLfloat);
	void cell2center(int, int, float&, float&);
	void world2cell(double, double, int&, int&);
};
