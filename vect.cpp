#include "vect.h"
#include <cmath>

using namespace std;

Vect::Vect(double a, double b, double c) {
	double normalize = sqrt(a * a + b * b + c * c);
	x = a / normalize;
	y = b / normalize;
	z = c / normalize;
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