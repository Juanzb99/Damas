#include "Tabuleiro.h"

using namespace std;


void Tabuleiro::drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 100; //Numero de triangulos usados para dibujar un circulo

	GLfloat twicePi = 2.0f * M_PI;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // Centro del circulo
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

void Tabuleiro::cell2center(int cell_x, int cell_y, float& glx, float& gly) {
	glx = cell_y * ancho + ancho / 2.0f;
	gly = -cell_x * ancho - ancho / 2.0f;
	//Centro de la celda
}

void Tabuleiro::world2cell(double x, double y, int& cell_x, int& cell_y) {
	//Coordinacion entre mundo y celda
	cell_x = (int)(abs(y / ancho));
	cell_y = (int)(x / ancho);
}

//Dibuja la malla donde va el tablero
void Tabuleiro::DibujaMalla() {
	float dist = ancho;
	glColor3ub(0, 0, 0);
	float marco = numero * ancho;
	for (int i = 0; i <= numero; i++) {
		if (i % numero == 0) glLineWidth(4);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(i * ancho, 0, 0);
		glVertex3f(i * ancho, -marco, 0);
		glVertex3f(0, -i * ancho, 0);
		glVertex3f(marco, -i * ancho, 0);
		glEnd();
	}

}

//Dibuja las fichas en sus celdas
void Tabuleiro::DibujaEnCelda(tablero& t,int x, int y) { 
	float glx, gly;

	cas_t pos = t.tab[x][y]->square();
		int i = pos.x, j = pos.y;

		switch (t.tab[x][y]->type())
		{
		case (ficha::PEON_BLANCO):
			cell2center(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			glColor3ub(255, 255, 255);
			glTranslatef(glx, gly, 0.001);
			drawFilledCircle(0.0f, 0.0f, (ancho / 2.0f) * 0.9f);
			glTranslatef(-glx, -gly, -0.001);
			glEnable(GL_LIGHTING);

			break;

		case (ficha::PEON_NEGRO):
			cell2center(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			glColor3ub(0, 0, 0);
			glTranslatef(glx, gly, 0.001);
			drawFilledCircle(0.0f, 0.0f, (ancho / 2.0f) * 0.9f);
			glTranslatef(-glx, -gly, -0.001);
			glEnable(GL_LIGHTING);
			break;
		case (ficha::DAMA_NEGRA):
			cell2center(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			glColor3ub(0, 0, 0);
			glTranslatef(glx, gly, 0.001);
			drawFilledCircle(0.0f, 0.0f, (ancho / 2.0f) * 0.9f);
			glTranslatef(-glx, -gly, -0.001);
			glTranslatef(glx, gly, 0.0011);
			glColor3ub(236, 198, 7);
			drawFilledCircle(0.0f, 0.0f, (ancho / 6.0f) * 0.9f);
			glTranslatef(-glx, -gly, -0.0011);
			glEnable(GL_LIGHTING);
			break;

		case (ficha::DAMA_BLANCA):
			cell2center(i, j, glx, gly);
			glDisable(GL_LIGHTING);
			glColor3ub(255, 255, 255);
			glTranslatef(glx, gly, 0.001);
			drawFilledCircle(0.0f, 0.0f, (ancho / 2.0f) * 0.9f);
			glTranslatef(-glx, -gly, -0.001);
			glTranslatef(glx, gly, 0.0011);
			glColor3ub(236, 198, 7);
			drawFilledCircle(0.0f, 0.0f, (ancho / 6.0f) * 0.9f);
			glTranslatef(-glx, -gly,-0.0011);
			glEnable(GL_LIGHTING);
			break;
		default:

			break;
		}

}

//Funcion principal de dibujo
void Tabuleiro::Dibuja(tablero& t) {
	float center_x = numero * ancho / 2;
	float center_y = -numero * ancho / 2;
	float center_z = 0;
	int c = 1;
	float dist = ancho;

	//Borrado de la pantalla
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(center_x, center_y, t.dist, center_x, center_y, center_z, 0, 1, 0);
	glEnable(GL_LIGHTING);

	DibujaMalla();
	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)

			if (t.tab[i][j] != NULL)
				DibujaEnCelda(t,i,j);
	}
	
	for (int i = 0; i < numero; i++)
	{
		c = i % 2;
		for (int j = 0; j < numero; j++)
		{
			
			if (c == 0)
			{
				glColor3ub(250, 250, 250);//Casillas blancas 
				c = 1;
			}
			else
			{
				glColor3ub(255, 4, 67);//Casillas de color
				c = 0;
			}
			glDisable(GL_LIGHTING);

			glTranslatef(i * dist, -j * dist, 0);
			glBegin(GL_POLYGON);
			glVertex2f(0, 0);
			glVertex2f(dist, 0);
			glVertex2f(dist, -dist);
			glVertex2f(0, -dist);
			glEnd();
			glTranslatef(-i * dist, +j * dist, 0);
			glEnable(GL_LIGHTING);
		
		}

	}

}


void Tabuleiro::BotonMouse(int x, int y, int button, bool down) {
	////////////////////////////////////////////////////
	//computes cell coordinates from mouse coordinates//

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	world2cell(posX, posY, xcell_sel, ycell_sel);

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	if (down) {
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;
	}
}
