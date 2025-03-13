#include "triangle.h"
#include "raytracer.h"
#include <cmath>
#include <utility>
using namespace std;

Triangle::Triangle(Punto v1, Punto v2, Punto v3, double dk, double sk, double ak, Vect odd, Vect so, double kgloss, double ref) {
	vert1 = v1;
	vert2 = v2;
	vert3 = v3;
	normal = v2.minus(v1).cross(v3.minus(v1));
	kd = dk;
	ks = sk;
	ka = ak;
	od = odd;
	os = so;
	kgls = kgloss;
	refl = ref;
}

Triangle::Triangle() {
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

Punto Triangle::getvert1() {
	return vert1;
}

Punto Triangle::getvert2() {
	return vert2;
}

Punto Triangle::getvert3() {
	return vert3;
}

Vect Triangle::getnormal() {
	return normal;
}

double Triangle::getkd() {
	return kd;
}

double Triangle::getks() {
	return ks;
}

double Triangle::getka() {
	return ka;
}

Vect Triangle::getod() {
	return od;
}

Vect Triangle::getos() {
	return os;
}

double Triangle::getkgls() {
	return kgls;
}

bool Triangle::intersect(Rayo r) {
	return false;
}

bool Triangle::intersect2(Rayo r) {
	return false;
}

Rayo Triangle::intersectray(Rayo r) {
	return Rayo();
}