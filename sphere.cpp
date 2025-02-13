#include "sphere.h"

Sphere::Sphere(double c[], double r, double dk, double sk, double ak, double odd[], double so[], double kgloss) {
	center = c;
	radius = r;
	kd = dk;
	ks = sk;
	ka = ak;
	od = odd;
	os = so;
	kgls = kgloss;
}

double* Sphere::getcenter() {
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

double* Sphere::getod() {
	return od;
}

double* Sphere::getos() {
	return os;
}

double Sphere::getkgls() {
	return kgls;
}