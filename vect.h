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
	double dot(Vect other);
	double cross(Vect other);
};
#endif