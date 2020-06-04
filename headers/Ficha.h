#include <iostream>
#include "Vector2D.h"
#pragma once

using namespace std;

class ficha {
public:
	enum obj_t { FICHA = 0, PEON_NEGRO, PEON_BLANCO, DAMA_NEGRA, DAMA_BLANCA };
public:
	cas_t cas;
	obj_t rtt;
	ficha(obj_t t = FICHA, cas_t c = { -1, -1 }) :rtt(t), cas(c) {}
public:
	virtual ~ficha() {};
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
	void setCas(cas_t dest) { cas = dest; }
	//I/O
	virtual ostream& print(ostream& o = cout) const { o << "ficha en" << endl; cas.print(o); return o; }
};



class pn : public ficha {
public:
	pn(cas_t c) :ficha(PEON_NEGRO, c) {}
	ostream& print(ostream& o = cout) const { o << "peon negro en "; cas.print(o); return o; }
};

class pb : public ficha {
public:
	pb(cas_t c) :ficha(PEON_BLANCO, c) {}
	ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class dn : public ficha {
public:
	dn(cas_t c) :ficha(DAMA_NEGRA, c) {}
	ostream& print(ostream& o = cout) const { o << "dama negra en "; cas.print(o); return o; }
};

class db : public ficha {
public:
	db(cas_t c) :ficha(DAMA_BLANCA, c) {}
	ostream& print(ostream& o = cout) const { o << "dama blanca en "; cas.print(o); return o; }
};

/////////
//factoría- (fabrica de objetos)
class factory {
public:
	static ficha* create(ficha::obj_t, cas_t);		//equivalent to normal constructor
	static ficha* create(const ficha&);				//equivalent to copy constructor
};
