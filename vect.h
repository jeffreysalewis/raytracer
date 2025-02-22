#pragma once
#ifndef VECT_H
#define VECT_H


class Vect {
private:
	double x, y, z;
public:
	Vect(double a, double b, double c);
	Vect();
	double getx();
	double gety();
	double getz();
	Vect getvect();
	double getlen();
	void normalize();
	double dot(Vect other);
	Vect cross(Vect other);
	Vect multiply(double scalar);
	Vect multiply(Vect other);
};
#endif