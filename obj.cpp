#include "obj.h"
#include "raytracer.h"
#include <cmath>
#include <utility>
using namespace std;

Obj::Obj() {
	vert1 = Punto(0, 0, 0);
	vert2 = Punto(-1, -1, -1);
	vert3 = Punto(-1, 1, -1);
	kd = 0.7;
	ks = 0.2;
	ka = 0.1;
	od = Vect(1, 0, 1);
	os = Vect(-1, -1, -1);
	kgls = 16;
}

double Obj::getkd() {
	return kd;
}

double Obj::getks() {
	return ks;
}

double Obj::getka() {
	return ka;
}

Vect Obj::getod() {
	return od;
}

Vect Obj::getos() {
	return os;
}

double Obj::getkgls() {
	return kgls;
}

bool Obj::intersect(Rayo r) {
	return false;
}

bool Obj::intersect2(Rayo r) {
	return true;
}

Rayo Obj::intersectray(Rayo r) {
	return Rayo();
}