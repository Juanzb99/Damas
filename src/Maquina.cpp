#include "Maquina.h"


move_t Maquina::blancaMueve(tablero t)
{
	//primero busca una ficha blanca
	//despues segun si es un peón o una dama pregunta por sus movimentos haciendo uso del is_legal

	ficha* fp;
	move_t aux;
	move_t bloqueado = { -1,-1,-1,-1 };	//movimiento que se devuelve si la máquina ha perdido porque ya no puede mover
	////////////////////////////////////////////////////////////////
	//se pregunta por el movimiento de comer ya que es prioritario//
	for (int i = 0; i < t.n; i++) {
		for (int j = 0; j < t.n; j++) {
			fp = t.tab[i][j];
			if (fp) {
				if (fp->type() == ficha::PEON_BLANCO) //preguntar por los movimientos que pueden hacer los peones blanos
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t) == 1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha si el de la izquierda no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
				}

				if (fp->type() == ficha::DAMA_BLANCA) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
				}

			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////
	//se pregunta por el movimiento de mover una vez comprobado que no se puede comer//
	for (int i = 0; i < t.n; i++) {
		for (int j = 0; j < t.n; j++) {
			fp = t.tab[i][j];
			if (fp) {
				if (fp->type() == ficha::PEON_BLANCO) //preguntar por los movimientos que pueden hacer los peones blanos
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha si el de la izquierda no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
				}

				if (fp->type() == ficha::DAMA_BLANCA) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
				}

			}
		}
	}

	return bloqueado;
}

move_t Maquina::negraMueve(tablero t)
{
	//primero busca una ficha negra
	//despues segun si es un peon o una dama pregunta por sus movimentos haciendo uso del is_legal

	ficha* fp;
	move_t aux;
	move_t bloqueado = { -1,-1,-1,-1 };	//movimiento que se devuelve si la máquina ha perdido porque ya no puede mover
	////////////////////////////////////////////////////////////////
	//se pregunta por el movimiento de comer ya que es prioritario//
	for (int i = 0; i < t.n; i++) {
		for (int j = 0; j < t.n; j++) {
			fp = t.tab[i][j];
			if (fp) {
				if (fp->type() == ficha::PEON_NEGRO) //preguntar por los movimientos que pueden hacer los peones negros
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda
					aux.dest.x = aux.ori.x - 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t) == 1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha si el de la izquierda no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
				}

				if (fp->type() == ficha::DAMA_NEGRA) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==1) { aux.tipo = 1; return aux; }
				}

			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////
	//se pregunta por el movimiento de mover una vez comprobado que no se puede comer//
	for (int i = 0; i < t.n; i++) {
		for (int j = 0; j < t.n; j++) {
			fp = t.tab[i][j];
			if (fp) {
				if (fp->type() == ficha::PEON_NEGRO) //preguntar por los movimientos que pueden hacer los peones negros
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda
					aux.dest.x = aux.ori.x - 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha si el de la izquierda no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
				}

				if (fp->type() == ficha::DAMA_NEGRA) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Engine::is_legal(aux, t)==2) { aux.tipo = 2; return aux; }
				}

			}
		}
	}
	return bloqueado;
}