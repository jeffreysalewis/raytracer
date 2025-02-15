#include "rayo.h"

using namespace std;

Rayo::Rayo(const Punto& o, const Vect& dir) {
	origin = o;
	direction = dir;
}

double Vect::getx() {
	return x;
}

double Vect::gety() {
	return y;
}