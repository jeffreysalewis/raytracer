#include "rayo.h"

using namespace std;

Rayo::Rayo(const Punto& o, const Vect& dir) {
	origin = o;
	direction = dir;
}

Rayo::Rayo(const Vect& dir) {
	origin = Punto(0, 0, 1);
	direction = dir;
}

Rayo::Rayo() {
	origin = Punto(0, 0, 1);
	direction = Vect(0, 0, 0);
}

Punto Rayo::getorigin() {
	return origin;
}

Vect Rayo::getdirection() {
	return direction;
}