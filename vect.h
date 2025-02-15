#pragma once
#ifndef VECT_H
#define VECT_H


class Vect {
private:
	double x, y, z;
public:
	Vect(double a, double b, double c);
	double getx();
	double gety();
	double getz();
	Vect getvect();
	void normalize();
	double dot(Vect other);
	Vect cross(Vect other);
};
#endif