#include "Ficha.h"



ficha* factory::create(ficha::obj_t t, cas_t c) {
	switch (t) {
	case ficha::PEON_NEGRO:
		return new pn(c);
	case ficha::PEON_BLANCO:
		return new pb(c);
	case ficha::DAMA_NEGRA:
		return new dn(c);
	case ficha::DAMA_BLANCA:
		return new db(c);
	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;
}
ficha* factory::create(const ficha& f)
{
	switch (f.type()) {
	case ficha::PEON_NEGRO:
		return new pn(dynamic_cast<const pn&>(f));
	case ficha::PEON_BLANCO:
		return new pb(dynamic_cast<const pb&>(f));
	case ficha::DAMA_NEGRA:
		return new dn(dynamic_cast<const dn&>(f));
	case ficha::DAMA_BLANCA:
		return new db(dynamic_cast<const db&>(f));
	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;

}

