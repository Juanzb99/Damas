#include "Coordinador.h"
#include "glut.h"

Coordinador coordinador;

void OnDraw(void);											//Esta funcion sera llamada para dibujar
void OnKeyboardDown(unsigned char key, int x, int y);		//Esta funcion sera llamada cuando se pulse una tecla	
void OnMouseClick(int button, int state, int x, int y);		//Esta funcion sera llamada cuando se pulse el a,raton
void OnTimer(int value);									//Esta funcion sera llamada cuando transcurra una temporizacion

int main(int argc, char* argv[]) {
	//GL Initialization stuff
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("LasDamas");

	//sets light and perspective
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Register callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//Le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	coordinador.Inicializa();

	//glut takes control
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner aqui el código de dibujo
	coordinador.Dibuja();
	
	
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Poner aqui el código de teclado
	coordinador.Tecla(key);

	glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y) {

	//Poner aqui el código de ratón
	coordinador.Raton(x, y, b, state);
	

	coordinador.TurnoMulti();
	glutPostRedisplay();
}

void OnTimer(int value) {

	coordinador.TurnoSolo();
	//No borrar estas lineas
	glutTimerFunc(100, OnTimer, 0); //ser configura 100ms para poder apreciar el movimiento de la maquina
	glutPostRedisplay();

}
