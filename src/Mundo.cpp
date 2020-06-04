#include "Mundo.h"

Mundo::Mundo() {}
Mundo::~Mundo() {}

void Mundo::Inicializa() {

	tab.Inicializa();

}

void Mundo::Dibuja() {	
	
	tabuleiro.Dibuja(tab);
	DibujaCasilla(origen_n);
	DibujaCasilla(origen_b);

}

void Mundo::DibujaCasilla(cas_t& c)  //cada casilla mide 0.15 y el origen está en el 0,0
{
	if (c.x != 0 || c.y != 0)
	{
		glDisable(GL_LIGHTING);
		glColor3ub(125, 0, 0);
		glTranslatef(0.15 * c.y, -0.15 * c.x, 0.0001);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.15, 0);
		glVertex2f(0.15, -0.15);
		glVertex2f(0, -0.15);
		glEnd();
		glTranslatef(-0.15 * c.y, 0.15 * c.x, -0.0001);
		glEnable(GL_LIGHTING);
	}
	

}

void Mundo::Tecla(unsigned char key) {

}

void Mundo::Raton(int x, int y, int b, bool state, char t) {
	
	///////////////////////////////////////////////////////////////////////////
	//captures clicks with mouse with or without special keys (CTRL or SHIFT)//
	//gives control to board scene...........................................//

	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {
		
		button = tabuleiro.MOUSE_LEFT_BUTTON;
		clic++;


		if ((tabuleiro.xcell_sel<=7)&& (tabuleiro.xcell_sel >= 0)&& (tabuleiro.ycell_sel <=7)&& (tabuleiro.ycell_sel >=0))
		{
			if (tab.tab[tabuleiro.xcell_sel][tabuleiro.ycell_sel] && clic == 2)
			{

				cout << "HAS SETEADO EL ORIGEN CRUCK" << endl;
				switch (tab.tab[tabuleiro.xcell_sel][tabuleiro.ycell_sel]->type())
				{
				case(ficha::DAMA_NEGRA):
					origen_n.x = tabuleiro.xcell_sel;
					origen_n.y = tabuleiro.ycell_sel;
					break;
				case(ficha::PEON_NEGRO):
					origen_n.x = tabuleiro.xcell_sel;
					origen_n.y = tabuleiro.ycell_sel;
					break;
				case(ficha::DAMA_BLANCA):
					origen_b.x = tabuleiro.xcell_sel;
					origen_b.y = tabuleiro.ycell_sel;
					break;
				case(ficha::PEON_BLANCO):
					origen_b.x = tabuleiro.xcell_sel;
					origen_b.y = tabuleiro.ycell_sel;
					break;
				}

			}

			if (clic == 4)
			{
				if (tab.tab[origen_n.x][origen_n.y]) //se deja por si se setea un destino sin haber puesto antes un origen //como cada vez que se pasa de turno el origen y el destino de las fichas se pone a 0,0
				{
					destino_n.x = tabuleiro.xcell_sel;
					destino_n.y = tabuleiro.ycell_sel;
					clic = 0;
				}

				if (tab.tab[origen_b.x][origen_b.y]) //es muy importante que ponga a 0,0 de en cada turno para que funcione bien
				{
					destino_b.x = tabuleiro.xcell_sel;
					destino_b.y = tabuleiro.ycell_sel;
					clic = 0;
				}
				cout << "HAS SETEADO EL DESTNO CRUCK" << endl;
			}

			cout << "clic: " << clic << endl;
			if (clic > 5)clic = 0;

		}
	}
	if (b == GLUT_RIGHT_BUTTON) {

		button = tabuleiro.MOUSE_RIGHT_BUTTON;
		
	}

	tabuleiro.BotonMouse(x, y, b, down);

}

int Mundo::MovimientoMaquina(char clase_turno) {
	int aux;
	move_t mov = maquina.blancaMueve(tab);

	//experimental//
	//mantener el turno para cuando ha comido y puede comer

	if (clase_turno == 's')
	{
		switch (mov.tipo)
		{
		case(2):								 //si el movimiento es de tipo simple es valido
			motor.move(mov, tab);
			return 1;
			break;
		case(1):								//si el movimiento es de tipo comer, es valido y comienzo la cadena
			motor.move(mov, tab);
			return 2;							//vuelvo al mi turno para continuar con la cadena
			break;
		default:
			break;
		}
		if (mov.ori.x == -1) {
			cout << "Movimiento no Válido BLOQUEO" << endl;
			return 3;
		}
	}


	if (clase_turno=='c')
	{
		switch (mov.tipo)
		{
		case(2):								//si el movimiento es de tipo simple no es valido porque vengo de comer, se rompe la cadena
			return 1;
			break;
		case(1):								//si el movimiento es de tipo comer es valido porque sigue la cadena de comer
			motor.move(mov, tab);
			return 2;							//vuelvo al mi turno para continuar con la cadena
			break;
		default:
			break;
		}
		if (mov.ori.x == -1) {
			cout << "Movimiento no Válido BLOQUEO" << endl;
			return 3;
		}
	}

}

