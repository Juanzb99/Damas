#include "Coordinador.h"
#include "ETSIDI.h"
#include "glut.h"

Coordinador::Coordinador() {

	estado = INICIO;

}

Coordinador::~Coordinador() {

}

void Coordinador::Inicializa() {
	mundo.Inicializa();
}

void Coordinador::Raton(int x, int y, int b, bool state) {

	if (turno == JUGADOR_B)
	{
		mundo.Raton(x, y, b, state, 'b');
	}
	if (turno == JUGADOR_N)
	{
		mundo.Raton(x, y, b, state, 'n');
	}

}


void Coordinador::Dibuja() {

	if (estado == INICIO) {
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 0);
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 100);
		ETSIDI::printxy("LAS DAMAS", -12, 10);
		ETSIDI::setTextColor(0.8, 0.8, 0.8);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE -1- PARA SINGLEPLAYER", -10, 7);
		ETSIDI::printxy("PULSE -2- PARA MULTIPLAYER", -10, 5);
		ETSIDI::printxy("PULSE -S- PARA SALIR", -10, 3);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 15);
		ETSIDI::printxy("MOSTROS S.A.", 5, -1);
	}

	else if (estado == SOLO) {
		mundo.Dibuja();
			glDisable(GL_LIGHTING);
			glColor3ub(81, 90, 90);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
	}

	else if (estado == MULTI) {
		mundo.Dibuja();
		if (turno == JUGADOR_B) {
			glDisable(GL_LIGHTING);
			glColor3ub(153, 163, 164);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
		}
		if (turno == JUGADOR_N) {
			glDisable(GL_LIGHTING);
			glColor3ub(81, 90, 90);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
		}
	}

	else if (estado == TABLAS) {
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 50);
		ETSIDI::printxy("EL JUEGO HA TERMINADO EN TABLAS", -13.5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE  -S- PARA VOLVER A INICIO", -10, 5);
		ETSIDI::printxy("MOSTROS S.A.", 2, 0);
	}

	else if (estado == GANA_B) {
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 50);
		ETSIDI::printxy("HAN GANADO LAS BLANCAS", -14, 8);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE -S- PARA VOLVER A INICIO", -10, 5);
		ETSIDI::printxy("MOSTROS S.A.", 5, -1);
	}

	else if (estado == GANA_N) {
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 50);
		ETSIDI::printxy("HAN GANADO LAS NEGRAS", -14, 8);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE -S- PARA VOLVER A INICIO", -10, 5);
		ETSIDI::printxy("MOSTROS S.A.", 5, -1);
	}

	else if (estado == PAUSASOLO) {
		glDisable(GL_LIGHTING);
		glColor3ub(81, 90, 90);
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 50);
		ETSIDI::printxy("PAUSA", -3, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE -C- PARA CONTINUAR", -10, 7);
		ETSIDI::printxy("PULSE -I- PARA VOLVER A INICIO", -10, 5);
		ETSIDI::printxy("MOSTROS S.A.", 5, -1);
	}

	else if (estado == PAUSAMULTI) {
		glDisable(GL_LIGHTING);
		glColor3ub(81, 90, 90);
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 50);
		ETSIDI::printxy("PAUSA", -3, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/SIXTY.ttf", 30);
		ETSIDI::printxy("PULSE -C- PARA CONTINUAR", -10, 7);
		ETSIDI::printxy("PULSE -I- PARA VOLVER A INICIO", -10, 5);
		ETSIDI::printxy("MOSTROS S.A.", 5, -1);
	}


}

void Coordinador::Tecla(unsigned char key) {

	if (estado == INICIO) {
		if (key == '1') { Inicializa(); estado = SOLO; turno = JUGADOR_B; }
		else if (key == '2') { Inicializa(); estado = MULTI; turno = JUGADOR_B; }
		else if (key == 'S' || key == 's') { exit(0); }
	}

	else if (estado == GANA_B|| estado == GANA_N|| estado == TABLAS) {
		if (key == 's' || key == 'S') { estado = INICIO; }
	}

	else if (estado == SOLO) {
		if (key == 'P' || key == 'p') { estado = PAUSASOLO; }
	}

	else if (estado == MULTI) {
		if (key == 'P' || key == 'p') { estado = PAUSAMULTI; }
	}

	else if (estado == PAUSASOLO) {
		if (key == 'C' || key == 'c') { estado = SOLO; }
		else if (key == 'I' || key == 'i') { estado = INICIO; }
	}

	else if (estado == PAUSAMULTI) {
		if (key == 'C' || key == 'c') { estado = MULTI; }
		else if (key == 'I' || key == 'i') { estado = INICIO; }
	}
}

