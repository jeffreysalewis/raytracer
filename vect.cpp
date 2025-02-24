#include "vect.h"
#include <cmath>

using namespace std;

Vect::Vect(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

Vect::Vect() {
	x = 0;
	y = 0;
	z = 0;
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

double Vect::getlen() {
	return sqrt(x * x + y * y + z * z);
}

void Vect::normalize() {
	double len = this->getlen();
	x = x / len;
	y = y / len;
	z = z / len;
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

Vect Vect::multiply(double scalar) {
	double newx = x * scalar;
	double newy = y * scalar;
	double newz = z * scalar;
	return Vect(newx, newy, newz);
}

Vect Vect::multiply(Vect other) {
	double newx = x * other.getx();
	double newy = y * other.gety();
	double newz = z * other.getz();
	return Vect(newx, newy, newz);
}

Vect Vect::add(Vect other) {
	double newx = x + other.getx();
	double newy = y + other.gety();
	double newz = z + other.getz();
	return Vect(newx, newy, newz);
}

Vect Vect::sub(Vect other) {
	double newx = x - other.getx();
	double newy = y - other.gety();
	double newz = z - other.getz();
	return Vect(newx, newy, newz);
}