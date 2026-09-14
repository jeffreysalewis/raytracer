#include "rayo.h"

using namespace std;

Rayo::Rayo(const Punto& o, const Vect& dir) {
	origin = o;
	direction = dir;
	hit = false;
	reflect = 0;
	refract = 0;
	bounce = 0;
}

Rayo::Rayo(const Vect& dir) {
	origin = Punto(0, 0, 1);
	direction = dir;
	hit = false;
	reflect = 0;
	refract = 0;
	bounce = 0;
}

Rayo::Rayo() {
	origin = Punto(0, 0, 1);
	direction = Vect(0, 0, -1);
	hit = false;
	reflect = 0;
	refract = 0;
	bounce = 0;
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

void Rayo::setreflect(double r) {
	reflect = r;
}

void Rayo::setrefract(double r) {
	refract = r;
}

void Rayo::setbounce(int b) {
	bounce = b;
}

double Rayo::getreflect() {
	return reflect;
}

double Rayo::getrefract() {
	return refract;
}

int Rayo::getbounce() {
	return bounce;
}