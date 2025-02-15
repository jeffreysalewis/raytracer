#include "rayo.h"

using namespace std;

Rayo::Rayo(const Punto& o, const Vect& dir) {
	origin = o;
	direction = dir;
}

Punto Rayo::getorigin() {
	return origin;
}

Vect Rayo::getdirection() {
	return direction;
}