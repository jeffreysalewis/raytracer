#include "vect.h"

Vect::Vect(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

double Vect::getx() {
	return x;
}

double Vect::gety() {
	return y;
}

double Vect::getz() {
	return z;
}

Vect Vect::getvect() {
	return *this;
}

double Vect::dot(Vect other) {
	return x * other.getx() + y * other.gety() + z * other.getz();
}

Vect Vect::cross(Vect other) {
	double d = other.getx();
	double e = other.gety();
	double f = other.getz();
	return Vect(y*f - z*e, z*d - x*f, x*e - y*d);
}