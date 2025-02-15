#include "punto.h"

using namespace std;

Punto::Punto(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
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