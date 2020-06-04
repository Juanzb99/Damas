#include "Tablero.h"

ostream& operator <<(ostream& o, const ficha& ob) { return ob.print(o); }

tablero& tablero::operator +=(const ficha& f) {

	//remove the object which occupies the square 
	cas_t c = f.square();
	if (tab[c.x][c.y] != NULL) {
		delete tab[c.x][c.y];
		tab[c.x][c.y] = NULL;
	}
	//create a new object copying the original one (uses explicit DOWNCAST)
	tab[c.x][c.y] = factory::create(f);
	nFichas++;
	return *this;
}

tablero& tablero::operator-=(const ficha& f)
{
	//remove the object which occupies the square 
	cas_t c = f.square();
	if (tab[c.x][c.y] != NULL) {
		delete tab[c.x][c.y];
		tab[c.x][c.y] = NULL;
		nFichas--;
	}
	return *this;
}

int tablero::number_of_pieces()
{
	nFichas = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tab[i][j] != NULL) { nFichas++; }
		}
	}

	return nFichas;
}

ostream& tablero::print(ostream& o) const
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tab[i][j] != NULL) {
				o << *tab[i][j];
			}
		}
	}
	return o;
}

void tablero::nulify()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tab[i][j] = NULL;
		}
	}
}

void tablero::Inicializa() {
	
	nulify();

	//fichas blancas
	for (int j = 1; j < n; j += 2) {
		tab[0][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 0,j });
		nFichas++;
	}
	for (int j = 0; j < n; j += 2) {
		tab[1][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 1,j });
		nFichas++;
	}
	for (int j = 1; j < n; j += 2) {
		tab[2][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 2,j });
		nFichas++;
	}
	//fichas negras
	for (int j = 0; j < n; j += 2) {
		tab[5][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 5,j });
		nFichas++;
	}
	for (int j = 1; j < n; j += 2) {
		tab[6][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 6,j });
		nFichas++;
	}
	for (int j = 0; j < n; j += 2) {
		tab[7][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 7,j });
		nFichas++;
	}

}

tablero::tablero() :nFichas(0)
{
	nulify();

	/////////////////////////
	//configuración inicial//

		//fichas blancas
	for (int j = 1; j < n; j += 2) {
		tab[0][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 0,j });
		nFichas++;
	}
	for (int j = 0; j < n; j += 2) {
		tab[1][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 1,j });
		nFichas++;
	}
	for (int j = 1; j < n; j += 2) {
		tab[2][j] = factory::create(ficha::PEON_BLANCO, cas_t{ 2,j });
		nFichas++;
	}

	//fichas negras
	for (int j = 0; j < n; j += 2) {
		tab[5][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 5,j });
		nFichas++;
	}
	for (int j = 1; j < n; j += 2) {
		tab[6][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 6,j });
		nFichas++;
	}
	for (int j = 0; j < n; j += 2) {
		tab[7][j] = factory::create(ficha::PEON_NEGRO, cas_t{ 7,j });
		nFichas++;
	}
}

tablero::~tablero() {
	////////////////////////////////////////////////////////////////////////////////////////////
	//Destructor que tiene las responsabilidad de eliminar los objetos creados por la factoría//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tab[i][j] != NULL) { delete tab[i][j]; }
		}
	}
}

tablero::tablero(const tablero& rhs) :nFichas(rhs.nFichas)
{
	nulify();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ficha* f = rhs.tab[i][j];
			if (f != NULL) {
				tab[i][j] = factory::create(*f);
			}
		}
	}
}

tablero& tablero::operator=(const tablero& rhs)
{

	if (this != &rhs) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ficha* f = rhs.tab[i][j];
				if (f != NULL) {
					tab[i][j] = factory::create(*f);
				}
				else {
					tab[i][j] = NULL;
				}
			}
		}
	}
	return *this;
}
