#include <iostream>
#include "Vector2D.h"
#include "Tablero.h"
#pragma once

//////////////////

class Engine {
public:
	static int is_legal(move_t m, const tablero& t);
	static int move(move_t m, tablero& t);
};
