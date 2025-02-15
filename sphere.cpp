#include "sphere.h"

Sphere::Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss) {
	center = c;
	radius = r;
	kd = dk;
	ks = sk;
	ka = ak;
	od = odd;
	os = so;
	kgls = kgloss;
}

Sphere::Sphere() {
	center = Punto(0, 0, 0);
	radius = 0.4;
	kd = 0.7;
	ks = 0.2;
	ka = 0.1;
	od = Vect(1, 0, 1);
	os = Vect(1, 1, 1);
	kgls = 16;
}

Punto Sphere::getcenter() {
	return center;
}

double Sphere::getradius() {
	return radius;
}

double Sphere::getkd() {
	return kd;
}

double Sphere::getks() {
	return ks;
}

double Sphere::getka() {
	return ka;
}

Vect Sphere::getod() {
	return od;
}

Vect Sphere::getos() {
	return os;
}

double Sphere::getkgls() {
	return kgls;
}

bool Sphere::intersect(Rayo r) {
	return true;
}