void Mundo::setMov(cas_t ori, cas_t dest)
{
	origen_n = ori;
	origen_b = ori;
	destino_n=dest;
	destino_b = dest;
}

int Mundo::MovimientoHumano(char t, char clase_turno) 
{
	int aux;
	
	if (t == 'N')
	{
		if (clase_turno == 's')
		{

			move_t mov = maquina.negraMueve(tab);

			switch (mov.tipo)
			{
			case(2):								 //si el movimiento es de tipo simple no tengo obligacion de comer porque no puedo comer
				aux = motor.move({ origen_n, destino_n }, tab);
				if (aux == -1)return 4;				//vuelvo a mi turno porque el movimiento no es valido
				else return 1;
				cout << "no puedes comer" << endl;
				break;
			case(1):								//si el movimiento es de tipo comer tengo obligación de comer
				if (motor.is_legal({ origen_n, destino_n }, tab) == 1)
				{
					motor.move({ origen_n, destino_n }, tab);
					return 2;						//vuelvo a mi turno porque el movimiento es de tipo comer
				}
				else return 4;
				break;
			default:
				break;
			}

			if (mov.ori.x == -1) {
				cout << "Movimiento no Válido BLOQUEO" << endl;
				return 3;
			}


		}
		if (clase_turno == 'c')
		{

			move_t mov = maquina.negraMueve(tab);

			switch (mov.tipo)
			{
			case(2):								 //si el movimiento es de tipo simple no tengo obligacion de comer porque no puedo comer asique se rompe la cadena
				return 1;
				break;
			case(1):								//si el movimiento es de tipo comer tengo obligación de comer
				
				if (motor.is_legal({ origen_n, destino_n }, tab) == 1)
				{
					motor.move({ origen_n, destino_n }, tab);
					return 2;						//vuelvo a mi turno porque el movimiento es de tipo comer
				}
				else return 4;
				break;
			default:
				break;
			}

			if (mov.ori.x == -1) {
				cout << "Movimiento no Válido BLOQUEO" << endl;
				return 3;
			}


		}
	}
	
	if (t == 'B')
	{
		if (clase_turno == 's')
		{

			move_t mov = maquina.blancaMueve(tab);

			switch (mov.tipo)
			{
			case(2):							 //si el movimiento es de tipo simple no tengo obligacion de comer porque no puedo comer
				aux = motor.move({ origen_b, destino_b }, tab);
				if (aux == -1)return 4;			//vuelvo a mi turno porque el movimiento no es valido
				else return 1;
				cout << "no puedes comer" << endl;
				break;
			case(1):							//si el movimiento es de tipo comer tengo obligación de comer
				if (motor.is_legal({ origen_b, destino_b }, tab) == 1)
				{
					motor.move({ origen_b, destino_b }, tab);
					return 2;					//vuelvo a mi turno porque el movimiento es de tipo comer
				}
				else return 4;
				break;
			default:
				break;
			}

			if (mov.ori.x == -1) {
				cout << "Movimiento no Válido BLOQUEO" << endl;
				return 3;
			}


		}
		if (clase_turno == 'c')
		{

			move_t mov = maquina.blancaMueve(tab);

			switch (mov.tipo)
			{
			case(2):								 //si el movimiento es de tipo simple no tengo obligacion de comer porque no puedo comer asique se rompe la cadena
				return 1;
				break;
			case(1):								//si el movimiento es de tipo comer tengo obligación de comer

				if (motor.is_legal({ origen_b, destino_b }, tab) == 1)
				{
					motor.move({ origen_b, destino_b }, tab);
					return 2;						//vuelvo a mi turno porque el movimiento es de tipo comer
				}
				else return 4;
				break;
			default:
				break;
			}

			if (mov.ori.x == -1) {
				cout << "Movimiento no Válido BLOQUEO" << endl;
				return 3;
			}


		}
	}
}
