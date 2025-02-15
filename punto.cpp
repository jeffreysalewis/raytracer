#include "punto.h"

using namespace std;

Punto::Punto(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

Punto::Punto() {
	x = 0;
	y = 0;
	z = 0;
}

double Punto::getx() {
	return x;
}

double Punto::gety() {
	return y;
}

double Punto::getz() {
	return z;
}