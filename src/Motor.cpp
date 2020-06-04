#include "Motor.h"



int Engine::is_legal(move_t m, const tablero& t)
{
	//seguridad, comprobar dimensiones
	if ((m.dest.x < 0) || (m.dest.x > 7) || (m.dest.y < 0) || (m.dest.y > 7)) { return 0; }


	//A) origen tiene que ser una ficha
	ficha* fo = t.tab[m.ori.x][m.ori.y];

	if (fo == NULL) { cout << "is_legal FALSE NULL" << endl; return 0; }


	//B) el destino tiene que ser de ficha contraria si es que es una ficha
	ficha* fd = t.tab[m.dest.x][m.dest.y];

	if (fd) {
		if (fd->type() == ficha::PEON_NEGRO || fd->type() == ficha::DAMA_NEGRA) {
			if (fo->type() == ficha::PEON_NEGRO || fo->type() == ficha::DAMA_NEGRA) {
				cout << "is_legal FALSE" << endl; return 0;
			}
		}
		if (fd->type() == ficha::PEON_BLANCO || fd->type() == ficha::DAMA_BLANCA) {
			if (fo->type() == ficha::PEON_BLANCO || fo->type() == ficha::DAMA_BLANCA) { cout << "is_legal FALSE" << endl; return 0; }
		}
	}

	//C) Movimiento permitido simple (diagonal, arriba para las negras, abajo para las blancas)
	if (!fd) {
		switch (fo->type())
		{
		case(ficha::PEON_BLANCO)://está permitido que avance hacia abajo(sumarle 1 a la x)  
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		case(ficha::PEON_NEGRO)://está permitido que avance hacia arriba(resta 1 a la x)  
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		case(ficha::DAMA_NEGRA):
			if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		case(ficha::DAMA_BLANCA):
			if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		default:
			break;
		}
	}

	//D) Movimiento de comer, tiene que haber ficha en el destino y ya se ha comprobado que es de diferente color que fo
	if (fd) {
		ficha* fs; //ficha salto auxiliar
		switch (fo->type())
		{
		case(ficha::PEON_BLANCO)://está permitido que coma hacia abajo si la casilla diagonal está vacía 
			//distinguir si para la derecha o para la izquierda asegurando de que es para abajo
			//crear una ficha destino salto y preguntar si está vacío
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha
			{
				fs = t.tab[m.dest.x + 1][m.dest.y + 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el peon blanco come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda
			{
				fs = t.tab[m.dest.x + 1][m.dest.y - 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el peon blanco come" << endl;
					return 1;
				}
			}
			break;
		case(ficha::PEON_NEGRO)://está permitido que coma hacia arriba  
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha
			{
				fs = t.tab[m.dest.x - 1][m.dest.y + 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el peon negro come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda
			{
				fs = t.tab[m.dest.x - 1][m.dest.y - 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el peon negro come" << endl;
					return 1;
				}
			}
			break;
		case(ficha::DAMA_NEGRA):
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha inferior
			{
				fs = t.tab[m.dest.x + 1][m.dest.y + 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama negro come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
			{
				fs = t.tab[m.dest.x + 1][m.dest.y - 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama negro come" << endl;
					return 1;
				}
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
			{
				fs = t.tab[m.dest.x - 1][m.dest.y + 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama negro come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
			{
				fs = t.tab[m.dest.x - 1][m.dest.y - 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama negro come" << endl;
					return 1;
				}
			}
			break;
		case(ficha::DAMA_BLANCA):
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha inferior
			{
				fs = t.tab[m.dest.x + 1][m.dest.y + 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama blanco come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
			{
				fs = t.tab[m.dest.x + 1][m.dest.y - 1];

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama blanco come" << endl;
					return 1;
				}
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
			{
				fs = t.tab[m.dest.x - 1][m.dest.y + 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama blanco come" << endl;
					return 1;
				}
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
			{
				fs = t.tab[m.dest.x - 1][m.dest.y - 1];

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				if (!fs)
				{
					delete fs;
					cout << "el dama blanco come" << endl;
					return 1;
				}
			}
			break;
		default:
			break;
		}


	}

	return 0;
}

int Engine::move(move_t m, tablero& t)
{
	
	if (Engine::is_legal(m, t)!=0) {
		ficha* fo = t.tab[m.ori.x][m.ori.y];
		ficha* fd = t.tab[m.dest.x][m.dest.y];
		cas_t aux;
		if (fd) {
			switch (fo->type())
			{
			case(ficha::PEON_BLANCO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1))//diagonal derecha
				{
					aux = { m.dest.x + 1,m.dest.y + 1 };
					if (aux.x == 7)
					{
						t += db({ aux });
						t -= *fo;
						cout << "dama blanca se convierte" << endl;
					}
					else
					{
						t += pb({ aux });
						t -= *fo;
					}
				}
				if ((m.dest.y == m.ori.y - 1))//diagonal izquierda
				{
					aux = { m.dest.x + 1,m.dest.y - 1 };
					if (aux.x == 7)
					{
						t += db({ aux });
						t -= *fo;
						cout << "dama blanca se convierte" << endl;
					}
					else
					{
						t += pb({ aux });
						t -= *fo;
					}
				}
				break;
			case(ficha::PEON_NEGRO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1))//diagonal derecha
				{
					aux = { m.dest.x - 1,m.dest.y + 1 };
					if (aux.x == 0)
					{
						t += dn({ aux });
						t -= *fo;
						cout << "dama negra se convierte" << endl;
					}
					else
					{
						t += pn({ aux });
						t -= *fo;
					}
				}
				if ((m.dest.y == m.ori.y - 1))//diagonal izquierda
				{
					aux = { m.dest.x - 1,m.dest.y - 1 };
					if (aux.x == 0)
					{
						t += dn({ aux });
						t -= *fo;
						cout << "dama negra se convierte" << endl;
					}
					else
					{
						t += pn({ aux });
						t -= *fo;
					}
				}
				break;
			case(ficha::DAMA_BLANCA): //elegir diagonal para mover fo
				if ((m.dest.x == m.ori.x + 1)&&(m.dest.y == m.ori.y + 1))//diagonal derecha inferior
				{
					aux = { m.dest.x + 1,m.dest.y + 1 };
					t += db({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1)&&(m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
				{
					aux = { m.dest.x + 1,m.dest.y - 1 };
					t += db({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
				{
					aux = { m.dest.x - 1,m.dest.y + 1 };
					t += db({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
				{
					aux = { m.dest.x - 1,m.dest.y - 1 };
					t += db({ aux });
					t -= *fo;
				}
				break;
			case(ficha::DAMA_NEGRA): //elegir diagonal para mover fo
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha inferior
				{
					aux = { m.dest.x + 1,m.dest.y + 1 };
					t += dn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
				{
					aux = { m.dest.x + 1,m.dest.y - 1 };
					t += dn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
				{
					aux = { m.dest.x - 1,m.dest.y + 1 };
					t += dn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
				{
					aux = { m.dest.x - 1,m.dest.y - 1 };
					t += dn({ aux });
					t -= *fo;
				}
				break;
			default:
				break;
			}
			t.operator-=(*fd); //borramos la ficha comida
		}
		else
		{
			//move piece in original square
			fd = fo;
			switch (fd->type())
			{
			case(ficha::PEON_BLANCO):
				if (m.dest.x == 7)
				{
					t += db(m.dest);
					t -= *fd;
					cout << "dama blanca se convierte" << endl;
				}
				else
				{
					t -= *fo;
					t += pb({m.dest});
				}
				break;
			case(ficha::PEON_NEGRO):
				if (m.dest.x == 0)
				{
					t += dn(m.dest);
					t -= *fd;
					cout << "dama NEGRO se convierte" << endl;
				}
				else
				{
					t -= *fo;
					t += pn({ m.dest });
				}
				break;
			case(ficha::DAMA_BLANCA):
				t -= *fo;
				t += db({ m.dest });
				break;
			case(ficha::DAMA_NEGRA):
				t -= *fo;
				t += dn({ m.dest });
				break;
			default:
				break;
			}

		}

		return 0;

	}
	return -1;

}