void Coordinador::TurnoSolo() {

	if (estado == SOLO) {
		if (turno == JUGADOR_N)
		{
			if (cadena == false)
			{
				int aux;
				aux = mundo.MovimientoHumano('N', 's'); //turno simple (sin cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_b)
					{
						estado = GANA_N;
						bloqueo_n = false;
						bloqueo_b = false;
					}

					turno = JUGADOR_B;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2: //si me mete en 2 es porque viene de comer
					cadena = true;
					turno = JUGADOR_N;
					break;
				case 3:
					bloqueo_n = true;
					if (bloqueo_b)
					{
						estado = TABLAS;						
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_B;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
				case 4://si me mete en 4 es porque viene de que el movimiento no ha sido valido
					turno = JUGADOR_N;
					break;
				}
			}

			if (cadena == true)
			{
				int aux;
				aux = mundo.MovimientoHumano('N', 'c'); //turno comer (con cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_b)
					{
						estado = GANA_N;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					cadena = false;
					turno = JUGADOR_B;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2:
					cadena = true;
					turno = JUGADOR_N;
					break;
				case 3:
					bloqueo_n = true;
					if (bloqueo_b)
					{
						estado = TABLAS;
						cadena = false;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_B;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
					break;
				case 4:
					turno = JUGADOR_N;
					break;
				}
			}

		}
		else if (turno == JUGADOR_B)
		{
			if (cadena==false)
			{
				int aux;
				aux = mundo.MovimientoMaquina('s'); //turno simple (sin cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_n)
					{
						estado = GANA_B;
						bloqueo_n = false;
						bloqueo_b = false;
					}

					turno = JUGADOR_N;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2:		//si es 2 es porque he comido
					cadena = true;
					turno = JUGADOR_B;
					break;
				case 3:
					bloqueo_b = true;
					if (bloqueo_n)
					{
						estado = TABLAS;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_N;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
					break;
				}
			}

			if (cadena == true)
			{
				int aux;
				aux = mundo.MovimientoMaquina('c'); //turno comer (con cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_n)
					{
						estado = GANA_B;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					cadena = false;
					turno = JUGADOR_N;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2:
					cadena = true;
					turno = JUGADOR_B;
					break;
				case 3:
					bloqueo_b = true;
					if (bloqueo_n)
					{
						estado = TABLAS;
						cadena = false;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_N;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
					break;
				}
			}
		
		}
	}
}

void Coordinador::TurnoMulti()
{
	if (estado == MULTI)
	{
		if (turno == JUGADOR_N)
		{
			if (cadena == false)
			{
				int aux;
				aux = mundo.MovimientoHumano('N', 's'); //turno simple (sin cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_b)
					{
						estado = GANA_N;
						bloqueo_n = false;
						bloqueo_b = false;
					}

					turno = JUGADOR_B;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2: //si me mete en 2 es porque viene de comer
					cadena = true;
					turno = JUGADOR_N;
					break;
				case 3:
					bloqueo_n = true;
					if (bloqueo_b)
					{
						estado = TABLAS;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_B;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
				case 4://si me mete en 4 es porque viene de que el movimiento no ha sido valido
					turno = JUGADOR_N;
					break;
				}
			}

			if (cadena == true)
			{
				int aux;
				aux = mundo.MovimientoHumano('N', 'c'); //turno comer (con cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_b)
					{
						estado = GANA_N;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					cadena = false;
					turno = JUGADOR_B;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2:
					cadena = true;
					turno = JUGADOR_N;
					break;
				case 3:
					bloqueo_n = true;
					if (bloqueo_b)
					{
						estado = TABLAS;
						cadena = false;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_B;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
					break;
				case 4:
					turno = JUGADOR_N;
					break;
				}
			}

		}

		if (turno == JUGADOR_B)
		{
			if (cadena == false)
			{
				int aux;
				aux = mundo.MovimientoHumano('B', 's'); //turno simple (sin cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_n)
					{
						estado = GANA_B;
						bloqueo_n = false;
						bloqueo_b = false;
					}

					turno = JUGADOR_N;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2: //si me mete en 2 es porque viene de comer
					cadena = true;
					turno = JUGADOR_B;
					break;
				case 3:
					bloqueo_n = true;
					if (bloqueo_b)
					{
						estado = TABLAS;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_N;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
				case 4://si me mete en 4 es porque viene de que el movimiento no ha sido valido
					turno = JUGADOR_B;
					break;
				}
			}

			if (cadena == true)
			{
				int aux;
				aux = mundo.MovimientoHumano('B', 'c'); //turno comer (con cadena)

				switch (aux)
				{
				case 1:
					if (bloqueo_n)
					{
						estado = GANA_B;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					cadena = false;
					turno = JUGADOR_N;
					mundo.setMov({ 0,0 }, { 0,0 });
					break;
				case 2:
					cadena = true;
					turno = JUGADOR_B;
					break;
				case 3:
					bloqueo_b = true;
					if (bloqueo_n)
					{
						estado = TABLAS;
						cadena = false;
						bloqueo_n = false;
						bloqueo_b = false;
					}
					else
					{
						turno = JUGADOR_N;
						mundo.setMov({ 0,0 }, { 0,0 });
					}
					break;
				case 4:
					turno = JUGADOR_B;
					break;
				}
			}

		}
	}
}
