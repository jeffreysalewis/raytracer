#include "rayo.h"

using namespace std;

Rayo::Rayo(const Punto& o, const Vect& dir) {
	origin = o;
	direction = dir;
	hit = false;
}

Rayo::Rayo(const Vect& dir) {
	origin = Punto(0, 0, 1);
	direction = dir;
	hit = false;
}

Rayo::Rayo() {
	origin = Punto(0, 0, 1);
	direction = Vect(0, 0, -1);
	hit = false;
}

Punto Rayo::getorigin() {
	return origin;
}

Vect Rayo::getdirection() {
	return direction;
}

void Rayo::sethit(bool b) {
	hit = b;
}

bool Rayo::gethit() {
	return hit;
}

void Rayo::setcolor(double r, double g, double b) {
	color = Vect(r, g, b);
}

void Rayo::setshadow(double r, double g, double b) {
	shadow = Vect(r, g, b);
}

Vect Rayo::getcolor() {
	return color;
}

Vect Rayo::getshadow() {
	return shadow;
}