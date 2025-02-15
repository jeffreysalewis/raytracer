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